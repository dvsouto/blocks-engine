#include "include/scenes/TestScene.h"
#include "include/graphics/Scene.h"

#include "include/graphics/Shader.h"
#include "include/graphics/ShaderProgram.h"

#include "include/layers/MeshLayer.h"
#include "include/layers/UILayer.h"

#include "include/primitive/VertexColor.h"
#include "include/primitive/Mesh.h"

#include <iostream>

using namespace Graphics;

namespace Scenes {
  void TestScene::init() {
    std::cout << "TestScene::init()" << std::endl;

    auto meshLayer = std::make_shared<Layers::MeshLayer>();
    auto uiLayer = std::make_shared<Layers::UILayer>();

    this->layers.addLayer<Layers::MeshLayer>(meshLayer);
    this->layers.addLayer<Layers::UILayer>(uiLayer);

    auto vertexColorShader = Shader("vertex_color");
    auto fragmentColorShader = Shader("fragment_color");

    auto shaderProgram = new ShaderProgram(vertexColorShader, fragmentColorShader);

    auto meshSquare = std::make_shared<Primitive::Mesh>(Primitive::Mesh(0, {
      {  0.5f,  0.5f, 0.0f  }, // Top-right
      {  0.5f, -0.5f, 0.0f  }, // Bottom-right
      { -0.5f, -0.5f, 0.0f }, // Bottom-left
      { -0.5f,  0.5f, 0.0f }  // Top-left
    }, {
      0,1,3,
      1,2,3
    }, *shaderProgram));

    auto meshCube = std::make_shared<Primitive::Mesh>(Primitive::Mesh(0, {
      // Front face
    {  0.5f,  0.5f,  0.5f }, // Top-right-front
    {  0.5f, -0.5f,  0.5f }, // Bottom-right-front
    { -0.5f, -0.5f,  0.5f }, // Bottom-left-front
    { -0.5f,  0.5f,  0.5f }, // Top-left-front

     // Back face
    {  0.5f,  0.5f, -0.5f }, // Top-right-back
    {  0.5f, -0.5f, -0.5f }, // Bottom-right-back
    { -0.5f, -0.5f, -0.5f }, // Bottom-left-back
    { -0.5f,  0.5f, -0.5f }  // Top-left-back
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
    }, *shaderProgram));

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
    // std::cout << "TestScene::update() - " << deltaTime << std::endl;
  };

  TestScene::~TestScene() {}
}