#pragma once

namespace Engine {
  class Timer;
}

namespace Engine {
  struct Updatable {
    Timer* timer = nullptr;

    Updatable();

    virtual void update(float deltaTime){};
    virtual ~Updatable() = default;
  };
}