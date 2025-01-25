#include "include/scenes/AnotherScene.h"

#include <include/core/Mouse.h>
#include <include/core/ShaderManager.h>
#include <include/core/EntityManager.h>
#include <include/core/SceneManager.h>

#include "include/graphics/Scene.h"

#include "include/engine/Player.h"

#include "include/layers/MeshLayer.h"
#include "include/layers/UILayer.h"

#include "include/primitive/Cube.h"
#include "include/primitive/Plane.h"

#include <include/scenes/TestScene.h>


#include <iostream>

using namespace Engine;
using namespace Graphics;
using namespace Primitive;
using namespace Layers;

using namespace std;

namespace Scenes {
  void AnotherScene::init() {
    cout << "AnotherScene::init()" << endl;

    this->layers->create<MeshLayer>();

    this->player = std::make_shared<Player>();

    auto cube = std::make_shared<Cube>();


    cube->moveX(-1.5f);
    cube->moveZ(-1.5f);

    this->layers->use<MeshLayer>()->entities->add(this->player);
    this->layers->use<MeshLayer>()->entities->add(cube);
  };

  void AnotherScene::load() {
    Scene::load();
  }

  void AnotherScene::update(float deltaTime) {
     for (const auto& entity : *this->layers->use<MeshLayer>()->entities->all()) {
       if (entity->isRenderable()) {
         entity->rotateX(7.5f * deltaTime);
         entity->rotateY(8.5f * deltaTime);
         entity->rotateZ(9.5f * deltaTime);
       }
     }
  };

  void AnotherScene::onKeyUp(SDL_Keycode key) {
    if (key == SDLK_1) {
      this->app->getSceneManager()->setCurrentScene<Scenes::TestScene>();
    }
  }


  AnotherScene::~AnotherScene() {}
}