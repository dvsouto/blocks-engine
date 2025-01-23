#pragma once

#include <include/graphics/Layer.h>

namespace Graphics {
  class Layer;
}

namespace Layers {
  class MeshLayer : public Graphics::Layer {
    public:
      MeshLayer();

      void render() override;
      void update(float deltaTime) override;

      ~MeshLayer() override;
  };
}