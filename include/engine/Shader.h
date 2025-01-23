#pragma once

#include <bgfx/bgfx.h>

#include <iostream>

namespace Graphics {
  class ShaderLoader;
  class ShaderProgram;
}

using namespace Graphics;
using namespace bgfx;

namespace Engine {
  struct Shader {
    virtual ~Shader();
    Shader(const Shader&) = delete;

    void initialize();

    ShaderProgram* getShaderProgram() const;
    ShaderLoader* getVertexShader() const;
    ShaderLoader* getFragmentShader() const;

    protected:
      ShaderProgram* shaderProgram = nullptr;
      ShaderLoader* vertexShader = nullptr;
      ShaderLoader* fragmentShader = nullptr;

      Shader(const std::string &shaderName);
      Shader(const std::string &vertexShaderName, const std::string &fragmentShaderName);

      virtual void makeLayout(VertexLayout& layout) = 0;
  };
}