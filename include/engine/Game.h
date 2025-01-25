#pragma once

#include "include/engine/Timer.h"

#include "SDL2/SDL.h"

namespace Core {
  class Application;
}

namespace Engine {
  class Game {
    static Core::Application* app;
    void loop();

    // @TODO change it to enum
    static int status;

  public:
      Game();
      ~Game();

      static Timer* timer;

      void run();
      void update() const;
      void render() const;

      void pause();
      void resume();
      void stop();

      void sendOnKeyDownEvent(SDL_Keycode key) const;
      void sendOnKeyUpEvent(SDL_Keycode key) const;
      void sendOnKeyPressEvent(const Uint8* currentKeystate) const;
      void sendOnMouseMoveEvent(int x, int y) const;
  };
}