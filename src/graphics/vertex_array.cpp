//
// Created by val on 22/12/2025.
//

#include "vertex_array.h"

#include <iostream>
#include <ostream>

VertexArray::VertexArray() {
  glGenVertexArrays(1, &id_);
}

void VertexArray::Bind() const { glBindVertexArray(id_); }

void VertexArray::Unbind() {
  glBindVertexArray(0);
  id_ = 0;
}

void VertexArray::AddBuffer(const VertexBuffer& vb) const {
  Bind();
  vb.Bind();

  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}