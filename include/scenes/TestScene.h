#pragma once

#include "include/graphics/Scene.h"
#include "include/engine/Player.h"

using namespace Graphics;
using namespace Engine;

namespace Scenes {
  class TestScene : public Scene {
    std::shared_ptr<Player> player = nullptr;
    public:
      void init() override;
      void load() override;
      void update(float deltaTime) override;

      ~TestScene() override;
  };
}