#ifndef SCENE_H_GUARD
#define SCENE_H_GUARD

#include <fstream>

#include <GL/glut.h>
#include <GL/glx.h>

#include "ray.h"
#include "quad.h"
#include "mesh.h"
#include "camera.h"

class Scene {
public:
  Scene(int screenWidth, int screenHeight);
  ~Scene();
  void addCube(Vec3f leftDownPos, int size);
  void init();
  bool computeShadow(Ray r, int faceId);
  Vec3f raycast(Ray r, int bounce);
  void draw();

private:
  std::vector<Mesh> meshes_;
  Vec3f light_;
  Camera camera_;
  Vec3f screenLeftDown_;
  int screenWidth_;
  int screenHeight_;
};

#endif // SCENE_H_GUARD
