#include "include/core/EntityManager.h"

#include "include/engine/Entity.h"

#include <iostream>

using namespace Engine;

namespace Core {
  EntityManager::EntityManager() {}

  void EntityManager::initialize() const {}

  void EntityManager::add(const std::shared_ptr<Entity>& entity) {
    this->entities.push_back(entity);
  }

  void EntityManager::remove(std::shared_ptr<Entity>& entity) {
    // this->entities->(renderable);
  }

  bool EntityManager::exists(std::shared_ptr<Entity>& entity) {
    return false;
  }

  int EntityManager::countOf(std::shared_ptr<Entity>& entity) {
    return 0;
  }

  int EntityManager::count() {
    return this->entities.size();
  }

  std::vector<std::shared_ptr<Entity>>* EntityManager::all() {
    return &this->entities;
  }
}