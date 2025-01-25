#include "include/core/LayerManager.h"
#include "include/graphics/Layer.h"

#include <iostream>

namespace Core {
  void LayerManager::initialize(){}

  void LayerManager::renderLayers() const {
    for(const auto& layerPair : this->layers){
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->render();
    }
  }

  void LayerManager::update(float deltaTime) const {
    // std::cout<<"LayerManager::update"<<std::endl;

    for(const auto& layerPair : this->layers) {
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->update(deltaTime);
    }
  }

  void LayerManager::handleKeyDown(SDL_Keycode key) const {
    for(const auto& layerPair : this->layers) {
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->handleKeyDown(key);
      itLayer->onKeyDown(key);
    }
  }

  void LayerManager::handleKeyUp(SDL_Keycode key) const {
    for(const auto& layerPair : this->layers) {
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->handleKeyUp(key);
      itLayer->onKeyUp(key);
    }
  }

  void LayerManager::handleKeyPress(const Uint8* currentKeystate) const {
    for(const auto& layerPair : this->layers) {
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->handleKeyPress(currentKeystate);
      itLayer->onKeyPress(currentKeystate);
    }
  }

  void LayerManager::handleMouseMove(int x, int y) const {
    for(const auto& layerPair : this->layers) {
      auto& itLayer = layerPair.second;

      if (! itLayer->isVisible()) {
        continue;
      }

      itLayer->handleMouseMove(x, y);
      itLayer->onMouseMove(x, y);
    }
  }


}