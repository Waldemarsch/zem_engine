//
// Created by val on 16/01/2026.
//

#pragma once

#include <memory>

#include "buffer_layout.h"

namespace zem::graphics {
class VertexBuffer {
 public:
  virtual ~VertexBuffer() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  static std::shared_ptr<VertexBuffer> Create(const void* vertices,
                                              uint32_t size);

  [[nodiscard]] virtual const BufferLayout& layout() const = 0;
  virtual void set_layout(const BufferLayout& layout) = 0;

};
}  // namespace zem::graphics
