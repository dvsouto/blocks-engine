#pragma once

#include "include/primitive/VertexColor.h"
#include "include/engine/Updatable.h"

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
  struct Renderable : Engine::Updatable {
    Renderable(std::shared_ptr<Engine::Shader> shader);

    Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t> &indices, const std::shared_ptr<Engine::Shader> &shader);
    ~Renderable() override = default;

    virtual void initialize() = 0;
    bool isInitialized() const;

    void setPosition(const Vector3<float> &position);
    void setRotation(const Vector3<float> &rotation);

    void move(const Vector3<float> &move);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void rotate(const Vector3<float> &rotate);
    void rotateX(float x);
    void rotateY(float y);
    void rotateZ(float z);


    Vector3<float> getPosition();

    virtual void draw() = 0;

    protected:
      uint8_t viewId;
      std::vector<Primitive::VertexColor> vertices;
      std::vector<uint16_t> indices;
      bool initialized = false;

      std::shared_ptr<Engine::Shader> shader = nullptr;

      bgfx::VertexBufferHandle vertexBuffer = BGFX_INVALID_HANDLE;
      bgfx::IndexBufferHandle indexBuffer = BGFX_INVALID_HANDLE;

      Vector3<float> position = Vector3<float>(0.f, 0.f, 0.f);
      Vector3<float> rotation = Vector3<float>(0.f, 0.f, 0.f);

      Matrix4f getTransformMatrix();
      std::array<float, 16> getTransformArray();

      bool validateDraw() const;
      void submitDraw() const;
  };
}