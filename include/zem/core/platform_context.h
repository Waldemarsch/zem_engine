//
// Created by Владимир on 03.05.2026.
//

#pragma once

namespace zem::core {
/**
 * @class PlatformContext
 * @brief RAII guard for the platform-specific environment state (GLFW).
 * 
 * @note Copying and moving are explicitly deleted to prevent state duplication.
 */
class PlatformContext {
 public:
  /**
   * @brief Initializes the underlying platform library (e.g., glfwInit).
   */
  PlatformContext();

  /**
   * @brief Terminates the underlying platform library (e.g., glfwTerminate).
   */
  ~PlatformContext();

  PlatformContext(const PlatformContext& other) = delete;
  PlatformContext& operator=(const PlatformContext& other) = delete;
};
}  // namespace zem::core
