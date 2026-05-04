//
// Created by val on 16/01/2026.
//

#pragma once

#include <vector>

namespace zem::graphics {
class VertexBuffer {
 public:
  virtual ~VertexBuffer() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;
};
}  // namespace zem::graphics
