
#include "vec3f.h"

Vec3f::Vec3f() { }

Vec3f::Vec3f(float x, float y, float z) : x_(x), y_(y), z_(z) { }


Vec3f Vec3f::operator-(const Vec3f& v) const {
  Vec3f res;
  res.x_ = this->x_ - v.x_;
  res.y_ = this->y_ - v.y_;
  res.z_ = this->z_ - v.z_;
  return res;
}

Vec3f Vec3f::operator+(const Vec3f& v) const {
  Vec3f res;
  res.x_ = this->x_ + v.x_;
  res.y_ = this->y_ + v.y_;
  res.z_ = this->z_ + v.z_;
  return res;
}

Vec3f Vec3f::operator^(const Vec3f& v) const {
  Vec3f res;
  res.x_ = this->y_ * v.z_ - this->z_ * v.y_;
  res.y_ = this->z_ * v.x_ - this->x_ * v.z_;
  res.z_ = this->x_ * v.y_ - this->y_ * v.x_;
  return res;
}

double Vec3f::operator*(const Vec3f& v) const {
  double res;
  res = this->x_ * v.x_
      + this->y_ * v.y_
      + this->z_ * v.z_;
  return res;
}

Vec3f Vec3f::operator*(const float s) const {
  Vec3f res;
  res.x_ = this->x_ * s;
  res.y_ = this->y_ * s;
  res.z_ = this->z_ * s;
  return res;
}

Vec3f Vec3f::operator/(const float s) const {
  Vec3f res;
  res.x_ = this->x_ / s;
  res.y_ = this->y_ / s;
  res.z_ = this->z_ / s;
  return res;
}

Vec3f& Vec3f::operator=(const Vec3f& v) {
  this->x_ = v.x_;
  this->y_ = v.y_;
  this->z_ = v.z_;
  return *this;
}

bool Vec3f::operator>=(const float s) const {
  if (this->x_ >= s && this->y_ >= s && this->z_ >= s)
    return true;
  else
    return false;
}

bool Vec3f::operator<=(const float s) const {
  if (this->x_ <= s && this->y_ <= s && this->z_ <= s)
    return true;
  else
    return false;
}

std::ostream& operator<<(std::ostream& os, const Vec3f& v) {
  return os << v.x_ << " " << v.y_ << " " << v.z_;
}

Vec3f Vec3f::project(Vec3f v) const {
  float dot = *this * v;
  float square = v * v;
  return v * (dot / square);
}

const float& Vec3f::x() const {
  return x_;
}

const float& Vec3f::y() const {
  return y_;
}

const float& Vec3f::z() const {
  return z_;
}

