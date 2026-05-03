//
// Created by val on 26/01/2026.
//

#pragma once

#include <memory>

namespace zem::core {

struct WindowProps {
  std::string title{"Zem Engine"};
  int width{1280};
  int height{720};
};

class Window {
 public:
  explicit Window(const WindowProps& props = WindowProps{});
  ~Window();

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

  Window(Window&&) noexcept;
  Window& operator=(Window&&) noexcept;

  void PollEvents();

  void SwapBuffers();

  [[nodiscard]] void* GetNativeWindow() const;

  [[nodiscard]] bool ShouldClose() const;

 private:
  class Impl;
  std::unique_ptr<Impl> m_impl_;
};
}  // namespace zem::core
