//
// Created by Владимир on 14.04.2026.
//

#ifndef OPENGLTRAIN_APPLICATION_H
#define OPENGLTRAIN_APPLICATION_H
#include <memory>

#include "clock.h"
#include "zem/math/precision.h"

namespace zem::graphics {
class Renderer;
}

namespace zem::core {
class Window;

/**
 * @brief Main engine class. It controls engine life cycle.
 * It owns main subsystems (window, renderer).
 * It also contains the Main Loop.
 */
class Application {
 public:
  explicit Application(std::unique_ptr<graphics::Renderer> renderer);

  Application(const Application& other) = delete;
  Application& operator=(const Application& other) = delete;

  void Run();

  void Close();

 private:
  static void ProcessInput();

  /**
   * @brief Method that contains integration part of the Main Loop
   * @param dt delta time
   */
  static void Update(math::Real dt);
  void Render() const;

  std::unique_ptr<Window> window_;
  std::unique_ptr<graphics::Renderer> renderer_;
  Clock clock_;

  bool is_running_ = false;
};
}  // namespace zem::core

#endif  // OPENGLTRAIN_APPLICATION_H