//
// Created by Владимир on 16.02.2026.
//

#include "zem/physics/physics_world.h"

#include "internal/physics_data.h"

namespace zem::physics {

PhysicsWorld::PhysicsWorld() {
  physics_data_ = std::make_unique<internal::PhysicsData>();
}

PhysicsWorld::~PhysicsWorld() = default;

PhysicsWorld::PhysicsWorld(PhysicsWorld&&) noexcept = default;
PhysicsWorld& PhysicsWorld::operator=(PhysicsWorld&&) noexcept = default;

// ReSharper disable once CppMemberFunctionMayBeConst
core::BodyHandle PhysicsWorld::CreateBody(
    math::Real mass, const math::Vector3& position = math::Vector3::Zero()) {
  auto& data = *physics_data_;

  uint16_t index;

  if (!data.free_indices.empty()) {
    index = data.free_indices.back();
    data.free_indices.pop_back();

  } else {
    index = data.positions.size();
    data.positions.push_back(math::Vector3::Zero());
    data.velocities.push_back(math::Vector3::Zero());
    data.inverse_masses.push_back(0);
    data.generations.push_back(0);
  }

  data.positions[index] = position;
  data.inverse_masses[index] =
      mass > 0 ? static_cast<math::Real>(1.0) / mass : 0;
  data.velocities[index] = math::Vector3::Zero();

  return {index, data.generations[index]};
}

// ReSharper disable once CppMemberFunctionMayBeConst
void PhysicsWorld::DestroyBody(core::BodyHandle handle) {
  auto& data = *physics_data_;

  if (!handle.IsValid()) return;
  if (handle.index() >= data.positions.size()) return;

  if (data.generations[handle.index()] != handle.generation()) return;

  data.generations[handle.index()]++;

  data.free_indices.push_back(handle.index());
}

math::Vector3 PhysicsWorld::GetPosition(core::BodyHandle handle) const {
  auto& data = *physics_data_;

  if (!handle.IsValid()) return math::Vector3::Zero();
  if (handle.index() >= data.positions.size()) return math::Vector3::Zero();

  if (data.generations[handle.index()] != handle.generation())
    return math::Vector3::Zero();

  return data.positions[handle.index()];
}

void PhysicsWorld::Step(math::Real delta_time) {

}
}  // namespace zem::physics