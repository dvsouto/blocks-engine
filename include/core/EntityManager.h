#pragma once

#include "include/engine/Entity.h"

#include <SDL2/SDL_keycode.h>

#include <iostream>
#include <typeindex>

using namespace Engine;

namespace Core {
  class EntityManager {
  std::vector<std::shared_ptr<Entity>> entities;

public:
    EntityManager();

    void initialize() const;

    void add(const std::shared_ptr<Entity>& entity);
    void remove(std::shared_ptr<Entity>& entity);
    bool exists(std::shared_ptr<Entity>& entity);
    int countOf(std::shared_ptr<Entity>& entity);
    int count();

    std::vector<std::shared_ptr<Entity>>* all();

    //    ~EntityManager();
  };
}