#pragma once

#include "include/graphics/Layer.h"

namespace Layers {
  class UILayer : public Graphics::Layer {
    public:
      UILayer();
      void render() override;
      void update(float deltaTime) override;
  };
}