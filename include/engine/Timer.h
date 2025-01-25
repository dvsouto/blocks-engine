#pragma once

#include <chrono>

using namespace std::chrono;

namespace Engine {
  class Timer {
    static Timer* instance;

    high_resolution_clock::time_point lastTime;
    float deltaTime;

    Timer();

    public:
      static Timer* getInstance();

      void update();
      float getDeltaTime() const;

      ~Timer() = default;
  };
}