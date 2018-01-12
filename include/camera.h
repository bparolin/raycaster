#ifndef CAMERA_H_GUARD
#define CAMERA_H_GUARD

#include "vec3f.h"

class Camera {
public:
  Camera();
  void init(Vec3f position);
  Vec3f getPosition();

private:
  Vec3f position_;
  Vec3f up_;
  Vec3f front_;
};

#endif // CAMERA_H_GUARD
