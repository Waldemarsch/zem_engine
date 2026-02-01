//
// Created by val on 29/01/2026.
//

#ifndef OPENGLTRAIN_CORE_H
#define OPENGLTRAIN_CORE_H
#include "precision.h"

namespace zem_math {
class Vector3 {
 public:
  constexpr Vector3() : x_(0), y_(0), z_(0) {}

  constexpr Vector3(Real x, Real y, Real z) : x_(x), y_(y), z_(z) {}

  constexpr Vector3& operator+=(const Vector3& right);
  constexpr Vector3& operator-=(const Vector3& right);
  constexpr Vector3& operator*=(Real right);

  static constexpr Real Dot(const Vector3& left, const Vector3& right) {
    return left.x_ * right.x_ + left.y_ * right.y_ + left.z_ * right.z_;
  }

  constexpr Real Dot(const Vector3& right) const {
    return x_ * right.x_ + y_ * right.y_ + z_ * right.z_;
  }

  static constexpr Vector3 Cross(const Vector3& left, const Vector3& right);
  constexpr Vector3 Cross(const Vector3& right) const;

  Real x() const { return x_; }

 private:
  Real x_, y_, z_;
};

constexpr Vector3& Vector3::operator+=(const Vector3& right) {
  x_ += right.x_;
  y_ += right.y_;
  z_ += right.z_;
  return *this;
}

constexpr Vector3& Vector3::operator-=(const Vector3& right) {
  x_ -= right.x_;
  y_ -= right.y_;
  z_ -= right.z_;
  return *this;
}

constexpr Vector3& Vector3::operator*=(Real right) {
  x_ *= right;
  y_ += right;
  z_ += right;
  return *this;
}

constexpr Vector3 Vector3::Cross(const Vector3& left, const Vector3& right) {
  return Vector3(left.y_ * right.z_ - left.z_ * right.y_,
                 left.z_ * right.x_ - left.x_ * right.z_,
                 left.x_ * right.y_ - left.y_ * right.x_);
}

constexpr Vector3 Vector3::Cross(const Vector3& right) const {
  return Vector3(y_ * right.z_ - z_ * right.y_,
                 z_ * right.x_ - x_ * right.z_,
                 x_ * right.y_ - y_ * right.x_);
}

constexpr Vector3 operator+(Vector3 left, const Vector3& right) {
  left += right;
  return left;
}

constexpr Vector3 operator-(Vector3 left, const Vector3& right) {
  left -= right;
  return left;
}
}  // namespace zem_math

#endif  // OPENGLTRAIN_CORE_H
