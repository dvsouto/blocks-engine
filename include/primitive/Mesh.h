#pragma once

#include <bgfx/bgfx.h>
#include <include/graphics/Renderable.h>
#include <iostream>

namespace Graphics {
  class ShaderProgram;
}

namespace Primitive {
  class VertexColor;
}

namespace Primitive {
  struct Mesh : Graphics::Renderable {
    Mesh(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t>& indices, Graphics::ShaderProgram& shaderProgram);
    ~Mesh() override;

    void initialize() override;
    void update(float deltaTime) override;
    void draw() override;
  };
}