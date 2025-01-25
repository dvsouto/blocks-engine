#include "include/engine/Renderable.h"
#include "include/engine/Shader.h"

#include "include/graphics/ShaderProgram.h"

#include "include/primitive/VertexColor.h"

#include <Eigen/Dense>
#include <bgfx/bgfx.h>
#include <iostream>

using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3;

using namespace Graphics;

namespace Engine {
  Renderable::Renderable() {}
  Renderable::Renderable(uint8_t viewId) : viewId(viewId) {}
  Renderable::Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t>& indices, const std::shared_ptr<Engine::Shader> &shader) :
    viewId(viewId), vertices(vertices), indices(indices), shader(shader), vertexBuffer(BGFX_INVALID_HANDLE), indexBuffer(BGFX_INVALID_HANDLE) {
  }

  void Renderable::setViewId(uint8_t viewId) {
  this->viewId = viewId;
  }

  void Renderable::setVertices(const std::vector<Primitive::VertexColor> &vertices) {
    this->vertices = vertices;
  }

  void Renderable::setIndices(const std::vector<uint16_t> &indices) {
    this->indices = indices;
  }

  void Renderable::setShader(const std::shared_ptr<Shader> &shader) {
    this->shader = shader;
  }

  bool Renderable::isInitialized() const {
    return initialized;
  };

  bool Renderable::validateDraw() const {
    if (! initialized) {
      std::cerr << "Mesh not initialized in Mesh::draw!";
      return false;
    }

    if (!bgfx::isValid(this->shader->getShaderProgram()->get())) {
      std::cerr << "Error: Invalid shader program handle in Mesh::draw!" << std::endl;
      return false;
    }

    if (!bgfx::isValid(this->vertexBuffer) || !bgfx::isValid(this->indexBuffer)) {
      std::cerr << "Error: Invalid vertex/index shader in Mesh::draw!" << std::endl;
      return false;
    }

    return true;
  }

  void Renderable::submitDraw() const {
    bgfx::submit(this->viewId, this->shader->getShaderProgram()->get());
  }
}