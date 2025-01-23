#include "include/engine/Game.h"

#include "include/core/Application.h"
#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include "include/core/Window.h"

#include "include/engine/Timer.h"

#include <include/scenes/TestScene.h>

using namespace Core;

namespace Engine {
  Timer* Game::timer = nullptr;
  Application* Game::app = nullptr;

  // @TODO change it to enum
  int Game::status = 0; // 0 = idle / 1 = running / 2 = paused / 3 = stopped

  Game::Game() {
    this->timer = new Timer();
    this->app = Application::getInstance();
    this->status = 0;
  }

  void Game::run() {
    auto* window = Window::getInstance();
    auto* renderer = Renderer::getInstance();
    auto* sceneManager = SceneManager::getInstance();

    window->initialize();
    renderer->initialize(window);
    sceneManager->initialize();

    sceneManager->addScene<Scenes::TestScene>();

    this->app->setWindow(window);
    this->app->setRenderer(renderer);
    this->app->setSceneManager(sceneManager);

    this->status = 1;

    window->run();
  }


  void Game::update() {
    if (this->status == 3) {
      this->app->getWindow()->close();

      return;
    }

    // Game tick
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


  Game::~Game() {
    this->status = 3;

    delete this->timer;

    delete this->app->getSceneManager();
  }
}