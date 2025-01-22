#include "include/graphics/Shader.h"

#include <bgfx/bgfx.h>
#include <fstream>

namespace Graphics {
  std::string Shader::getType() {
    std::string type;

    switch (bgfx::getRendererType()) {
      case bgfx::RendererType::Noop:
//      case bgfx::RendererType::Direct3D9:  type = "dx9";   break;
      case bgfx::RendererType::Direct3D11:
      case bgfx::RendererType::Direct3D12: type = "dx11";  break;
      case bgfx::RendererType::Agc:
      case bgfx::RendererType::Gnm:        type = "pssl";  break;
      case bgfx::RendererType::Metal:      type = "metal"; break;
      case bgfx::RendererType::Nvn:        type = "nvn";   break;
      case bgfx::RendererType::OpenGL:     type = "glsl";  break;
      case bgfx::RendererType::OpenGLES:   type = "essl";  break;
      case bgfx::RendererType::Vulkan:     type = "spirv"; break;
//      case bgfx::RendererType::WebGPU:     type = "spirv"; break;
      default:
        type = "unknown";
        break;
    }

    return type;
  }

  std::string Shader::getPlatform() {
    return "osx";
  }

  Shader::Shader(std::string shaderName) : shaderName(shaderName) {}

  bool Shader::isLoaded() {
    return this->loaded;
  }


  Shader* Shader::load() {
    std::string path = "/assets/shaders/bin/" + getPlatform() + "/" + shaderName + "." + getType() + ".bin";

    // @TODO fix relative path
    path = "/Users/dvsouto/Dados/Projetos/bitnary/blocks" + path;

    std::cout << "Loading shader " << shaderName << ": " << path << std::endl;

    char* data = new char[2048];
    std::ifstream file;
    size_t fileSize;
    file.open(path);

    if(file.is_open()) {
      file.seekg(0, std::ios::end);
      fileSize = file.tellg();
      file.seekg(0, std::ios::beg);
      file.read(data, fileSize);
      file.close();
    }

    if (std::strlen(data) < 1) {
      std::cerr << "Failed to load shader: " << path << std::endl;
      return this;
    }

    const bgfx::Memory* mem = bgfx::copy(data, fileSize+1);

    mem->data[mem->size-1] = '\0';

    this->shaderHandle = bgfx::createShader(mem);

    bgfx::setName(this->shaderHandle, shaderName.c_str());

    if (! bgfx::isValid(this->shaderHandle)) {
      std::cerr << "Failed to load shader: " << path << std::endl;
      return this;
    }

    this->loaded = true;

    std::cout << "Shader " << shaderName << " loaded" << std::endl;

    return this;
  }

  bgfx::ShaderHandle& Shader::get() {
     return this->shaderHandle;
  }

  Shader::~Shader() {
    this->loaded = false;

    if (bgfx::isValid(this->shaderHandle)) {
      bgfx::destroy(this->shaderHandle);
    }
  }
}