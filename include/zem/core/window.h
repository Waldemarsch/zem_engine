//
// Created by val on 26/01/2026.
//

#pragma once

#include <memory>

#include "zem/graphics/contexts/graphics_context.h"

namespace zem::core {

/**
 * @struct WindowProps
 * @brief Configuration properties used to initialize a Window.
 */
struct WindowProps {
  std::string title{"Zem Engine"};
  int width{1280};
  int height{720};
};

/**
 * @class Window
 * @brief Represents an OS-level window and encapsulates its graphics context.
 * 
 * Implements the Pimpl idiom to hide OS-specific window handlers (e.g. GLFWwindow).
 */
class Window {
 public:
  /**
   * @brief Constructs a new window and initializes its internal graphics context.
   * @param props Window properties (title, width, height).
   */
  explicit Window(const WindowProps& props = WindowProps{});
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  Window(Window&&) noexcept;
  Window& operator=(Window&&) noexcept;

  /**
   * @brief Polls OS window events (input, resize, close). Must be called at the start of a frame.
   */
  void PollEvents();

  /**
   * @brief Swaps the front and back buffers. Must be called at the end of a frame.
   */
  void SwapBuffers();

  [[nodiscard]] void* GetNativeWindow() const;

  [[nodiscard]] bool ShouldClose() const;

 private:
  class Impl;
  std::unique_ptr<Impl> m_impl_;

  std::unique_ptr<graphics::GraphicsContext> context_;
};
}  // namespace zem::core
