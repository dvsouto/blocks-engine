#pragma once

namespace Primitive {
  struct Color {
    float r, g, b, alpha;

    Color(float r, float g, float b, float alpha);
    Color(int r, int g, int b, int alpha);
    Color(float r, float g, float b);
    Color(int r, int g, int b);

    unsigned int abgr() const;
    unsigned int argb() const;
    unsigned int rgba() const;
  };
}