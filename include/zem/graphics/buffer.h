//
// Created by val on 16/01/2026.
//

#ifndef OPENGLTRAIN_BUFFER_H
#define OPENGLTRAIN_BUFFER_H
#include <vector>

#include "glad/glad.h"

namespace zem::graphics {
class VertexBuffer {
 public:
  explicit VertexBuffer(const std::vector<GLfloat>& vertices);

  ~VertexBuffer();
  void Bind() const;
  void Unbind();

 private:
  GLuint id_{0};
};
}  // namespace zem::graphics

#endif  // OPENGLTRAIN_BUFFER_H
