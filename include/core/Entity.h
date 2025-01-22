#pragma once

namespace Core {
  class Entity {
    Entity() = default;
    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void render() = 0;
  };
}