#pragma once

#include <bgfx/bgfx.h>
#include <iostream>

namespace Graphics {
  class Shader {
    std::string shaderName;
    bgfx::ShaderHandle shaderHandle{};
    bool loaded = false;

    std::string getType();
    std::string getPlatform();

    public:
      explicit Shader(std::string shaderName);
      ~Shader();

      Shader* load();
      bool isLoaded();
      bgfx::ShaderHandle& get();
  };
}
