#pragma once

#include <iostream>

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
      std::vector<std::shared_ptr<Graphics::Scene>> scenes;
      Graphics::Scene* currentScene = nullptr;

      static SceneManager* getInstance();

      void initialize() const;
      void addScene(std::shared_ptr<Graphics::Scene> scene, bool current = true);
      void setCurrentScene(Graphics::Scene* scene);
      void renderCurrentScene() const;
  };
}