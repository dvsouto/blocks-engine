#include "include/engine/Shader.h"

#include "include/graphics/ShaderLoader.h"
#include "include/graphics/ShaderProgram.h"

using namespace Graphics;

namespace Engine {
  Shader::Shader(const std::string &shaderName) : Shader("vertex_" + shaderName, "fragment_" + shaderName) {}

  Shader::Shader(const std::string &vertexShaderName, const std::string &fragmentShaderName) {
    this->vertexShader = new ShaderLoader(vertexShaderName);
    this->fragmentShader = new ShaderLoader(fragmentShaderName);

    this->shaderProgram = new ShaderProgram(*this->vertexShader, *this->fragmentShader);
  }

  void Shader::initialize() {
    this->makeLayout(this->shaderProgram->getLayout());
  }

  ShaderProgram* Shader::getShaderProgram() const {
    return this->shaderProgram;
  }
  ShaderLoader* Shader::getVertexShader() const {
    return this->vertexShader;
  }
  ShaderLoader* Shader::getFragmentShader() const {
    return this->fragmentShader;
  }

  Shader::~Shader() {
    delete this->vertexShader;
    delete this->fragmentShader;
    delete this->shaderProgram;

    this->vertexShader = nullptr;
    this->fragmentShader = nullptr;
    this->shaderProgram = nullptr;
  }
}