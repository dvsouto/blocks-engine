#pragma once

#include <iostream>

namespace Graphics {
  class Layer;
}

namespace Graphics {
  class Scene {
    bool loaded = false;

    public:
      Scene() = default;

      virtual ~Scene() = default;
      virtual void init() = 0;
      // virtual void update(float deltaTime) = 0;
      void render() const;

      void addLayer(const std::shared_ptr<Layer> &layer);

      virtual void load() = 0;
      void unload();
      bool isLoaded() const;

    protected:
      std::vector<std::shared_ptr<Layer>> layers;
  };
}