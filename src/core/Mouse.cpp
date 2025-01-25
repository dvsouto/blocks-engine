#include "include/core/Mouse.h"
#include "include/core/Application.h"
#include <include/core/Window.h>
#include "include/core/SceneManager.h"

#include <Eigen/Dense>
#include <chrono>

namespace Core {
  Mouse* Mouse::instance = nullptr;

  Mouse::Mouse() {
    this->app = Application::getInstance();
  }

  Mouse* Mouse::getInstance() {
    if (instance == nullptr) {
      instance = new Mouse();
    }

    return instance;
  }

  Mouse::~Mouse() {}

  void Mouse::initialize() {

  }

  void Mouse::handleMouseMove(int x, int y) {
    this->axisX = x;
    this->axisY = y;

    this->lastUpdate = std::chrono::high_resolution_clock::now();

    this->app->getSceneManager()->handleMouseMove(this->axisX, this->axisY);
  }

  void Mouse::reset() {
    this->axisX = 0;
    this->axisY = 0;
  }

  void Mouse::show() {
    this->visible = true;

    Application::getInstance()->getWindow()->setCursorVisibility(visible);
  }

  void Mouse::hide() {
    this->visible = false;

    Application::getInstance()->getWindow()->setCursorVisibility(visible);
  }

  void Mouse::toggleVisibility() {
    this->visible = !this->visible;

    Application::getInstance()->getWindow()->setCursorVisibility(visible);
  }


  int Mouse::getAxisX() const {
    return this->axisX;
  }

  int Mouse::getAxisY() const {
    return this->axisY;
  }

  Eigen::Vector2<int> Mouse::getAxis() const {
    return Eigen::Vector2<int>(this->axisX, this->axisY);
  }
}