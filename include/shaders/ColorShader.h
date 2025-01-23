#pragma once

#include "include/engine/Shader.h"

using namespace Engine;

namespace Shaders {
  struct ColorShader final : Shader {
    ColorShader();

    protected:
      void makeLayout(VertexLayout& layout) override;
  };
}