
#include "quad.h"

Quad::Quad() {}

Quad::Quad(const Vec3f& v1, const Vec3f& v2, const Vec3f& v3, const Vec3f& v4) {
    edges_[0] = v1;
    edges_[1] = v2;
    edges_[2] = v3;
    edges_[3] = v4;
    calculateNormal();
}

void Quad::calculateNormal() {
    Vec3f U = edges_[1] - edges_[0];
    Vec3f V = edges_[3] - edges_[0];
    normal_ = U ^ V;
}

bool Quad::intersect(const Ray& ray, Vec3f& inter) const {
  if (!intersectPlane(ray, inter)) {
    return false;
  }

  if (intersectTriangle(ray, inter, edges_[0], edges_[1], edges_[2])
   || intersectTriangle(ray, inter, edges_[0], edges_[2], edges_[3])) {
    return true;
  } else {
    return false;
  }
}

bool Quad::intersectPlane(const Ray& ray, Vec3f& inter) const {
  float distance = normal_ * edges_[0];

  float nd = ray.getDirection() * normal_;
  float pn = ray.getOrigin() * normal_;

  // nd must be negative, and not 0
  // if nd is positive, the ray and plane normals
  /* point in the same direction. No intersection.
  if (nd >= 0.0f) {
    return false;
  }
*/
  float t = (distance - pn) / nd;

  // t must be positive
  if (t >= 0.0f) {
    inter = ray.getOrigin() + ray.getDirection() * t;
    return true;
  }

  return false;
}

bool Quad::intersectTriangle(const Ray& ray, const Vec3f& inter, const Vec3f& a, const Vec3f& b, const Vec3f& c) const {
  Vec3f ai = inter - a;
  Vec3f bi = inter - b;
  Vec3f ci = inter - c;

  Vec3f ab = b - a;
  Vec3f cb = b - c;
  Vec3f v = ab - ab.project(cb);
  float baryA = 1.0f - ((v* ai) / (v * ab));

  Vec3f bc = c - b;
  Vec3f ac = c - a;
  v = bc - bc.project(ac);
  float baryB = 1.0f - ((v * bi) / (v * bc));

  Vec3f ca = a - c;
  v = ca - ca.project(ab);
  float baryC = 1.0f - ((v * ci) / (v * ca));

  // Check if inter is in ABC Triangle with barycentric coordinates
  if (baryA >= 0.0f && baryA <= 1.0f
   && baryB >= 0.0f && baryB <= 1.0f
   && baryC >= 0.0f && baryC <= 1.0f) {
    return true;
  } else {
    return false;
  }
}

