
#include "mesh.h"

Mesh::Mesh(Vec3f color) : color_(color) { }

void Mesh::addFace(Quad face) {
  faces_.push_back(face);
}

std::vector<Quad> Mesh::getFaces() {
  return faces_;
}

Vec3f Mesh::getColor() {
  return color_;
}

