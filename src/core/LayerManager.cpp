#include "include/core/LayerManager.h"
#include "include/graphics/Layer.h"

#include <iostream>

namespace Core {
  LayerManager* LayerManager::instance = nullptr;

  LayerManager::LayerManager() {}

  LayerManager* LayerManager::getInstance() {
    if (instance == nullptr) {
      instance = new LayerManager();
    }

    return instance;
  }

  void LayerManager::initialize(){}

  void LayerManager::addLayer(std::shared_ptr<Graphics::Layer> layer) {
    layers.push_back(layer);
  }

  void LayerManager::renderLayers(){
    for(std::shared_ptr<Graphics::Layer> layer : this->layers){
      if (! layer->isVisible()) {
        continue;
      }

      layer->render();
    }
  }
}