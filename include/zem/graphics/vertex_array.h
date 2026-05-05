//
// Created by val on 22/12/2025.
//

#pragma once

#include <memory>

namespace zem::graphics {
class VertexBuffer;

class VertexArray {
 public:
  virtual ~VertexArray() = default;

  virtual void Bind() const = 0;
  virtual void Unbind() const = 0;

  virtual void AddVertexBuffer(
      const std::shared_ptr<VertexBuffer>& vertex_buffer) = 0;

  static std::shared_ptr<VertexArray> Create();
};
}  // namespace zem::graphics
