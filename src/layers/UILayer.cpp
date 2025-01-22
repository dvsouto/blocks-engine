#include "include/layers/UILayer.h"

#include "include/graphics/Layer.h"
#include "include/layers/Views.h"

#include <iostream>

namespace Layers {
  UILayer::UILayer() : Layer(VIEW_UI) {};

  void UILayer::render(){
    std::cout << "UILayer::render()" << std::endl;

    Layer::render();
  }
}