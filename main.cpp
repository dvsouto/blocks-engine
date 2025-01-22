#include "include/core/Application.h"
#include "include/core/Renderer.h"
#include "include/core/SceneManager.h"
#include "include/core/Window.h"

#include <include/scenes/TestScene.h>

using namespace Core;

int main() {
  auto* application = Application::getInstance();
  auto* window = Window::getInstance();
  auto* renderer = Renderer::getInstance();
  auto* sceneManager = SceneManager::getInstance();

  window->initialize();
  renderer->initialize(window);
  sceneManager->initialize();

  sceneManager->addScene<Scenes::TestScene>();


  application->setWindow(window);
  application->setRenderer(renderer);
  application->setSceneManager(sceneManager);

  window->run();

  return 0;
}
