//
// Created by Владимир on 03.05.2026.
//

#define GLFW_INCLUDE_NONE

#include "zem/core/platform_context.h"

#include "GLFW/glfw3.h"
#include "zem/core/assert.h"

namespace zem::core {
PlatformContext::PlatformContext() {
  const int success = glfwInit();
  ZEM_ASSERT(success, "Failed to initialize GLFW");
}

PlatformContext::~PlatformContext() { glfwTerminate(); }
}  // namespace zem::core
