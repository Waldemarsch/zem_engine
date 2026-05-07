//
// Created by Владимир on 05.05.2026.
//

#include "opengl_vertex_array.h"

#include <utility>

#include "zem/core/assert.h"
#include "zem/graphics/vertex_buffer.h"

namespace {
GLenum ShaderDataTypeToOpenGLBaseType(zem::graphics::ShaderDataType type) {
  switch (type) {
    case zem::graphics::ShaderDataType::Float:
      return GL_FLOAT;
    case zem::graphics::ShaderDataType::Float2:
      return GL_FLOAT;
    case zem::graphics::ShaderDataType::Float3:
      return GL_FLOAT;
    case zem::graphics::ShaderDataType::Float4:
      return GL_FLOAT;
    case zem::graphics::ShaderDataType::Int1:
      return GL_INT;
    case zem::graphics::ShaderDataType::Int2:
      return GL_INT;
    case zem::graphics::ShaderDataType::Int3:
      return GL_INT;
    case zem::graphics::ShaderDataType::Int4:
      return GL_INT;
    case zem::graphics::ShaderDataType::Bool:
      return GL_BOOL;
    case zem::graphics::ShaderDataType::None:
      break;
  }
  ZEM_ASSERT(false, "Unknown ShaderDataType!");
  return 0;
}
}  // namespace

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

  ZEM_ASSERT(!vertex_buffer->layout().elements().empty(),
             "Failed to bind VBO to VAO: empty layout");

  for (auto& el : vertex_buffer->layout()) {
    glEnableVertexAttribArray(vertex_attribute_index_);
    glVertexAttribPointer(
        vertex_attribute_index_, static_cast<GLint>(el.size),
        ShaderDataTypeToOpenGLBaseType(el.type), el.normalized,
        static_cast<GLsizei>(vertex_buffer->layout().stride()), &el.offset);
    vertex_attribute_index_++;
  }
}
}  // namespace zem::graphics
