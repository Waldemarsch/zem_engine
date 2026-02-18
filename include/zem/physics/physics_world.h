//
// Created by Владимир on 16.02.2026.
//

#ifndef OPENGLTRAIN_PHYSICS_WORLD_H
#define OPENGLTRAIN_PHYSICS_WORLD_H
#include <memory>

#include "zem/core/body_handle.h"
#include "zem/math/precision.h"
#include "zem/math/vector3.h"

namespace zem::physics {
namespace internal {
struct PhysicsData;
}

class PhysicsWorld {
 public:
  PhysicsWorld();
  ~PhysicsWorld();

  PhysicsWorld(const PhysicsWorld&) = delete;
  PhysicsWorld& operator=(const PhysicsWorld&) = delete;

  PhysicsWorld(PhysicsWorld&&) noexcept;
  PhysicsWorld& operator=(PhysicsWorld&&) noexcept;

  [[nodiscard]] core::BodyHandle CreateBody(
      math::Real mass, const math::Vector3& position);

  void DestroyBody(core::BodyHandle handle);

  [[nodiscard]] math::Vector3 GetPosition(core::BodyHandle handle) const;

  void Step(math::Real delta_time);

 private:
  std::unique_ptr<internal::PhysicsData> physics_data_;
};
}  // namespace zem::physics

#endif  // OPENGLTRAIN_PHYSICS_WORLD_H
