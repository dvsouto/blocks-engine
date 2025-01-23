#pragma once

#include <chrono>

using namespace std::chrono;
namespace Engine {
  class Timer {
    high_resolution_clock::time_point lastTime;

    public:
      Timer();

      float getDeltaTime();

      ~Timer() = default;
  };
}