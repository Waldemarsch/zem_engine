//
// Created by val on 16/01/2026.
//

#include <iostream>
#include <utility>

#include "vertex_buffer.h"

namespace zem::graphics {
OpenGLVertexBuffer::OpenGLVertexBuffer(const std::vector<GLfloat>& vertices) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ARRAY_BUFFER, id_);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat),
               vertices.data(), GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer() { glDeleteBuffers(1, &id_); }

OpenGLVertexBuffer::OpenGLVertexBuffer(OpenGLVertexBuffer&& other) noexcept
    : id_(std::exchange(other.id_, 0)) {}
OpenGLVertexBuffer& OpenGLVertexBuffer::operator=(OpenGLVertexBuffer&& other) noexcept {
  if (this == &other) return *this;
  std::swap(id_, other.id_);
  return *this;
}

void OpenGLVertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }

void OpenGLVertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  id_ = 0;
}
}  // namespace zem::graphics
