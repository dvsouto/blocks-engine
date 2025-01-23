#include "include/shaders/ColorShader.h"
#include "include/engine/Shader.h"
#include "include/graphics/ShaderProgram.h"

#include <bgfx/bgfx.h>

using namespace Engine;
using namespace bgfx;

namespace Shaders {

  ColorShader::ColorShader() : Shader("color") {

  }

  void ColorShader::makeLayout(VertexLayout& layout) {
    layout.begin()
      .add(Attrib::Position, 3, AttribType::Float)
      .add(Attrib::Color0, 4, AttribType::Uint8, true)
      .end();
  }
}