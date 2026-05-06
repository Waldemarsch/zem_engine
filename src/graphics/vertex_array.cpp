//
// Created by vladimir on 5/6/26.
//


#include "zem/graphics/vertex_array.h"

#include "opengl/opengl_vertex_array.h"

namespace zem::graphics {
std::shared_ptr<VertexArray> VertexArray::Create() {
  return std::make_shared<OpenGLVertexArray>();
}
}  // namespace zem::graphics