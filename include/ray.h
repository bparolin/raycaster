#ifndef RAY_H_GUARD
#define RAY_H_GUARD

#include "vec3f.h"

class Ray {
public:
    Ray(const Vec3f& origin, const Vec3f& direction);
    Vec3f getOrigin() const;
    Vec3f getDirection() const;

private:
    Vec3f origin_;
    Vec3f direction_;
};

#endif // RAY_H_GUARD
