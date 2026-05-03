//
// Created by Владимир on 03.05.2026.
//

#pragma once

namespace zem::graphics {
/**
 * @class GraphicsContext
 * @brief Abstract interface for a graphics API context (e.g., OpenGL, Vulkan).
 * 
 * Responsible for initializing the graphics API and presenting rendered frames to the OS window.
 */
class GraphicsContext {
 public:
  virtual ~GraphicsContext() = default;

  /**
   * @brief Initializes the graphics context. Must be called after OS window creation.
   */
  virtual void Init() = 0;

  /**
   * @brief Swaps the front and back buffers, presenting the rendered image to the screen.
   */
  virtual void SwapBuffers() = 0;
};
}  // namespace zem::graphics
