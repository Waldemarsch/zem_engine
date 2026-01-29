//
// Created by val on 29/01/2026.
//

#ifndef OPENGLTRAIN_CORE_H
#define OPENGLTRAIN_CORE_H
#include "precision.h"

namespace zem_math {
class Vector3 {
 public:
  Vector3() : x_(0), y_(0), z_(0) {}

  Vector3(Real x, Real y, Real z) : x_(x), y_(y), z_(z) {}



 private:
  Real x_, y_, z_;
};
}  // namespace zem

#endif  // OPENGLTRAIN_CORE_H
