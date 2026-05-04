//
// Created by val on 22/12/2025.
//

#include "zem/graphics/vertex_array.h"

#include <iostream>
#include <ostream>
#include <utility>

namespace zem::graphics {

VertexArray::VertexArray() { glGenVertexArrays(1, &id_); }
VertexArray::~VertexArray() { glDeleteVertexArrays(1, &id_); }

VertexArray::VertexArray(VertexArray&& other) noexcept
    : id_(std::exchange(other.id_, 0)) {}
VertexArray& VertexArray::operator=(VertexArray&& other) noexcept {
  if (this == &other) return *this;
  std::swap(id_, other.id_);
  return *this;
}

void VertexArray::Bind() const { glBindVertexArray(id_); }

void VertexArray::Unbind() {
  glBindVertexArray(0);
  id_ = 0;
}

void VertexArray::AddVertexAttribPointer() const {
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}
}  // namespace zem::graphics
