#include "include/core/Application.h"
#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include "include/core/ShaderManager.h"
#include "include/core/Window.h"
#include "include/core/Keyboard.h"
#include "include/core/Mouse.h"

#include "include/engine/Game.h"
#include "include/engine/Timer.h"

using namespace Engine;

namespace Core {
  Application* Application::instance = nullptr;
  Window* Application::window = nullptr;
  Renderer* Application::renderer = nullptr;
  SceneManager* Application::sceneManager = nullptr;
  ShaderManager* Application::shaderManager = nullptr;
  Game* Application::game = nullptr;
  Keyboard* Application::keyboard = nullptr;
  Mouse* Application::mouse = nullptr;
  Timer* Application::timer = nullptr;

  Application::Application() {}

  Application* Application::getInstance() {
    if (instance == nullptr) {
      instance = new Application();
    }

    return instance;
  }

  Window* Application::getWindow() const {
    return window;
  }

  Renderer* Application::getRenderer() const {
    return renderer;
  }

  SceneManager* Application::getSceneManager() const {
    return sceneManager;
  }

  ShaderManager* Application::getShaderManager() const {
    return shaderManager;
  }

  Game* Application::getGame() const {
    return game;
  };

  Keyboard* Application::getKeyboard() const {
    return keyboard;
  };

  Mouse* Application::getMouse() const {
    return mouse;
  };

  Timer* Application::getTimer() const {
    return timer;
  };

  void Application::setWindow(Window* windowInstance) const {
    window = windowInstance;
  }

  void Application::setRenderer(Renderer *rendererInstance) const {
    renderer = rendererInstance;
  }

  void Application::setSceneManager(SceneManager *sceneManagerInstance) const {
    sceneManager = sceneManagerInstance;
  }

  void Application::setShaderManager(ShaderManager *shaderManagerInstance) const {
    shaderManager = shaderManagerInstance;
  }

  void Application::setGame(Game *gameInstance) const {
    game = gameInstance;
  }

  void Application::setKeyboard(Keyboard *keyboardInstance) const {
    keyboard = keyboardInstance;
  }

  void Application::setMouse(Mouse *mouseInstance) const {
    mouse = mouseInstance;
  }

  void Application::setTimer(Timer *timerInstance) const {
    timer = timerInstance;
  }

  Application::~Application() {
    std::cout << std::endl << "Application::~Application" << std::endl;

    renderer = nullptr;
    window = nullptr;
  }
}