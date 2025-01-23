#pragma once

#include <Eigen/Dense>
#include <bgfx/bgfx.h>

using Eigen::Matrix4f;
using Eigen::Vector3;

namespace Engine {
  struct Movable {
    void setPosition(const Vector3<float> &newPosition);
    void setRotation(const Vector3<float> &newRotation);

    void move(const Vector3<float> &move);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void rotate(const Vector3<float> &rotate);
    void rotateX(float x);
    void rotateY(float y);
    void rotateZ(float z);


    Vector3<float> getPosition();
    Vector3<float> getRotation();

  protected:
    Vector3<float> position = Vector3<float>(0.f, 0.f, 0.f);
    Vector3<float> rotation = Vector3<float>(0.f, 0.f, 0.f);

    Matrix4f getTransformMatrix();
    std::array<float, 16> getTransformArray();
  };
}