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

    auto meshLayer = std::make_shared<Layers::MeshLayer>(Layers::MeshLayer());
    auto uiLayer = std::make_shared<Layers::UILayer>(Layers::UILayer());

    this->addLayer(meshLayer);
    this->addLayer(uiLayer);

    auto vertexColorShader = Shader("vertex_color");
    auto fragmentColorShader = Shader("fragment_color");

    auto shaderProgram = new ShaderProgram(vertexColorShader, fragmentColorShader);

    std::vector<Primitive::VertexColor> vertices = {
      {  0.5f,  0.5f, 0.0f  }, // Top-right
      {  0.5f, -0.5f, 0.0f  }, // Bottom-right
      { -0.5f, -0.5f, 0.0f }, // Bottom-left
      { -0.5f,  0.5f, 0.0f }  // Top-left
    };

    auto mesh = std::make_shared<Primitive::Mesh>(Primitive::Mesh(0, vertices, {
      0,1,3,
      1,2,3
    }, *shaderProgram));

    auto mesht = std::make_shared<Primitive::Mesh>(Primitive::Mesh(0, vertices, {
      0,1,3,
      1,2,3
    }, *shaderProgram));

    mesh->initialize();
    mesh->move({1.f, 1.f, 1.f });

    mesht->initialize();
    mesht->move({-1.f, -1.f, -1.f});
    mesht->rotate({45.f, 45.f, 45.f});

    meshLayer->add(mesh);
    meshLayer->add(mesht);
  };

  void TestScene::load() {
    Scene::load();
  }

  TestScene::~TestScene() {}
}