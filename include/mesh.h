#ifndef MESH_H_GUARD
#define MESH_H_GUARD

#include <vector>

#include "quad.h"

class Mesh {
public:
  Mesh(Vec3f color);
  void addFace(Quad face);
  std::vector<Quad> getFaces();
  Vec3f getColor();

private:
  std::vector<Quad> faces_;
  Vec3f color_;

};

#endif // MESH_H_GUARD
