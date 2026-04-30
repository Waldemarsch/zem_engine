//
// Created by val on 16/01/2026.
//

#include "zem/graphics/buffer.h"

#include <iostream>

namespace zem::graphics {
VertexBuffer::VertexBuffer(const std::vector<GLfloat>& vertices) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ARRAY_BUFFER, id_);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat),
               vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &id_); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }

void VertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  id_ = 0;
}
}  // namespace zem::graphics
