#include "include/graphics/Layer.h"
#include "include/graphics/Renderable.h"

#include <vector>

namespace Graphics {
  Layer::Layer(unsigned int viewId) : viewId(viewId) {};

  bool Layer::isVisible() const {
    return visible;
  }

  void Layer::add(const std::shared_ptr<Renderable>& renderable) {
    this->renderables.push_back(renderable);
  }

  void Layer::remove(std::shared_ptr<Renderable>& renderable) {
    // this->renderables->(renderable);
  }

  int Layer::size() {
    return this->renderables.size();
  }

  void Layer::render() {
    if (! this->isVisible()) {
       return;
    }

    for (const auto& renderable : this->renderables) {
      renderable->draw();
    }
  }
}