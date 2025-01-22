#pragma once

#include <bgfx/bgfx.h>
#include <iostream>

namespace Graphics {
  class Shader;
}

namespace Graphics {
  class ShaderProgram {
    bgfx::ProgramHandle handle;
    bgfx::VertexLayout layout;

    public:
      // ShaderProgram(Shader* shader);
      ShaderProgram(Shader& vertexShader, Shader& fragmentShader);

      bgfx::ProgramHandle& get();
      bgfx::VertexLayout& getLayout();

      ~ShaderProgram();
  };
}
