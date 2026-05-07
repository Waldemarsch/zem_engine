//
// Created by Владимир on 05.05.2026.
//

#pragma once

#include "glad/glad.h"
#include "zem/graphics/vertex_array.h"

namespace zem::graphics {
class OpenGLVertexArray : public VertexArray {
 public:
  OpenGLVertexArray();
  ~OpenGLVertexArray() override;

  OpenGLVertexArray(const OpenGLVertexArray&) = delete;
  OpenGLVertexArray& operator=(const OpenGLVertexArray&) = delete;

  OpenGLVertexArray(OpenGLVertexArray&& other) noexcept;
  OpenGLVertexArray& operator=(OpenGLVertexArray&& other) noexcept;

  void Bind() const override;
  void Unbind() const override;
  void AddVertexBuffer(
      const std::shared_ptr<VertexBuffer>& vertex_buffer) override;

private:
  GLuint id_{0};
  uint32_t vertex_attribute_index_{0};
};
}  // namespace zem::graphics
