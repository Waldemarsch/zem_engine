//
// Created by Владимир on 03.05.2026.
//

#pragma once
#include "graphics_context.h"

struct GLFWwindow;

namespace zem::graphics {
class OpenGLContext : public GraphicsContext {
 public:
  explicit OpenGLContext(GLFWwindow* window_handle);

  void Init() override;
  void SwapBuffers() override;

private:
  GLFWwindow* window_handle_;
};
}  // namespace zem::graphics