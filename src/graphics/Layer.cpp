#include "include/graphics/Layer.h"

#include "include/core/EntityManager.h"

#include "include/engine/Renderable.h"

using namespace Core;
using namespace Engine;

namespace Graphics {
  Layer::Layer(unsigned int viewId) : viewId(viewId) {
    this->entities = new EntityManager();
  };

  bool Layer::isVisible() const {
    return visible;
  }

  void Layer::render() {
    if (! this->isVisible()) {
       return;
    }

    for (const auto& itEntity : *this->entities->all()) {
      if (itEntity->isRenderable()) {
        itEntity->getRenderable()->draw();
      }
    }
  }

  void Layer::update(float deltaTime) {
    for (const auto& itEntity : *this->entities->all()) {
      itEntity->update(deltaTime);
    }
  }

  void Layer::handleKeyDown(SDL_Keycode key) const {
    for (const auto& itEntity : *this->entities->all()) {
      itEntity->onKeyDown(key);
    }
  }

  void Layer::handleKeyUp(SDL_Keycode key) const {
    for (const auto& itEntity : *this->entities->all()) {
      itEntity->onKeyUp(key);
    }
  }

  void Layer::handleKeyPress(const Uint8* currentKeystate) const {
    for (const auto& itEntity : *this->entities->all()) {
      itEntity->onKeyPress(currentKeystate);
    }
  }

  void Layer::handleMouseMove(int x, int y) const {
    for (const auto& itEntity : *this->entities->all()) {
      itEntity->onMouseMove(x, y);
    }
  }

}