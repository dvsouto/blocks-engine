#pragma once

#include <bgfx/bgfx.h>
#include <iostream>

namespace Graphics {
  class ShaderLoader {
    std::string shaderName;
    bgfx::ShaderHandle shaderHandle{};
    bool loaded = false;

    std::string getType() const;
    std::string getPlatform() const;

    public:
      explicit ShaderLoader(std::string shaderName);
      ~ShaderLoader();

      ShaderLoader* load();
      bool isLoaded() const;
      bgfx::ShaderHandle& get();
  };
}
