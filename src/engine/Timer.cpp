#include "include/engine/Timer.h"

#include <chrono>

using namespace std::chrono;

namespace Engine {
  Timer* Timer::instance = nullptr;

  Timer::Timer() : lastTime(high_resolution_clock::now()), deltaTime(0) {}

  Timer* Timer::getInstance() {
    if (instance == nullptr) {
      instance = new Timer();
    }

    return instance;
  }

  float Timer::getDeltaTime() const {
    return this->deltaTime;
  }

  void Timer::update() {
    auto now = high_resolution_clock::now();
    duration<float> delta = now - lastTime;

    this->lastTime = now;
    this->deltaTime = delta.count();
  }
}