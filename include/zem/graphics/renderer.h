//
// Created by val on 18/12/2025.
//

#pragma once

#include "vertex_array.h"

namespace zem::graphics {
class Shader;

/**
 * @class Renderer
 * @brief Abstract base class for the rendering subsystem.
 * 
 * Provides an interface for initializing rendering resources and executing draw calls.
 */
class Renderer {
 public:
  virtual ~Renderer() = default;

  /**
   * @brief Initializes renderer resources (e.g., shaders, default buffers).
   */
  virtual void Init() = 0;

  /**
   * @brief Executes the rendering pipeline for a single frame.
   */
  virtual void Render() = 0;
};
}  // namespace zem::graphics
