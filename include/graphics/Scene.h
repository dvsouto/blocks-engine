#pragma once

#include <include/core/LayerManager.h>
#include <iostream>

namespace Core {
  class LayerManager;
}

namespace Graphics {
  class Layer;
}

namespace Graphics {
  class Scene {
    public:
      Core::LayerManager layers;

      Scene();

      virtual ~Scene() = default;
      virtual void init() = 0;
      // virtual void update(float deltaTime) = 0;
      void render() const;

      // void addLayer(const std::shared_ptr<Layer> &layer);

      virtual void load() = 0;
      void unload();
      bool isLoaded() const;

    protected:
      bool loaded = false;
  };
}