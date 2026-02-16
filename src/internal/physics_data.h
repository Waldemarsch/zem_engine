//
// Created by Владимир on 16.02.2026.
//

#ifndef OPENGLTRAIN_PHYSICS_DATA_H
#define OPENGLTRAIN_PHYSICS_DATA_H
#include <cstdint>
#include <vector>

#include "zem/math/precision.h"
#include "zem/math/vector3.h"

namespace zem::physics::internal {
struct PhysicsData {
  std::vector<zem::math::Vector3> positions;
  std::vector<zem::math::Vector3> velocities;
  std::vector<zem::math::Real> inverse_masses;
  std::vector<uint16_t> generations;
  std::vector<uint16_t> free_indices;
};
}  // namespace zem::physics::internal

#endif  // OPENGLTRAIN_PHYSICS_DATA_H
