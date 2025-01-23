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

}