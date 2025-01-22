#pragma once

#include <bgfx/bgfx.h>

namespace Primitive {
  struct Color;
}

namespace Primitive {
  struct VertexColor {
    float x, y, z;
    unsigned int color;

    VertexColor(float x, float y, float z);
    VertexColor(float x, float y, float z, unsigned int color);
    VertexColor(float x, float y, float z, Color color);

    static void init();
    static bgfx::VertexBufferHandle create(const VertexColor vertexList[]);
  };
}