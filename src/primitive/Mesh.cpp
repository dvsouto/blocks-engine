#include "include/primitive/Mesh.h"
#include <include/primitive/VertexColor.h>

#include <include/engine/Entity.h>
#include <include/engine/Shader.h>

#include "include/graphics/ShaderProgram.h"

#include <bgfx/bgfx.h>
#include <bx/math.h>

namespace Primitive {
  Mesh::Mesh() {}
  Mesh::Mesh(uint8_t viewId, const std::vector<VertexColor> &vertices, const std::vector<uint16_t> &indices, std::shared_ptr<Engine::Shader> shader) :
    Renderable(viewId, vertices, indices, shader) {}

  void Mesh::initialize(Engine::Entity* entity) {
    vertexBuffer = bgfx::createVertexBuffer(
      bgfx::copy(vertices.data(), sizeof(VertexColor) * vertices.size()),
      this->shader->getShaderProgram()->getLayout()
    );

    indexBuffer = bgfx::createIndexBuffer(
      bgfx::copy(indices.data(), sizeof(uint16_t) * indices.size())
    );

    if (!bgfx::isValid(vertexBuffer) || !bgfx::isValid(indexBuffer)) {
      std::cerr << "Error when trying create buffers!" << std::endl;

      return;
    }

    this->entity = entity;

    initialized = true;
  }

  void Mesh::draw() {
    if (this->validateDraw()) {
      // Buffers
      bgfx::setVertexBuffer(0, this->vertexBuffer);
      bgfx::setIndexBuffer(this->indexBuffer);

      // Get model transform
      float transform[16];
      Eigen::Map<Matrix4f>(transform, 4, 4) = this->entity->getTransformMatrix();

      // Set model matrix for rendering
      bgfx::setTransform(transform, 1);

      this->submitDraw();
    }


  }

  Mesh::~Mesh() {
    if (bgfx::isValid(this->vertexBuffer)) {
      bgfx::destroy(this->vertexBuffer);
    }

    if (bgfx::isValid(this->indexBuffer)) {
      bgfx::destroy(this->indexBuffer);
    }
  }
}