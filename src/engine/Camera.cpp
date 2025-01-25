#include "include/engine/Camera.h"

#include <iostream>

#include "include/layers/Views.h"

#include <bx/math.h>
#include <bgfx/bgfx.h>

#include <Eigen/Dense>

using Eigen::Vector3f;

namespace Engine {
  Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane) : fov(fov), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane),
  viewMatrix{}, projectionMatrix{} {
    this->viewId = Layers::VIEW_CAMERA;

    bx::mtxProj(this->projectionMatrix,
      this->fov,
      this->aspectRatio,
      this->nearPlane,
      this->farPlane,
      bgfx::getCaps()->homogeneousDepth);
  };

  void Camera::setView(const Vector3f &eye, const Vector3f &target, const Vector3f &up) {
    bx::mtxLookAt(this->viewMatrix,
      {eye.x(), eye.y(), eye.z()},
      {target.x(), target.y(), target.z() },
      {up.x(), up.y(), up.z()});
  }

  void Camera::updateView(const Vector3f& playerPosition, const Vector3f& playerRotation, const Vector3f& offset, const Vector3f& up) {
    bx::Vec3 front{0.0f};

    // front.x = cos(bx::toRad(playerRotation.y())) * cos(bx::toRad(playerRotation.x()));
    // front.y = sin(bx::toRad(playerRotation.x()));
    // front.z = sin(bx::toRad(playerRotation.y())) * cos(bx::toRad(playerRotation.x()));
    front.x = sin(bx::toRad(playerRotation.y())) * cos(bx::toRad(playerRotation.x()));
    front.y = sin(bx::toRad(playerRotation.x()));
    front.z = cos(bx::toRad(playerRotation.y())) * cos(bx::toRad(playerRotation.x()));

    bx::Vec3 directionBx = bx::normalize(front);
    Vector3f direction{ directionBx.x, directionBx.y, directionBx.z };

    const Vector3f eye = playerPosition + offset;
    const Vector3f target = eye + direction;

    this->setView(eye, target, up);
  }

  void Camera::applyView() const {
    bgfx::setViewTransform(0, this->viewMatrix, this->projectionMatrix);
  }
}