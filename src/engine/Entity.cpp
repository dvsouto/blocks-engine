#include "include/engine/Entity.h"

#include <include/core/ShaderManager.h>

namespace Engine {

  Entity::Entity() : shaders(Core::ShaderManager::getInstance()) {};
  Entity::Entity(Renderable *renderable) : renderable(renderable), shaders(Core::ShaderManager::getInstance()) {};

  bool Entity::isRenderable() const {
    return this->renderable != nullptr;
  }

  Renderable* Entity::getRenderable() const {
    return this->renderable;
  }
}