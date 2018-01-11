#ifndef VEC3F_H_GUARD
#define VEC3F_H_GUARD

#include <cmath>
#include <iostream>

#define EPSILON 0.00001

class Vec3f {
public:
    Vec3f();
    Vec3f(float x, float y, float z);
    Vec3f operator-(const Vec3f& v) const;
    Vec3f operator+(const Vec3f& v) const;
    Vec3f operator^(const Vec3f& v) const;
    double operator*(const Vec3f& v) const;
    Vec3f operator*(const float s) const;
    Vec3f operator/(const float s) const;
    Vec3f& operator=(const Vec3f& v);
    bool operator>=(const float s) const;
    bool operator<=(const float s) const;
    friend std::ostream& operator<<(std::ostream& os, const Vec3f& v);
    Vec3f project(Vec3f v) const;
    const float& x() const;
    const float& y() const;
    const float& z() const;

private:
    float x_, y_, z_;
};

#endif // VEC3F_H_GUARD
