#include "include/engine/Player.h"
#include "include/engine/Camera.h"

#include "include/core/Application.h"
#include "include/core/Window.h"

#include "include/core/Keyboard.h"
#include "include/core/Mouse.h"

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <include/engine/Timer.h>

using Eigen::Vector3f;

namespace Engine {
  Player::Player() : Entity() {
    float aspectRatio = Core::Application::getInstance()->getWindow()->getAspectRatio();

    this->camera = std::make_shared<Camera>(60.0f, aspectRatio, 0.1f, 100.0f);
    this->setPosition({0.f, 0.f, 5.f});

    this->keyboard = Core::Keyboard::getInstance();
    this->mouse = Core::Mouse::getInstance();

    this->setPosition({0.f, 0.f, -10.f});
  }

  void Player::update(float deltaTime) {
    // std::cout << "Player::update()" << std::endl;

    Vector3f cameraOffset = {0.0f, 0.8f, 0.0f};

    this->camera->updateView(this->getPosition(), this->getRotation(), cameraOffset);
    this->camera->applyView();
  }

  void Player::onKeyPress(const Uint8* currentKeystate) {
    float deltaTime = this->timer->getDeltaTime();

    // Front
    if (keyboard->isKeyPressed(SDL_SCANCODE_W)) {
      this->position += forward() * speed * deltaTime;
    }

    // Back
    if (keyboard->isKeyPressed(SDL_SCANCODE_S)) {
      this->position -= forward() * speed * deltaTime;
    }

    // Left
    if (keyboard->isKeyPressed(SDL_SCANCODE_A)) {
      this->position -= right() * speed * deltaTime;
    }

    // Right
    if (keyboard->isKeyPressed(SDL_SCANCODE_D)) {
      this->position += right() * speed * deltaTime;
    }

    // Jump
    if (keyboard->isKeyPressed(SDL_SCANCODE_SPACE)) {
      this->position.y() += speed * deltaTime;
    }

    // Down
    if (keyboard->isKeyPressed(SDL_SCANCODE_LSHIFT)) {
      this->position.y() -= speed * deltaTime;
    }
  }

  void Player::onMouseMove(int x, int y) {
    // Yaw
    this->rotateY(x * this->mouseSensivity);

    // Pitch
    this->rotateX(-y * this->mouseSensivity);

    if (this->getRotation().x() > 89.0f) {
      this->getRotation()[0] = 89.0f;
    }

    if (this->getRotation().x() < -89.0f) {
      this->getRotation()[0] = -89.0f;
    }
  }

  Player::~Player() {
    this->camera.reset();
  }

}