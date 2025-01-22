#include "include/core/SceneManager.h"
#include "include/graphics/Scene.h"

#include <iostream>

namespace Core {
  SceneManager* SceneManager::instance = nullptr;

  SceneManager::SceneManager() : currentScene(nullptr) {}

  SceneManager* SceneManager::getInstance() {
    if (instance == nullptr) {
      instance = new SceneManager();
    }

    return instance;
  }

  void SceneManager::initialize() const {}

  void SceneManager::addScene(std::shared_ptr<Graphics::Scene> scene, bool current) {
    scenes.push_back(scene);

    if (current) {
      this->unloadScenes();

      this->currentScene = scene.get();
      this->loadScene(this->currentScene);
    }
  }

  void SceneManager::unloadScenes() const {
    for (auto scene : scenes) {
      scene->unload();
    }
  }

  void SceneManager::loadScene(Graphics::Scene *scene) const {
    scene->init();
    scene->load();
  }

  void SceneManager::renderCurrentScene() const {
    if (this->currentScene != nullptr) {
      this->currentScene->render();
    }
  }
}