#include "include/graphics/Scene.h"
#include "include/graphics/Layer.h"

namespace Graphics {
   Scene::Scene() : layers() {
     layers.initialize();
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

  // void Scene::addLayer(const std::shared_ptr<Layer> &layer) {
  //   this->layers.push_back(layer);
  // }

  void Scene::render() const {
    this->layers.renderLayers();
  }
}