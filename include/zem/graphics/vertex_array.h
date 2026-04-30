//
// Created by val on 22/12/2025.
//

#ifndef OPENGLTRAIN_VERTEX_ARRAY_H
#define OPENGLTRAIN_VERTEX_ARRAY_H
#include "buffer.h"
#include "glad/glad.h"

namespace zem::graphics {
class VertexArray {
 public:
  VertexArray();
  void Bind() const;
  void Unbind();
  void AddVertexAttribPointer() const;

 private:
  GLuint id_{0};
};
}  // namespace zem::graphics

#endif  // OPENGLTRAIN_VERTEX_ARRAY_H
