//
// Created by vladimir on 5/6/26.
//

#include "zem/graphics/vertex_buffer.h"

#include "opengl/opengl_vertex_buffer.h"

namespace zem::graphics {
std::shared_ptr<VertexBuffer> VertexBuffer::Create(const void* vertices,
                                                   uint32_t size) {
  return std::make_shared<OpenGLVertexBuffer>(vertices, size);
}
}  // namespace zem::graphics