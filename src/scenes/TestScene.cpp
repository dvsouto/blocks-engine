#include "include/scenes/TestScene.h"

#include <include/core/ShaderManager.h>
#include <include/core/EntityManager.h>

#include "include/graphics/Scene.h"

#include "include/engine/Player.h"

#include "include/layers/MeshLayer.h"
#include "include/layers/UILayer.h"

#include "include/primitive/Cube.h"
#include "include/primitive/Plane.h"

#include <include/core/Mouse.h>
#include <iostream>

using namespace Engine;
using namespace Graphics;
using namespace Primitive;
using namespace Layers;

using namespace std;

namespace Scenes {
  void TestScene::init() {
    cout << "TestScene::init()" << endl;

    this->layers->create<MeshLayer>();
    this->layers->create<UILayer>();

    this->player = std::make_shared<Player>();

    auto cube = std::make_shared<Cube>();
    auto anotherCube = std::make_shared<Cube>();
    auto plane = std::make_shared<Plane>();

    plane->setScale({ 10.f, 10.f, 10.f });

    cube->moveX(1.5f);
    cube->moveY(2.5f);
    cube->moveZ(3.5f);

    anotherCube->moveY(0.5f);

    // anotherCube->moveX(-2.5f);
    // anotherCube->moveY(-5.f);
    // anotherCube->moveZ(-7.5f);

    this->layers->use<MeshLayer>()->entities->add(this->player);
    this->layers->use<MeshLayer>()->entities->add(cube);
    this->layers->use<MeshLayer>()->entities->add(anotherCube);
    this->layers->use<MeshLayer>()->entities->add(plane);

    this->app->getMouse()->hide();
  };

  void TestScene::load() {
    Scene::load();
  }

  void TestScene::update(float deltaTime) {
    // for (const auto& entity : *this->layers->use<MeshLayer>()->entities->all()) {
    //   if (entity->isRenderable()) {
    //     entity->rotateX(7.5f * deltaTime);
    //     entity->rotateY(8.5f * deltaTime);
    //     entity->rotateZ(9.5f * deltaTime);
    //   }
    // }
  };

  void TestScene::onKeyUp(SDL_Keycode key) {
    if (key == SDLK_ESCAPE) {
      this->app->getMouse()->toggleVisibility();
    }
  }


  TestScene::~TestScene() {}
}