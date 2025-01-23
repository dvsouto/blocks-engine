#include "include/engine/Timer.h"

#include <chrono>

using namespace std::chrono;

namespace Engine {
  Timer::Timer(): lastTime(high_resolution_clock::now()){}

  float Timer::getDeltaTime() {
    auto now = high_resolution_clock::now();
    duration<float> delta = now - lastTime;

    this->lastTime = now;

    return delta.count();
  }
}