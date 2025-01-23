#pragma once

#include "include/graphics/Renderable.h"

namespace Graphics {
  class RenderableEmpty : public Renderable {
    public:
      RenderableEmpty();

      virtual void render() = 0;
      virtual void update(float deltaTime) = 0;
  };
}