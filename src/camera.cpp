
#include "camera.h"

Camera::Camera() : up_(Vec3f(0, 1, 0)), front_(Vec3f(0, 0, 1)) { }

void Camera::init(Vec3f position) {
  position_ = position;
}

Vec3f Camera::getPosition() {
  return position_;
}
