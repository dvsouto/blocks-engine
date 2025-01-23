#pragma once

#include <iostream>
#include <typeindex>

namespace Graphics {
  class Scene;
}

namespace Core {
  class SceneManager {
    static SceneManager* instance;

    SceneManager();

    void unloadScenes() const;
    void loadScene(Graphics::Scene* scene) const;

    public:
      std::unordered_map<std::type_index, std::shared_ptr<Graphics::Scene>> scenes;
      Graphics::Scene* currentScene = nullptr;

      static SceneManager* getInstance();

      void initialize() const;

      template<typename T, typename... Args>
      void addScene(Args&&... args);

      template<typename T>
      void setCurrentScene();

      void renderCurrentScene() const;
      void update(float deltaTime) const;
  };
}

namespace Core {
  template<typename T, typename... Args>
  void SceneManager::addScene(Args&&... args) {
    auto itScene = std::make_shared<T>(std::forward<Args>(args)...);
    auto itSceneIdx = std::type_index(typeid(T));

    this->scenes.insert(std::make_pair(itSceneIdx, itScene));

    this->unloadScenes();

    this->currentScene = itScene.get();
    this->loadScene(this->currentScene);
  }

  template<typename T>
  void SceneManager::setCurrentScene() {
    auto itSceneIdx = std::type_index(typeid(T));
    auto itScene = this->scenes.find(itSceneIdx);

    if (itScene == this->scenes.end()) {
      currentScene = itScene->second.get();

      this->loadScene(this->currentScene);

      return;
    }

    currentScene = nullptr;

  }
}