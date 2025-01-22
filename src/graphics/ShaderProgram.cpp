#include "include/graphics/ShaderProgram.h"
#include "include/graphics/Shader.h"

#include <bgfx/bgfx.h>

namespace Graphics {
//  ShaderProgram::ShaderProgram(Shader* shader){
//    this->handle = bgfx::createProgram(shader->get(), true);
//  }

  ShaderProgram::ShaderProgram(Shader& vertexShader, Shader& fragmentShader) {
    if (! vertexShader.isLoaded()) {
      vertexShader.load();
    }

    if (! fragmentShader.isLoaded()) {
      fragmentShader.load();
    }

    this->handle = bgfx::createProgram(vertexShader.get(), fragmentShader.get(), true);

    if (! bgfx::isValid(this->handle)) {
      std::cerr << "Error: Shader program handle is invalid!" << std::endl;

    }

    layout.begin()
      .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
      .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
      .end();
  }

  bgfx::ProgramHandle& ShaderProgram::get() {
    return this->handle;
  }

  bgfx::VertexLayout& ShaderProgram::getLayout() {
    return this->layout;
  }

  ShaderProgram::~ShaderProgram(){
   if (bgfx::isValid(this->handle)) {
    bgfx::destroy(this->handle);
    }
  }


}