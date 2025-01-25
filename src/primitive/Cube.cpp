#include "include/primitive/Cube.h"
#include "include/primitive/Mesh.h"
#include "include/primitive/Color.h"

#include <include/shaders/ColorShader.h>

namespace Primitive {
  Cube::Cube() : Entity() {
    this->renderable = new Mesh();
    this->renderable->setShader(this->shaders->use<Shaders::ColorShader>());
    this->renderable->setVertices({
      {  0.5f,  0.5f,  0.5f, Color(0, 0, 255) }, // Top-right-front
      {  0.5f, -0.5f,  0.5f, Color(0, 0, 255) }, // Bottom-right-front
      { -0.5f, -0.5f,  0.5f, Color(0, 0, 255) }, // Bottom-left-front
      { -0.5f,  0.5f,  0.5f, Color(0, 0, 255) }, // Top-left-front

      // Back face
      {  0.5f,  0.5f, -0.5f, Color(255, 0, 0) }, // Top-right-back
      {  0.5f, -0.5f, -0.5f, Color(255, 0, 0) }, // Bottom-right-back
      { -0.5f, -0.5f, -0.5f, Color(255, 0, 0) }, // Bottom-left-back
      { -0.5f,  0.5f, -0.5f, Color(255, 0, 0) }  // Top-left-back
    });

    this->renderable->setIndices({
      // Front face (counter-clockwise)
       0, 1, 3,
       1, 2, 3,

       // Back face (counter-clockwise)
       4, 7, 5,
       5, 7, 6,

       // Left face (counter-clockwise)
       3, 6, 7,
       3, 2, 6,

       // Right face (counter-clockwise)
       0, 4, 5,
       0, 5, 1,

       // Top face (counter-clockwise)
       0, 7, 4,
       0, 3, 7,

       // Bottom face (counter-clockwise)
       1, 5, 6,
       1, 6, 2
    });

    this->renderable->initialize(this);

    std::cout << "OI" << std::endl;
  }
}