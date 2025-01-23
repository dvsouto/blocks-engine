#include "include/engine/Player.h"
#include "include/engine/Camera.h"
#include "include/core/Keyboard.h"

#include "include/core/Application.h"
#include "include/core/Window.h"

#include "Eigen/Dense"

using Eigen::Vector3f;

namespace Engine {
  Player::Player() {
    float aspectRatio = Core::Application::getInstance()->getWindow()->getAspectRatio();

    this->camera = std::make_shared<Camera>(60.0f, aspectRatio, 0.1f, 100.0f);
    this->setPosition({0.f, 0.f, 5.f});

    this->keyboard = Core::Keyboard::getInstance();
  }

  void Player::update(float deltaTime) {
    std::cout << "Player::update()" << std::endl;

    Vector3f cameraOffset = {0.0f, 0.0f, 10.0f};

    // Front
    if (keyboard->isKeyPressed(SDL_SCANCODE_W)) {
      this->moveZ(-this->speed * deltaTime);
    }

    // Back
    if (keyboard->isKeyPressed(SDL_SCANCODE_S)) {
      this->moveZ(this->speed * deltaTime);
    }

    // Left
    if (keyboard->isKeyPressed(SDL_SCANCODE_A)) {
      this->moveX(this->speed * deltaTime);
    }

    // Right
    if (keyboard->isKeyPressed(SDL_SCANCODE_D)) {
      this->moveX(-this->speed * deltaTime);
    }

    // Jump
    if (keyboard->isKeyPressed(SDL_SCANCODE_SPACE)) {
      this->moveY(this->speed * deltaTime);
    }

    // Down
    if (keyboard->isKeyPressed(SDL_SCANCODE_LSHIFT)) {
      this->moveY(-this->speed * deltaTime);
    }

    this->camera->updateView(this->getPosition(), cameraOffset);
    this->camera->applyView();
  }

   Player::~Player() {
    this->camera.reset();
  }

}