#include "include/primitive/VertexColor.h"
#include "include/primitive/Color.h"

namespace Primitive {
  VertexColor::VertexColor(float x, float y, float z, unsigned int color) :
    x(x), y(y), z(z), color(color) {};

  VertexColor::VertexColor(float x, float y, float z) :
    x(x), y(y), z(z), color(Primitive::Color{135, 135, 135}.abgr()) {}

  VertexColor::VertexColor(float x, float y, float z, Primitive::Color color) :
    x(x), y(y), z(z), color(color.abgr()) {}

}