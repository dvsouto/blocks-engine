#pragma once

#include "include/engine/Timer.h"

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
  };
}