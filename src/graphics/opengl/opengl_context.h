//
// Created by Владимир on 03.05.2026.
//

#pragma once
#include "../../../include/zem/graphics/contexts/graphics_context.h"

struct GLFWwindow;

namespace zem::graphics {
/**
 * @class OpenGLContext
 * @brief OpenGL implementation of the GraphicsContext.
 */
class OpenGLContext : public GraphicsContext {
 public:
  /**
   * @brief Constructs an OpenGLContext bound to a specific GLFW window.
   * @param window_handle Opaque pointer to the native GLFWwindow.
   */
  explicit OpenGLContext(GLFWwindow* window_handle);

  void Init() override;
  void SwapBuffers() override;

private:
  GLFWwindow* window_handle_;
};
}  // namespace zem::graphics