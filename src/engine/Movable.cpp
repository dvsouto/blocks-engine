#include "include/engine/Movable.h"

#include <Eigen/Dense>

using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3;

namespace Engine {
  void Movable::setPosition(const Vector3<float> &newPosition) {
    this->position = newPosition;
  }

  void Movable::setRotation(const Vector3<float> &newRotation) {
    this->rotation = newRotation;
  }

  void Movable::move(const Vector3<float> &move) {
    this->position += move;
  }

  void Movable::moveX(float x) {
    this->position[0] += x;
  }

  void Movable::moveY(float y) {
    this->position[1] += y;
  }

  void Movable::moveZ(float z) {
    this->position[2] += z;
  }

  void Movable::rotate(const Vector3<float> &rotate) {
    this->rotation += rotate;
  }

  void Movable::rotateX(float x) {
    this->rotation[0] += x;
  }

  void Movable::rotateY(float y) {
    this->rotation[1] += y;
  }

  void Movable::rotateZ(float z) {
    this->rotation[2] += z;
  }

  Vector3<float> Movable::getPosition() {
    return this->position;
  }

  Matrix4f Movable::getTransformMatrix() {
    Matrix4f transformMatrix = Matrix4f::Identity();

    // Convert to euler angles
    float radianX = this->rotation.x() * M_PI / 180.0f;
    float radianY = this->rotation.y() * M_PI / 180.0f;
    float radianZ = this->rotation.z() * M_PI / 180.0f;

    // Euler angles rotation
    Matrix3f rotationX = Eigen::AngleAxisf(radianX, Eigen::Vector3f::UnitX()).toRotationMatrix();
    Matrix3f rotationY = Eigen::AngleAxisf(radianY, Eigen::Vector3f::UnitY()).toRotationMatrix();
    Matrix3f rotationZ = Eigen::AngleAxisf(radianZ, Eigen::Vector3f::UnitZ()).toRotationMatrix();
    Matrix3f rotationMatrix = rotationZ * rotationY * rotationX;

    // Rotation
    transformMatrix.block<3, 3>(0, 0) = rotationMatrix;

    // Position
    transformMatrix.block<3, 1>(0, 3) = -position;
    // transformMatrix(0, 3) = -position.x();
    // transformMatrix(1, 3) = -position.y();
    // transformMatrix(2, 3) = -position.z();

    return transformMatrix;
  }

  std::array<float, 16> Movable::getTransformArray() {
    Matrix4f transformMatrix = getTransformMatrix();

    float transformArr[16];
    std::array<float, 16> transformStdArr;

    Eigen::Map<Matrix4f>(transformArr, 4, 4) = transformMatrix;

    std::copy(std::begin(transformArr), std::end(transformArr), transformStdArr.begin());

    return transformStdArr;
  }
}