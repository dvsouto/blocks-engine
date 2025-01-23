#include "include/core/ShaderManager.h"
#include "include/engine/Shader.h"

#include "include/shaders/ColorShader.h"

#include <iostream>

using namespace Engine;
using namespace Shaders;

namespace Core {
  ShaderManager* ShaderManager::instance = nullptr;

  ShaderManager::ShaderManager() {}

  ShaderManager* ShaderManager::getInstance() {
    if (instance == nullptr) {
      instance = new ShaderManager();
    }

    return instance;
  }

  void ShaderManager::initialize(){
    auto colorShader = std::make_shared<ColorShader>();

    colorShader->initialize();

    this->addShader<Shaders::ColorShader>(colorShader);
  }
}