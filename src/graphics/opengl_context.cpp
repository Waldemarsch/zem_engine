//
// Created by Владимир on 03.05.2026.
//
#define GLFW_INCLUDE_NONE

#include "zem/graphics/contexts/opengl_context.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "zem/core/assert.h"

namespace zem::graphics {
OpenGLContext::OpenGLContext(GLFWwindow* window_handle)
    : window_handle_(window_handle) {}

void OpenGLContext::Init() {
  glfwMakeContextCurrent(window_handle_);

  int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  ZEM_ASSERT(status, "Failed to initialize GLAD!");
}
void OpenGLContext::SwapBuffers() { glfwSwapBuffers(window_handle_); }
}  // namespace zem::graphics