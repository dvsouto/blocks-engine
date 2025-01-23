#pragma once

#include <include/graphics/Layer.h>

#include <iostream>
#include <typeindex>

namespace Graphics {
  class Layer;
}

namespace Core {
  class LayerManager {
  public:
    LayerManager() = default;
    LayerManager& operator=(const LayerManager&) = default;

    std::unordered_map<std::type_index, std::shared_ptr<Graphics::Layer>> layers;

    // static LayerManager* getInstance();
    void initialize();

    template<typename T>
    void addLayer(std::shared_ptr<T> layer);

    template<typename T>
    std::shared_ptr<T> getLayer();

    void renderLayers() const;
    void update(float deltaTime) const;
  };
}

namespace Core {
  template<typename T>
  void LayerManager::addLayer(std::shared_ptr<T> layer) {
    auto itLayerIdx = std::type_index(typeid(T));

    this->layers.insert(std::make_pair(itLayerIdx, layer));
  }

  template<typename T>
  std::shared_ptr<T> LayerManager::getLayer() {
    auto it = this->layers.find(typeid(T));

    if (it != this->layers.end()) {
      return std::static_pointer_cast<T>(it->second);
    }

    return nullptr;
  }
}