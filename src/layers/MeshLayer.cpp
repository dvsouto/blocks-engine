#include "include/layers/MeshLayer.h"

#include "include/graphics/Layer.h"
#include "include/layers/Views.h"

#include <include/graphics/Renderable.h>
#include <iostream>

namespace Layers {
  MeshLayer::MeshLayer() : Layer(VIEW_SCENE) {};

  void MeshLayer::render() {
    // std::cout << "MeshLayer::render()" << std::endl;

    Layer::render();
  }

  void MeshLayer::update(float deltaTime) {
    Layer::update(deltaTime);

    for (const auto& renderable : renderables) {
      renderable->rotateX(7.5f * deltaTime);
      renderable->rotateY(8.5f * deltaTime);
      renderable->rotateZ(9.5f * deltaTime);
    }
}

  MeshLayer::~MeshLayer(){}
}