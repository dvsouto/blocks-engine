#pragma once

#include "include/engine/Updatable.h"
#include "include/engine/Movable.h"

namespace Core {
  class Keyboard;
}

namespace Engine {
  class Camera;
}

namespace Engine {
  class Player : public Movable, public Updatable {
    std::shared_ptr<Camera> camera = nullptr;
    Core::Keyboard* keyboard = nullptr;

    float speed = 1.0f;

    public:
      Player();

      void update(float deltaTime) override;

      ~Player() override;
  };
}