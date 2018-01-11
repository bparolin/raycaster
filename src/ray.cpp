
#include "ray.h"

Ray::Ray(const Vec3f& origin, const Vec3f& direction) : origin_(origin), direction_(direction)
{ }

Vec3f Ray::getOrigin() const {
    return origin_;
}

Vec3f Ray::getDirection() const {
    return direction_;
}
