#include "include/layers/MeshLayer.h"

#include "include/graphics/Layer.h"
#include "include/layers/Views.h"

#include <iostream>

namespace Layers {
  MeshLayer::MeshLayer() : Layer(VIEW_SCENE) {};

  void MeshLayer::render() {
    // std::cout << "MeshLayer::render()" << std::endl;

    Layer::render();
  }

  MeshLayer::~MeshLayer(){}
}