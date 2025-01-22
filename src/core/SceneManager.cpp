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



  void SceneManager::unloadScenes() const {
    for (auto& scenePair : scenes) {
      auto& itScene = scenePair.second;

      itScene->unload();
    }
  }

  void SceneManager::loadScene(Graphics::Scene *scene) const {
    if (! scene->isLoaded()) {
      scene->init();
      scene->load();
    }
  }

  void SceneManager::renderCurrentScene() const {
    if (this->currentScene != nullptr) {
      this->currentScene->render();
    }
  }
}