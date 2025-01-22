#include "include/graphics/Renderable.h"
#include <include/graphics/ShaderProgram.h>
#include "include/primitive/VertexColor.h"

#include <Eigen/Dense>
#include <bgfx/bgfx.h>
#include <iostream>

using Eigen::Matrix4f;
using Eigen::Matrix4f;

namespace Graphics {
  Renderable::Renderable(uint8_t viewId, const std::vector<Primitive::VertexColor> &vertices, const std::vector<uint16_t>& indices, Graphics::ShaderProgram& shaderProgram) :
    viewId(viewId), vertices(vertices), indices(indices), shaderProgram(shaderProgram), vertexBuffer(BGFX_INVALID_HANDLE), indexBuffer(BGFX_INVALID_HANDLE) {
  }

  bool Renderable::isInitialized(){
    return initialized;
  };

  void Renderable::setPosition(Vector3<float> position) {
    this->position = position;
  }

  void Renderable::setRotation(Vector3<float> rotation) {
    this->rotation = rotation;
  }

  void Renderable::move(Vector3<float> move) {
    this->position += move;
  }

  void Renderable::moveX(float x) {
    this->position[0] += x;
  }

  void Renderable::moveY(float y) {
    this->position[1] += y;
  }

  void Renderable::moveZ(float z) {
    this->position[2] += z;
  }

  void Renderable::rotate(Vector3<float> rotate) {
    this->rotation += rotate;
  }

  void Renderable::rotateX(float x) {
    this->rotation[0] += x;
  }

  void Renderable::rotateY(float y) {
    this->rotation[1] += y;
  }

  void Renderable::rotateZ(float z) {
    this->rotation[2] += z;
  }


  Vector3<float> Renderable::getPosition() {
    return this->position;
  }


  bool Renderable::validateDraw() {
    if (! initialized) {
      std::cerr << "Mesh not initialized in Mesh::draw!";
      return false;
    }

    if (!bgfx::isValid(this->shaderProgram.get())) {
      std::cerr << "Error: Invalid shader program handle in Mesh::draw!" << std::endl;
      return false;
    }

    if (!bgfx::isValid(this->vertexBuffer) || !bgfx::isValid(this->indexBuffer)) {
      std::cerr << "Error: Invalid vertex/index shader in Mesh::draw!" << std::endl;
      return false;
    }

    return true;
  }

  void Renderable::submitDraw() const {
    bgfx::submit(this->viewId, this->shaderProgram.get());
  }

  Matrix4f Renderable::getTransformMatrix() {
    Matrix4f transformMatrix = Matrix4f::Identity();

    // Convert to euler angles
    float radianX = this->rotation.x() * M_PI / 180.0f;
    float radianY = this->rotation.y() * M_PI / 180.0f;
    float radianZ = this->rotation.z() * M_PI / 180.0f;

    // Euler angles rotation
    Eigen::Matrix3f rotationX = Eigen::AngleAxisf(radianX, Eigen::Vector3f::UnitX()).toRotationMatrix();
    Eigen::Matrix3f rotationY = Eigen::AngleAxisf(radianY, Eigen::Vector3f::UnitY()).toRotationMatrix();
    Eigen::Matrix3f rotationZ = Eigen::AngleAxisf(radianZ, Eigen::Vector3f::UnitZ()).toRotationMatrix();
    Eigen::Matrix3f rotationMatrix = rotationZ * rotationY * rotationX;

    // Rotation
    transformMatrix.block<3, 3>(0, 0) = rotationMatrix;

    // Position
    transformMatrix.block<3, 1>(0, 3) = -position;
    // transformMatrix(0, 3) = -position.x();
    // transformMatrix(1, 3) = -position.y();
    // transformMatrix(2, 3) = -position.z();

    return transformMatrix;
  }

  std::array<float, 16> Renderable::getTransformArray() {
    Matrix4f transformMatrix = getTransformMatrix();

    float transformArr[16];
    std::array<float, 16> transformStdArr;

    Eigen::Map<Eigen::Matrix4f>(transformArr, 4, 4) = transformMatrix;

    std::copy(std::begin(transformArr), std::end(transformArr), transformStdArr.begin());

    return transformStdArr;
  }
}