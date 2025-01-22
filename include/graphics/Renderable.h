#pragma once

#include "include/primitive/VertexColor.h"

#include <Eigen/Dense>
#include <bgfx/bgfx.h>

using Eigen::Vector3;
using Eigen::Matrix4f;

namespace Graphics {
  class ShaderProgram;
}

namespace Graphics {
  struct Renderable {
    Renderable(Graphics::ShaderProgram& shaderProgram);

    Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t>& indices, Graphics::ShaderProgram& shaderProgram);
    virtual ~Renderable() = default;

    virtual void initialize() = 0;
    bool isInitialized();

    void setPosition(Vector3<float> position);
    void setRotation(Vector3<float> rotation);

    void move(Vector3<float> move);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void rotate(Vector3<float> rotate);
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

      Graphics::ShaderProgram& shaderProgram;
      bgfx::VertexBufferHandle vertexBuffer = BGFX_INVALID_HANDLE;
      bgfx::IndexBufferHandle indexBuffer = BGFX_INVALID_HANDLE;

      Vector3<float> position = Vector3<float>(0.f, 0.f, 0.f);
      Vector3<float> rotation = Vector3<float>(0.f, 0.f, 0.f);

      Matrix4f getTransformMatrix();
      std::array<float, 16> getTransformArray();

      bool validateDraw();
      void submitDraw() const;
  };
}