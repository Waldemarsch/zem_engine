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

core::BodyHandle PhysicsWorld::CreateBody(const math::Vector3& position,
                                          math::Real mass) {

}

}  // namespace zem::physics