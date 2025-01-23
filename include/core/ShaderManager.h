#pragma once

#include <include/engine/Shader.h>

#include <iostream>
#include <typeindex>

namespace Engine {
  struct Shader;
}

using namespace Engine;

namespace Core {
  class ShaderManager {
    ShaderManager();

    public:
      static ShaderManager* instance;
      static ShaderManager* getInstance();

      std::unordered_map<std::type_index, std::shared_ptr<Shader>> shaders;

      void initialize();

      template<typename T>
      void addShader(std::shared_ptr<T> shader);

      template<typename T>
      std::shared_ptr<T> use();
    };
}

namespace Core {
  template<typename T>
  void ShaderManager::addShader(std::shared_ptr<T> shader) {
    auto itShaderIdx = std::type_index(typeid(T));

    this->shaders.insert(std::make_pair(itShaderIdx, shader));
  }

  template<typename T>
  std::shared_ptr<T> ShaderManager::use() {
    auto itShaderIdx = std::type_index(typeid(T));

    const auto it = this->shaders.find(itShaderIdx);

    if (it != this->shaders.end()) {
      return std::static_pointer_cast<T>(it->second);
    }

    return nullptr;
  }
}