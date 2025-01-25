#pragma once

#include <include/core/ShaderManager.h>

#include <include/engine/Inputable.h>
#include <include/engine/Movable.h>
#include <include/engine/Updatable.h>

namespace Engine {
  struct Renderable;
}

namespace Engine {
  class Entity : public Movable, public Updatable, public Inputable {
    public:
      std::shared_ptr<Entity> ptr();

      bool isRenderable() const;

      Renderable* getRenderable() const;

    protected:
      Renderable* renderable = nullptr;
      Core::ShaderManager* shaders = nullptr;

      Entity();
      Entity(Renderable* renderable);
  };
}