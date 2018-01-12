#ifndef QUAD_H_GUARD
#define QUAD_H_GUARD

#include "vec3f.h"
#include "ray.h"

class Quad {
public:
    Quad();
    Quad(const Vec3f& e1, const Vec3f& e2, const Vec3f& e3, const Vec3f& e4);
    void calculateNormal();
    Vec3f getNormal();
    bool intersect(const Ray& ray, Vec3f& inter) const;
    bool intersectPlane(const Ray& ray, Vec3f& inter) const;
    bool intersectTriangle(const Ray& ray, const Vec3f& inter, const Vec3f& a, const Vec3f& b, const Vec3f& c) const;

private:
    Vec3f edges_[4];
    Vec3f normal_;
};

#endif // QUAD_H_GUARD
