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

  void SceneManager::update(float deltaTime) const {
    if (this->currentScene != nullptr) {
      this->currentScene->update(deltaTime);
      this->currentScene->layers->update(deltaTime);
    }
  }

  void SceneManager::handleMouseMove(int x, int y) const {
    if (this->currentScene != nullptr) {
      this->currentScene->onMouseMove(x, y);
      this->currentScene->layers->handleMouseMove(x, y);
    }
  }

  void SceneManager::handleKeyUp(SDL_Keycode key) const {
    if (this->currentScene != nullptr) {
      this->currentScene->onKeyUp(key);
      this->currentScene->layers->handleKeyUp(key);
    }
  }

  void SceneManager::handleKeyDown(SDL_Keycode key) const {
    if (this->currentScene != nullptr) {
      this->currentScene->onKeyDown(key);
      this->currentScene->layers->handleKeyDown(key);
    }
  }

  void SceneManager::handleKeyPress(const Uint8* currentKeystate) const {
    if (this->currentScene != nullptr) {
      this->currentScene->onKeyPress(currentKeystate);
      this->currentScene->layers->handleKeyPress(currentKeystate);
    }
  }


}