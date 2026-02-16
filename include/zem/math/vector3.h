//
// Created by val on 29/01/2026.
//

#ifndef OPENGLTRAIN_VECTOR3_H
#define OPENGLTRAIN_VECTOR3_H

#include <cmath>

#include "precision.h"

namespace zem::math {
struct Vector3 {
  Real x, y, z;

  constexpr Vector3() = default;

  constexpr Vector3(Real x, Real y, Real z) : x(x), y(y), z(z) {}

  constexpr Vector3& operator+=(const Vector3& right);
  constexpr Vector3& operator-=(const Vector3& right);
  constexpr Vector3& operator*=(Real right);
  constexpr Vector3& operator/=(Real right);

  [[nodiscard]] static constexpr Real Dot(const Vector3& left,
                                          const Vector3& right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
  }

  [[nodiscard]] constexpr Real Dot(const Vector3& right) const {
    return x * right.x + y * right.y + z * right.z;
  }

  [[nodiscard]] static constexpr Vector3 Cross(const Vector3& left,
                                               const Vector3& right);

  [[nodiscard]] constexpr Vector3 Cross(const Vector3& right) const;

  [[nodiscard]] Real Length() const { return std::sqrt(LengthSquared()); }

  [[nodiscard]] constexpr Real LengthSquared() const {
    return x * x + y * y + z * z;
  }

  [[nodiscard]] Vector3 Normalized() const;
};

constexpr Vector3& Vector3::operator+=(const Vector3& right) {
  x += right.x;
  y += right.y;
  z += right.z;
  return *this;
}

constexpr Vector3& Vector3::operator-=(const Vector3& right) {
  x -= right.x;
  y -= right.y;
  z -= right.z;
  return *this;
}

constexpr Vector3& Vector3::operator*=(Real right) {
  x *= right;
  y *= right;
  z *= right;
  return *this;
}

constexpr Vector3& Vector3::operator/=(Real right) {
  Real inverted_right = static_cast<Real>(1.0) / right;
  x *= inverted_right;
  y *= inverted_right;
  z *= inverted_right;
  return *this;
}

constexpr Vector3 Vector3::Cross(const Vector3& left, const Vector3& right) {
  return {left.y * right.z - left.z * right.y,
          left.z * right.x - left.x * right.z,
          left.x * right.y - left.y * right.x};
}

constexpr Vector3 Vector3::Cross(const Vector3& right) const {
  return {y * right.z - z * right.y,
          z * right.x - x * right.z,
          x * right.y - y * right.x};
}

inline Vector3 Vector3::Normalized() const {
  Real length_squared = LengthSquared();
  if (length_squared < 1e-6) {
    return {0, 0, 0};
  }

  Real inverted_length = static_cast<Real>(1.0) / std::sqrt(length_squared);
  return {x * inverted_length, y * inverted_length, z * inverted_length};
}

constexpr Vector3 operator+(Vector3 left, const Vector3& right) {
  left += right;
  return left;
}

constexpr Vector3 operator-(Vector3 left, const Vector3& right) {
  left -= right;
  return left;
}

constexpr Vector3 operator*(Vector3 left, Real right) { return left *= right; }

constexpr Vector3 operator*(Real left, Vector3 right) { return right *= left; }

constexpr Vector3 operator/(Vector3 left, Real right) { return left /= right; }
}  // namespace zem_math

#endif  // OPENGLTRAIN_VECTOR3_H
