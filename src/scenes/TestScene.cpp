#include "include/scenes/TestScene.h"

#include <include/core/ShaderManager.h>

#include "include/graphics/Scene.h"

#include "include/engine/Player.h"

#include "include/layers/MeshLayer.h"
#include "include/layers/UILayer.h"

#include <include/shaders/ColorShader.h>

#include "include/primitive/VertexColor.h"
#include "include/primitive/Mesh.h"
#include <include/primitive/Color.h>


#include <iostream>

using namespace Engine;
using namespace Graphics;
using namespace Primitive;
using namespace Layers;

using namespace std;

namespace Scenes {
  void TestScene::init() {
    cout << "TestScene::init()" << endl;

    this->player = std::make_shared<Player>();

    auto meshLayer = make_shared<MeshLayer>();
    auto uiLayer = make_shared<UILayer>();

    this->layers.addLayer<MeshLayer>(meshLayer);
    this->layers.addLayer<UILayer>(uiLayer);

    auto meshSquare = make_shared<Mesh>(Mesh(0, {
      {  0.5f,  0.5f, 0.0f  }, // Top-right
      {  0.5f, -0.5f, 0.0f  }, // Bottom-right
      { -0.5f, -0.5f, 0.0f }, // Bottom-left
      { -0.5f,  0.5f, 0.0f }  // Top-left
    }, {
      0,1,3,
      1,2,3
    }, this->shaders->use<Shaders::ColorShader>()));

    auto meshCube = make_shared<Mesh>(Mesh(0, {
      // Front face
    {  0.5f,  0.5f,  0.5f, Color(0, 0, 255 ) }, // Top-right-front
    {  0.5f, -0.5f,  0.5f, Color(0, 255, 0 ) }, // Bottom-right-front
    { -0.5f, -0.5f,  0.5f, Color(255, 0, 0 ) }, // Bottom-left-front
    { -0.5f,  0.5f,  0.5f, Color(0, 255, 255 ) }, // Top-left-front

     // Back face
    {  0.5f,  0.5f, -0.5f, Color(0, 0, 255) }, // Top-right-back
    {  0.5f, -0.5f, -0.5f, Color(0, 255, 0 ) }, // Bottom-right-back
    { -0.5f, -0.5f, -0.5f, Color(255, 0, 0 ) }, // Bottom-left-back
    { -0.5f,  0.5f, -0.5f, Color(0, 255, 255 ) }  // Top-left-back
    }, {
      // Front face
      0, 1, 3,
      1, 2, 3,

      // Back face
      4, 5, 7,
      5, 6, 7,

      // Left face
      3, 2, 7,
      2, 6, 7,

      // Right face
      0, 1, 4,
      1, 5, 4,

      // Top face
      0, 3, 4,
      3, 7, 4,

      // Bottom face
      1, 2, 5,
      2, 6, 5
    }, this->shaders->use<Shaders::ColorShader>()));

    meshSquare->initialize();
    meshSquare->move({1.f, 1.f, 1.f });

    meshCube->initialize();
    meshCube->move({-1.f, -1.f, -1.f});
    meshCube->rotate({45.f, 45.f, 45.f});

    meshLayer->add(meshSquare);
    meshLayer->add(meshCube);
  };

  void TestScene::load() {
    Scene::load();
  }

  void TestScene::update(float deltaTime) {
    this->player->update(deltaTime);
    // cout << "TestScene::update() - " << deltaTime << endl;
  };

  TestScene::~TestScene() {}
}