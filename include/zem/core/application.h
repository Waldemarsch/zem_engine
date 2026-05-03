//
// Created by Владимир on 14.04.2026.
//

#pragma once

#include <memory>

#include "clock.h"
#include "window.h"
#include "zem/math/precision.h"

namespace zem::graphics {
class Renderer;
}

namespace zem::core {

/**
 * @class Application
 * @brief Main engine class. It controls the engine lifecycle.
 *
 * It owns main subsystems (window, renderer) and orchestrates the Main Loop.
 */
class Application {
 public:
  explicit Application(std::unique_ptr<graphics::Renderer> renderer);
  ~Application();

  Application(const Application& other) = delete;
  Application& operator=(const Application& other) = delete;

  /**
   * @brief Starts the main application loop. Blocking call until Close() is invoked or window closes.
   */
  void Run();

  /**
   * @brief Signals the application to break out of the main loop.
   */
  void Close();

 private:
  /**
   * @brief Processes input events for the current frame.
   */
  static void ProcessInput();

  /**
   * @brief Method that contains integration part of the Main Loop
   * @param dt delta time
   */
  static void Update(math::Real dt);
  /**
   * @brief Submits draw calls for the current frame.
   */
  void Render() const;

  Window window_;
  std::unique_ptr<graphics::Renderer> renderer_;
  Clock clock_;

  bool is_running_ = false;
};
}  // namespace zem::core