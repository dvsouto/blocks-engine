#include "include/primitive/Color.h";

#include <bgfx/bgfx.h>
#include <iostream>


namespace Primitive {
  Color::Color(float r, float g, float b, float alpha) :
    r(r), g(g), b(b), alpha(alpha) {};

  Color::Color(int r, int g, int b, int alpha) :
    r(r / 255.0f), g(g / 255.0f), b(b / 255.0f), alpha(alpha / 255.0f) {};

  Color::Color(float r, float g, float b) :
    r(r), g(g), b(b), alpha(1.0f) {};

  Color::Color(int r, int g, int b) :
    r(r / 255.0f), g(g / 255.0f), b(b / 255.0f), alpha(1.0f) {};


  unsigned int Color::abgr() const {
    uint8_t rInt = static_cast<uint8_t>(r * 255);
    uint8_t gInt = static_cast<uint8_t>(g * 255);
    uint8_t bInt = static_cast<uint8_t>(b * 255);
    uint8_t alphaInt = static_cast<uint8_t>(alpha * 255);

    return (alphaInt << 24) | (bInt << 16) | (gInt << 8) | rInt;
  }

  unsigned int Color::argb() const {
    uint8_t rInt = static_cast<uint8_t>(r * 255);
    uint8_t gInt = static_cast<uint8_t>(g * 255);
    uint8_t bInt = static_cast<uint8_t>(b * 255);
    uint8_t alphaInt = static_cast<uint8_t>(alpha * 255);

    return (alphaInt << 24) | (rInt << 16) | (gInt << 8) | bInt;
  }

  unsigned int Color::rgba() const {
    uint8_t rInt = static_cast<uint8_t>(r * 255);
    uint8_t gInt = static_cast<uint8_t>(g * 255);
    uint8_t bInt = static_cast<uint8_t>(b * 255);
    uint8_t alphaInt = static_cast<uint8_t>(alpha * 255);

    return (rInt << 24) | (gInt << 16) | (bInt << 8) | alphaInt;
  }
}