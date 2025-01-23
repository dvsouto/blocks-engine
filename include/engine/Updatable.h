#pragma once

namespace Engine {
  struct Updatable {
    virtual void update(float deltaTime) = 0;
    virtual ~Updatable() = default;
  };
}