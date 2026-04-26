//
// Created by val on 18/12/2025.
//

#pragma once

#include "vertex_array.h"

namespace zem::graphics {
class Shader;

class Renderer {
 public:
  virtual ~Renderer() = default;

  virtual void Init() = 0;
  virtual void Render() = 0;
};
}  // namespace zem::graphics
