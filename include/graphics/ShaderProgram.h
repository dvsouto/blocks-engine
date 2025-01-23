#pragma once

#include <bgfx/bgfx.h>
#include <iostream>

namespace Graphics {
  class ShaderLoader;
}

namespace Graphics {
  class ShaderProgram {
    bgfx::ProgramHandle handle;
    bgfx::VertexLayout layout;

    public:
      // ShaderProgram(Shader* shader);
      ShaderProgram(ShaderLoader& vertexShader, ShaderLoader& fragmentShader);

      bgfx::ProgramHandle& get();
      bgfx::VertexLayout& getLayout();

      ~ShaderProgram();
  };
}
