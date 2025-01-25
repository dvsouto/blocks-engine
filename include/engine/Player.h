#pragma once

#include "Entity.h"
#include "Inputable.h"
#include "include/engine/Movable.h"
#include "include/engine/Updatable.h"

namespace Core {
  class Keyboard;
  class Mouse;
}

namespace Engine {
  class Camera;
}

namespace Engine {
  class Player : public Entity {
    std::shared_ptr<Camera> camera = nullptr;
    Core::Keyboard* keyboard = nullptr;
    Core::Mouse* mouse = nullptr;

    float speed = 5.0f;
    float mouseSensivity = 0.1f;

    void playerMoveEvent(float deltaTime);
    void playerRotateEvent(float deltaTime);


    public:
      Player();

      void update(float deltaTime) override;
      void onMouseMove(int x, int y) override;
      void onKeyPress(const Uint8* currentKeystate) override;

      ~Player() override;
  };
}