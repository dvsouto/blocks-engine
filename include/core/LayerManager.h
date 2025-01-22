#pragma once

#include <iostream>

namespace Graphics {
  class Layer;
}

namespace Core {
  class LayerManager {
    static LayerManager* instance;

    LayerManager();

  public:
    std::vector<std::shared_ptr<Graphics::Layer>> layers;

    static LayerManager* getInstance();

    void initialize();
    void addLayer(std::shared_ptr<Graphics::Layer> layer);
    void renderLayers();
  };
}