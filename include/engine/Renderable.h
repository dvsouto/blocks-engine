#pragma once

#include "include/primitive/VertexColor.h"

#include "include/engine/Updatable.h"
#include "include/engine/Movable.h"
#include "include/engine/Inputable.h"
#include <include/engine/Shader.h>

#include <Eigen/Dense>
#include <bgfx/bgfx.h>

using Eigen::Matrix4f;
using Eigen::Vector3;

namespace Engine {
  struct Shader;
  class Entity;
}

namespace Graphics {
  class ShaderProgram;
}

using namespace Graphics;

namespace Engine {
  struct Renderable {
    Renderable();
    Renderable(uint8_t viewId);
    Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t> &indices, const std::shared_ptr<Shader> &shader);

    virtual ~Renderable() = default;

    virtual void initialize(Entity* entity) = 0;
    bool isInitialized() const;

    virtual void draw() = 0;

    void setViewId(uint8_t viewId);
    void setVertices(const std::vector<Primitive::VertexColor> &vertices);
    void setIndices(const std::vector<uint16_t> &indices);
    void setShader(const std::shared_ptr<Shader> &shader);

    protected:
      uint8_t viewId = 0;
      std::vector<Primitive::VertexColor> vertices;
      std::vector<uint16_t> indices;
      bool initialized = false;

      std::shared_ptr<Shader> shader = nullptr;
      Entity* entity = nullptr;

      bgfx::VertexBufferHandle vertexBuffer = BGFX_INVALID_HANDLE;
      bgfx::IndexBufferHandle indexBuffer = BGFX_INVALID_HANDLE;

      bool validateDraw() const;
      void submitDraw() const;
  };
}