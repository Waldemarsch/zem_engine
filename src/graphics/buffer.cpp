//
// Created by val on 16/01/2026.
//

#include "zem/graphics/buffer.h"

#include <iostream>
#include <utility>

namespace zem::graphics {
VertexBuffer::VertexBuffer(const std::vector<GLfloat>& vertices) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ARRAY_BUFFER, id_);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat),
               vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &id_); }

VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
    : id_(std::exchange(other.id_, 0)) {}
VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
  if (this == &other) return *this;
  std::swap(id_, other.id_);
  return *this;
}

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }

void VertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  id_ = 0;
}
}  // namespace zem::graphics
