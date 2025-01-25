#pragma once

#include "include/graphics/Scene.h"
#include "include/engine/Player.h"

using namespace Graphics;
using namespace Engine;

namespace Scenes {
  class AnotherScene : public Scene {
    std::shared_ptr<Player> player = nullptr;
    public:
      void init() override;
      void load() override;
      void update(float deltaTime) override;

      void onKeyUp(SDL_Keycode key) override;

      ~AnotherScene() override;
  };
}