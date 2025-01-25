#pragma once

#include <Eigen/Dense>
#include <bgfx/bgfx.h>

using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3;

namespace Engine {
  struct Movable {
    void setPosition(const Vector3<float> &newPosition);
    void setRotation(const Vector3<float> &newRotation);
    void setScale(const Vector3<float> &newScale);

    void move(const Vector3<float> &move);
    void moveX(float x);
    void moveY(float y);
    void moveZ(float z);

    void rotate(const Vector3<float> &rotate);
    void rotateX(float x);
    void rotateY(float y);
    void rotateZ(float z);

    Vector3<float>& getPosition();
    Vector3<float>& getRotation();
    Vector3<float>& getScale();

    Vector3<float> forward() const;
    Vector3<float> back() const;
    Vector3<float> left() const;
    Vector3<float> right() const;

    Eigen::Transform<float, 3, Eigen::Affine> getTransform();
    Matrix4f getTransformMatrix();
    Matrix3f getRotationMatrix();

    std::array<float, 16> getTransformArray();

  protected:
    Vector3<float> position = Vector3<float>(0.f, 0.f, 0.f);
    Vector3<float> rotation = Vector3<float>(0.f, 0.f, 0.f);
    Vector3<float> scale = Vector3<float>(1.f, 1.f, 1.f);
  };
}