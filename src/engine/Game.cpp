#include "include/engine/Game.h"

#include <include/core/Application.h>
#include "include/core/Keyboard.h"
#include "include/core/Mouse.h"
#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include "include/core/ShaderManager.h"
#include "include/core/Window.h"

#include "include/engine/Timer.h"

#include <include/scenes/TestScene.h>
#include <include/scenes/AnotherScene.h>

using namespace Core;

namespace Engine {
  Timer* Game::timer = nullptr;
  Application* Game::app = nullptr;

  // @TODO change it to enum
  int Game::status = 0; // 0 = idle / 1 = running / 2 = paused / 3 = stopped

  Game::Game() {
    this->app = Application::getInstance();
    this->timer = Timer::getInstance();
    this->status = 0;
  }

  void Game::run() {
    auto* window = Window::getInstance();
    auto* keyboard = Keyboard::getInstance();
    auto* mouse = Mouse::getInstance();
    auto* renderer = Renderer::getInstance();
    auto* sceneManager = SceneManager::getInstance();
    auto* shaderManager = ShaderManager::getInstance();

    this->app->setWindow(window);
    this->app->setKeyboard(keyboard);
    this->app->setMouse(mouse);
    this->app->setRenderer(renderer);
    this->app->setShaderManager(shaderManager);
    this->app->setSceneManager(sceneManager);
    this->app->setTimer(this->timer);

    window->initialize();
    keyboard->initialize();
    mouse->initialize();
    renderer->initialize(window);
    shaderManager->initialize();
    sceneManager->initialize();

    sceneManager->addScene<Scenes::AnotherScene>();
    sceneManager->addScene<Scenes::TestScene>();

    this->status = 1;

    window->run();
  }


  void Game::update() const {
    // Close window if game has stopped
    if (this->status == 3) {
      this->app->getWindow()->close();

      return;
    }

    this->timer->update();

    // Update current scene
    if (this->status == 1) {
      float deltaTime = this->timer->getDeltaTime();

      this->app->getSceneManager()->update(deltaTime);
    }
  }

  void Game::render() const {
    if (this->app->getRenderer()->isRunning()) {
      this->app->getRenderer()->render();
    }
  }

  void Game::pause() {
    this->status = 2;
  }

  void Game::resume() {
    this->status = 1;
  }

  void Game::stop() {
    this->status = 3;
  }

  void Game::sendOnKeyDownEvent(SDL_Keycode key) const {
    if (this->status == 1) {
      this->app->getSceneManager()->handleKeyDown(key);
    }
  }

  void Game::sendOnKeyUpEvent(SDL_Keycode key) const {
    if (this->status == 1) {
      this->app->getSceneManager()->handleKeyUp(key);
    }
  }

  void Game::sendOnKeyPressEvent(const Uint8* currentKeystate) const {
    if (this->status == 1) {
      this->app->getSceneManager()->handleKeyPress(currentKeystate);
    }
  }

  void Game::sendOnMouseMoveEvent(int x, int y) const {
    if (this->status == 1) {
      this->app->getSceneManager()->handleMouseMove(x, y);
    }
  }



  Game::~Game() {
    this->status = 3;

    delete this->timer;

    delete this->app->getSceneManager();
  }
}