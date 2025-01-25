#pragma once

#include <include/engine/Updatable.h>

#include <include/engine/Inputable.h>
#include <vector>

namespace Engine {
  struct Renderable;
}

namespace Core {
  class EntityManager;
}

using namespace Core;
using namespace Engine;

namespace Graphics {
  class Layer : public Updatable, public Inputable {
    protected:
      unsigned int viewId;
      bool visible = true;

      Layer(unsigned int viewId);

    public:
      ~Layer() override = default;

      EntityManager* entities = nullptr;

      virtual void render();
      void update(float deltaTime) override;

      void handleKeyDown(SDL_Keycode key) const;
      void handleKeyUp(SDL_Keycode key) const;
      void handleKeyPress(const Uint8* currentKeystate) const;
      void handleMouseMove(int x, int y) const;

      bool isVisible() const;
  };
}