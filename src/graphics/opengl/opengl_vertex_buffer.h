//
// Created by vladimir on 5/4/26.
//

#pragma once
#include "../../../cmake-build-debug/_deps/glfw-src/src/internal.h"
#include "zem/graphics/opengl_vertex_buffer.h"

namespace zem::graphics {
class OpenGLVertexBuffer : public VertexBuffer {
 public:
  ~OpenGLVertexBuffer() override;
  void Bind() const override;
  void Unbind() const override;

private:
  GLuint id_{0};
};
}