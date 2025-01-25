#include "include/graphics/Scene.h"
#include "include/core/Application.h"

namespace Graphics {
   Scene::Scene() : layers(nullptr), shaders(nullptr) {
     this->layers = new LayerManager();
     this->layers->initialize();

     this->shaders = Core::Application::getInstance()->getShaderManager();
     this->app = Core::Application::getInstance();
   }

  bool Scene::isLoaded() const {
    return this->loaded;
  }

  // @TODO create load scene method
  void Scene::load() {
    this->loaded = true;
  }

  // @TODO create unload scene method
  void Scene::unload() {
    this->loaded = false;
  }

  void Scene::render() const {
    this->layers->renderLayers();
  }
}