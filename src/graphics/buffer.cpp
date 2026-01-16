//
// Created by val on 16/01/2026.
//

#include "buffer.h"
VertexBuffer::VertexBuffer(GLfloat* vertices) {
  glGenBuffers(1, &id_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}
VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &id_); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }
void VertexBuffer::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  id_ = 0;
}
