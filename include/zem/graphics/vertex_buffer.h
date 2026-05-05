//
// Created by val on 16/01/2026.
//

#pragma once

#include <memory>

namespace zem::graphics {
class VertexBuffer {
 public:
  virtual ~VertexBuffer() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  static std::shared_ptr<VertexBuffer> Create(const void* vertices,
                                              uint32_t size);
};
}  // namespace zem::graphics
