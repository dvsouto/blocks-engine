#pragma once

#include <Eigen/Dense>
#include <bx/math.h>

using Eigen::Vector3f;

namespace Engine {
  class Camera {
    public:
      Camera(float fov, float aspectRatio, float nearPlane, float farPlane);

      void setView(const Vector3f &eye, const Vector3f &target, const Vector3f &up = {0.0f, 1.0f, 0.0f});
      void updateView(const Vector3f& playerPosition, const Vector3f& offset, const Vector3f& targetOffset = {0.0f, -1.0f, -1.0f}, const Vector3f& up = {0.0f, 1.0f, 0.0f});
      void applyView() const;
    private:
      float fov, aspectRatio, nearPlane, farPlane;
      uint8_t viewId;

      float viewMatrix[16];
      float projectionMatrix[16];
  };
}