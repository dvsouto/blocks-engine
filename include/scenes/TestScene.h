#pragma once

#include "include/graphics/Scene.h"

using namespace Graphics;

namespace Scenes {
  class TestScene : public Scene {
    public:
      void init() override;
      void load() override;

      ~TestScene() override;
  };
}