#ifndef SCENE_H_GUARD
#define SCENE_H_GUARD

#include <fstream>

#include "ray.h"
#include "quad.h"

class Scene {
public:
  Scene(int screenWidth, int screenHeight, Vec3f screenLeftDown, Vec3f eyeOrigin, Vec3f lightPosition = Vec3f(100, 100, 100));
  ~Scene();
  void init();
  void draw();

private:
  Quad* mesh_;
  Vec3f light_;
  Vec3f camera_;
  Vec3f screenLeftDown_;
  int screenWidth_;
  int screenHeight_;
};

#endif // SCENE_H_GUARD
