#pragma once

#include <include/graphics/Layer.h>

#include <SDL2/SDL_keycode.h>
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
    void add(std::shared_ptr<T> layer);

    template<typename T, typename... Args>
    std::shared_ptr<T> create(Args&&... args);

    template<typename T>
    std::shared_ptr<T> use();

    void renderLayers() const;
    void update(float deltaTime) const;

    void handleKeyDown(SDL_Keycode key) const;
    void handleKeyUp(SDL_Keycode key) const;
    void handleKeyPress(const Uint8* currentKeystate) const;
    void handleMouseMove(int x, int y) const;
  };
}

namespace Core {
  template<typename T>
  void LayerManager::add(std::shared_ptr<T> layer) {
    auto itLayerIdx = std::type_index(typeid(T));

    this->layers.insert(std::make_pair(itLayerIdx, layer));
  }

  template<typename T, typename... Args>
  std::shared_ptr<T> LayerManager::create(Args&&... args) {
    auto itLayer = std::make_shared<T>(std::forward<Args>(args)...);
    auto itLayerIdx = std::type_index(typeid(T));

    this->layers.insert(std::make_pair(itLayerIdx, itLayer));

    return itLayer;
  }

  template<typename T>
  std::shared_ptr<T> LayerManager::use() {
    auto it = this->layers.find(typeid(T));

    if (it != this->layers.end()) {
      return std::static_pointer_cast<T>(it->second);
    }

    return nullptr;
  }
}