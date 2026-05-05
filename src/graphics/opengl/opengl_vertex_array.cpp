//
// Created by Владимир on 05.05.2026.
//

#include "zem/graphics/vertex_buffer.h"
#include "opengl_vertex_array.h"

#include <utility>

namespace zem::graphics {
OpenGLVertexArray::OpenGLVertexArray() { glGenVertexArrays(1, &id_); }
OpenGLVertexArray::~OpenGLVertexArray() { glDeleteVertexArrays(1, &id_); }

OpenGLVertexArray::OpenGLVertexArray(OpenGLVertexArray&& other) noexcept
    : id_(std::exchange(other.id_, 0)) {}

OpenGLVertexArray& OpenGLVertexArray::operator=(
    OpenGLVertexArray&& other) noexcept {
  if (this == &other) return *this;
  std::swap(id_, other.id_);
  return *this;
}

void OpenGLVertexArray::Bind() const { glBindVertexArray(id_); }
void OpenGLVertexArray::Unbind() const { glBindVertexArray(0); }
void OpenGLVertexArray::AddVertexBuffer(
    const std::shared_ptr<VertexBuffer>& vertex_buffer) {
  Bind();
  vertex_buffer->Bind();
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}
}  // namespace zem::graphics
