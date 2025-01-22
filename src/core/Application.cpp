#include "include/core/Application.h"
#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include "include/core/Window.h"

namespace Core {
  Application* Application::instance = nullptr;
  Window* Application::window = nullptr;
  Renderer* Application::renderer = nullptr;
  SceneManager* Application::sceneManager = nullptr;

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

  void Application::setWindow(Window* windowInstance) const {
    window = windowInstance;
  }

  void Application::setRenderer(Renderer *rendererInstance) const {
    renderer = rendererInstance;
  }

  void Application::setSceneManager(SceneManager *sceneManagerInstance) const {
    sceneManager = sceneManagerInstance;
  }

  Application::~Application() {
    std::cout << std::endl << "Application::~Application" << std::endl;

    renderer = nullptr;
    window = nullptr;
  }
}