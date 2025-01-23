#pragma once

#include <include/graphics/Renderable.h>
#include <iostream>

namespace Engine {
  class Shader;
}

namespace Primitive {
  struct VertexColor;
}

namespace Primitive {
  struct Mesh : Graphics::Renderable {
    Mesh(uint8_t viewId, const std::vector<VertexColor> &vertices, const std::vector<uint16_t>& indices, std::shared_ptr<Engine::Shader> shader);
    ~Mesh() override;

    void initialize() override;
    void update(float deltaTime) override;
    void draw() override;
  };
}