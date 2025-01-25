#pragma once

#include <include/engine/Renderable.h>
#include <iostream>

namespace Engine {
  struct Shader;
  class Entity;
}

namespace Primitive {
  struct VertexColor;
}

namespace Primitive {
  struct Mesh : Engine::Renderable {
    Mesh();
    Mesh(uint8_t viewId, const std::vector<VertexColor> &vertices, const std::vector<uint16_t>& indices, std::shared_ptr<Engine::Shader> shader);
    ~Mesh() override;

    void initialize(Engine::Entity* entity) override;
    void draw() override;
  };
}