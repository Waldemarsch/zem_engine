//
// Created by val on 18/12/2025.
//

#ifndef OPENGLTRAIN_RENDERER_H
#define OPENGLTRAIN_RENDERER_H
#include "vertex_array.h"

class Shader;
class Renderer {
public:
  void Init();
  void Draw(const Shader& shader, const VertexArray& vao);
  void Clear();
};

#endif  // OPENGLTRAIN_RENDERER_H
