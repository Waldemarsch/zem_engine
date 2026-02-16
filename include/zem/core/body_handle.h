//
// Created by val on 16/02/2026.
//

#ifndef OPENGLTRAIN_BODY_HANDLE_H
#define OPENGLTRAIN_BODY_HANDLE_H
#include <cstdint>

namespace zem::core {
class BodyHandle {
 public:
  BodyHandle() : id_(0) {}

  BodyHandle(uint16_t index, uint16_t generation) {
    id_ = (static_cast<uint32_t>(generation) << 16) | index;
  }

  [[nodiscard]] uint16_t index() const { return id_ & 0xFFFF; }

  [[nodiscard]] uint16_t generation() const { return (id_ >> 16) & 0xFFFF; }

  bool operator==(const BodyHandle& other) const { return id_ == other.id_; }

  bool operator!=(const BodyHandle& other) const { return id_ != other.id_; }

  [[nodiscard]] bool IsValid() const { return id_ != 0; }

 private:
  uint32_t id_;
};
}  // namespace zem_core

#endif  // OPENGLTRAIN_BODY_HANDLE_H
