#include "include/primitive/Plane.h"
#include "include/primitive/Mesh.h"
#include "include/primitive/Color.h"

#include <include/shaders/ColorShader.h>

namespace Primitive {
  Plane::Plane() : Entity() {
    this->renderable = new Mesh();
    this->renderable->setShader(this->shaders->use<Shaders::ColorShader>());
    this->renderable->setVertices({
      {  -0.5f, 0.f,  -0.5f, /* Color(0, 0, 255) */ }, // Bottom left
      {  0.5f,  0.0f, -0.5f, /* Color(0, 0, 255) */ }, // Bottot right
      { -0.5f,  0.0f,  0.5f, /* Color(0, 0, 255) */ }, // Top left
      { 0.5f,   0.0f,  0.5f, /* Color(0, 0, 255) */ }, // Top right
    });

    this->renderable->setIndices({
      0, 1, 2,
      1, 3, 2
    });

    this->renderable->initialize(this);
  }
}