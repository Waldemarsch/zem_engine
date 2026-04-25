//
// Created by val on 18/12/2025.
//

#pragma once

#include "vertex_array.h"

namespace zem::graphics {
class Shader;

class Renderer {
 public:
  void Init();
  void Draw(const Shader& shader, const VertexArray& vao);
  void Clear();
};
}  // namespace zem::graphics
