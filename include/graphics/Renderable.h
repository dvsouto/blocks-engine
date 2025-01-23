#pragma once

#include "include/primitive/VertexColor.h"
#include "include/engine/Updatable.h"
#include "include/engine/Movable.h"

#include <Eigen/Dense>
#include <bgfx/bgfx.h>
#include <include/engine/Shader.h>

using Eigen::Matrix4f;
using Eigen::Vector3;

namespace Engine {
  struct Shader;
}

namespace Graphics {
  class ShaderProgram;
}

namespace Graphics {
  struct Renderable : Engine::Movable, Engine::Updatable {
    Renderable(std::shared_ptr<Engine::Shader> shader);

    Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t> &indices, const std::shared_ptr<Engine::Shader> &shader);
    ~Renderable() override = default;

    virtual void initialize() = 0;
    bool isInitialized() const;

    virtual void draw() = 0;

    protected:
      uint8_t viewId;
      std::vector<Primitive::VertexColor> vertices;
      std::vector<uint16_t> indices;
      bool initialized = false;

      std::shared_ptr<Engine::Shader> shader = nullptr;

      bgfx::VertexBufferHandle vertexBuffer = BGFX_INVALID_HANDLE;
      bgfx::IndexBufferHandle indexBuffer = BGFX_INVALID_HANDLE;

      bool validateDraw() const;
      void submitDraw() const;
  };
}