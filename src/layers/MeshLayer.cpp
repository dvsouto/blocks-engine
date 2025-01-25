#include "include/layers/MeshLayer.h"

#include "include/graphics/Layer.h"
#include "include/layers/Views.h"

#include <include/core/EntityManager.h>
#include <include/engine/Renderable.h>
#include <iostream>

namespace Layers {
  MeshLayer::MeshLayer() : Layer(VIEW_SCENE) {};

  void MeshLayer::render() {
    // std::cout << "MeshLayer::render()" << std::endl;

    Layer::render();
  }

  void MeshLayer::update(float deltaTime) {
    Layer::update(deltaTime);
}

  MeshLayer::~MeshLayer(){}
}