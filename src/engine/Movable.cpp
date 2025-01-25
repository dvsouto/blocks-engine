#include "include/engine/Movable.h"

#include <Eigen/Dense>
#include <iostream>
#include <bx/math.h>

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

  void Movable::setScale(const Vector3<float> &newScale) {
    this->scale = newScale;
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

  Vector3<float>& Movable::getPosition() {
    return this->position;
  }

  Vector3<float>& Movable::getRotation() {
    return this->rotation;
  }

  Vector3<float>& Movable::getScale() {
    return this->scale;
  }

  Eigen::Transform<float, 3, Eigen::Affine> Movable::getTransform() {
    Eigen::Transform<float, 3, Eigen::Affine> transform = Eigen::Transform<float, 3, Eigen::Affine>::Identity();;

    transform.translate(this->position);
    transform.rotate(this->getRotationMatrix());
    transform.scale(this->scale);

    return transform;
  }

  // Calc forward vector
  Vector3<float> Movable::forward() const {
    // bx::Vec3 bxForward(
    //     sin(bx::toRad(rotation.y())) * cos(bx::toRad(rotation.x())), // X
    //     sin(bx::toRad(rotation.x())),                                        // Y
    //     cos(bx::toRad(rotation.y())) * cos(bx::toRad(rotation.x()))  // Z
    // );

    return {
      sin(bx::toRad(rotation.y())), // X
      0.0f,                                 // Y (ignore vertical)
      cos(bx::toRad(rotation.y()))  // Z
    };
  }

  Vector3<float> Movable::back() const {
    return -this->forward();
  }

  Vector3<float> Movable::left() const {
    return -this->right();
  }

  Vector3<float> Movable::right() const {
    return {
      cos(bx::toRad(rotation.y())), // X
      0.0f,                                 // Y (always zero to horizontal movements)
      -sin(bx::toRad(rotation.y())) // Z
    };
  }


  Matrix4f Movable::getTransformMatrix() {
    return this->getTransform().matrix();
  }

  Matrix3f Movable::getRotationMatrix() {
    // Convert to euler angles
    const float radianX = this->rotation.x() * M_PI / 180.0f;
    const float radianY = this->rotation.y() * M_PI / 180.0f;
    const float radianZ = this->rotation.z() * M_PI / 180.0f;

    // Euler angles rotation
    Matrix3f rotationX = Eigen::AngleAxisf(radianX, Eigen::Vector3f::UnitX()).toRotationMatrix();
    Matrix3f rotationY = Eigen::AngleAxisf(radianY, Eigen::Vector3f::UnitY()).toRotationMatrix();
    Matrix3f rotationZ = Eigen::AngleAxisf(radianZ, Eigen::Vector3f::UnitZ()).toRotationMatrix();

    // Create rotation matrix
    Matrix3f rotationMatrix = rotationZ * rotationY * rotationX;

    return rotationMatrix;
  }


  // Matrix4f Movable::getTransformMatrix() {
  //   Matrix4f transformMatrix = Matrix4f::Identity();
  //   // Matrix3f scaleMatrix = Matrix3f::Identity();
  //   Matrix3f rotationMatrix = Matrix3f::Identity();
  //
  //   // Convert to euler angles
  //   float radianX = this->rotation.x() * M_PI / 180.0f;
  //   float radianY = this->rotation.y() * M_PI / 180.0f;
  //   float radianZ = this->rotation.z() * M_PI / 180.0f;
  //
  //   // Euler angles rotation
  //   Matrix3f rotationX = Eigen::AngleAxisf(radianX, Eigen::Vector3f::UnitX()).toRotationMatrix();
  //   Matrix3f rotationY = Eigen::AngleAxisf(radianY, Eigen::Vector3f::UnitY()).toRotationMatrix();
  //   Matrix3f rotationZ = Eigen::AngleAxisf(radianZ, Eigen::Vector3f::UnitZ()).toRotationMatrix();
  //
  //   // Rotation matrix
  //   rotationMatrix = rotationZ * rotationY * rotationX;
  //
  //   // Apply rotation
  //   transformMatrix.block<3, 3>(0, 0) = rotationMatrix;
  //
  //   // Apply translate
  //   transformMatrix.block<3, 1>(0, 3) = position;
  //   // transformMatrix(0, 3) = -position.x();
  //   // transformMatrix(1, 3) = -position.y();
  //   // transformMatrix(2, 3) = -position.z();
  //
  //   std::cout << "Matrix: " << transformMatrix << std::endl;
  //
  //   return transformMatrix;
  // }

  std::array<float, 16> Movable::getTransformArray() {
    Matrix4f transformMatrix = getTransformMatrix();
    std::array<float, 16> transformStdArr;

    for (int i = 0; i < 16; ++i) {
      transformStdArr[i] = transformMatrix.data()[i];
    }

    return transformStdArr;
  }
}