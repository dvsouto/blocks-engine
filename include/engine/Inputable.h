#pragma once

#include <SDL2/SDL.h>

namespace Core {
  class Keyboard;
  class Mouse;
}

namespace Engine {
  struct Inputable {
    Core::Keyboard* keyboard = nullptr;
    Core::Mouse* mouse = nullptr;

    virtual void onKeyDown(SDL_Keycode key){};
    virtual void onKeyUp(SDL_Keycode key){};
    virtual void onKeyPress(const Uint8* currentKeystate){};
    virtual void onMouseMove(int x, int y){};

    Inputable();
    virtual ~Inputable() = default;
  };
}