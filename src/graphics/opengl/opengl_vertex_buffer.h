//
// Created by vladimir on 5/4/26.
//

#pragma once

#include "glad/glad.h"
#include "zem/graphics/vertex_buffer.h"

namespace zem::graphics {
class OpenGLVertexBuffer : public VertexBuffer {
 public:
  OpenGLVertexBuffer(const void* vertices, uint32_t size);
  ~OpenGLVertexBuffer() override;

  OpenGLVertexBuffer(const OpenGLVertexBuffer& other) = delete;
  OpenGLVertexBuffer& operator=(const OpenGLVertexBuffer& other) = delete;

  OpenGLVertexBuffer(OpenGLVertexBuffer&& other) noexcept;
  OpenGLVertexBuffer& operator=(OpenGLVertexBuffer&& other) noexcept;

  void Bind() const override;
  void Unbind() const override;

 private:
  GLuint id_{0};
};
}  // namespace zem::graphics