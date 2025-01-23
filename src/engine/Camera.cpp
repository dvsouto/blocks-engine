#include "include/engine/Camera.h"
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

  void Camera::updateView(const Vector3f& playerPosition, const Vector3f& offset, const Vector3f& targetOffset, const Vector3f& up) {
    const Vector3f eye = playerPosition + offset;
    const Vector3f target = playerPosition + targetOffset;

    // const auto eye = Vector3f(playerPosition.x() + offset.x(), playerPosition.y() + offset.y(), playerPosition.z() + offset.z());
    // const auto target = Vector3f(playerPosition.x() + targetOffset.x(), playerPosition.y() + targetOffset.y(), playerPosition.z() + targetOffset.z);

    this->setView(eye, target, up);
  }

  void Camera::applyView() const {
    bgfx::setViewTransform(0, this->viewMatrix, this->projectionMatrix);
  }
}