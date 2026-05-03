//
// Created by val on 26/01/2026.
//

#include "zem/core/window.h"

#include "GLFW/glfw3.h"
#include "zem/core/assert.h"
#include "zem/graphics/contexts/opengl_context.h"

namespace zem::core {
class Window::Impl {
 public:
  explicit Impl(const WindowProps& props) {
    native_window_ = glfwCreateWindow(props.width, props.height,
                                      props.title.c_str(), nullptr, nullptr);
  }

  ~Impl() {
    if (native_window_) {
      glfwDestroyWindow(native_window_);
    }
  }
  GLFWwindow* native_window_ = nullptr;
};

Window::Window(const WindowProps& props)
    : m_impl_(std::make_unique<Impl>(props)) {
  context_ = std::make_unique<graphics::OpenGLContext>(m_impl_->native_window_);
  context_->Init();
}

Window::~Window() = default;
Window::Window(Window&&) noexcept = default;
Window& Window::operator=(Window&&) noexcept = default;

void Window::PollEvents() {
  glfwPollEvents();
}
void Window::SwapBuffers() {
  context_->SwapBuffers();
}

bool Window::ShouldClose() const {
  return glfwWindowShouldClose(m_impl_->native_window_) != 0;
}
void* Window::GetNativeWindow() const {
  return m_impl_->native_window_;
}

}  // namespace zem::core
