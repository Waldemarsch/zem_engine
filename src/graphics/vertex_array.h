//
// Created by val on 22/12/2025.
//

#ifndef OPENGLTRAIN_VERTEX_ARRAY_H
#define OPENGLTRAIN_VERTEX_ARRAY_H
#include "buffer.h"
#include "glad/glad.h"

class VertexArray {
 public:
  VertexArray();
  void Bind() const;
  void Unbind();
  void AddBuffer(const VertexBuffer &vb) const;

 private:
  GLuint id_{0};
};

#endif  // OPENGLTRAIN_VERTEX_ARRAY_H
