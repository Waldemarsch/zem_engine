//
// Created by val on 26/01/2026.
//
#define GLFW_INCLUDE_NONE


#include "zem/core/window.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "zem/core/assert.h"

namespace zem::core {
class Window::Impl {
 public:
  explicit Impl(const WindowProps& props) {
    native_window_ = glfwCreateWindow(props.width, props.height,
                                      props.title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(native_window_);

    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    ZEM_ASSERT(status, "Failed to initialize GLAD!");
  }

  ~Impl() {
    if (native_window_) {
      glfwDestroyWindow(native_window_);
    }
  }
  GLFWwindow* native_window_ = nullptr;

 private:
};

Window::Window(const WindowProps& props)
    : m_impl_(std::make_unique<Impl>(props)) {}

Window::~Window() = default;
Window::Window(Window&&) noexcept = default;
Window& Window::operator=(Window&&) noexcept = default;

void Window::PollEvents() {
  glfwPollEvents();
}
void Window::SwapBuffers() {
  glfwSwapBuffers(m_impl_->native_window_);
}

bool Window::ShouldClose() const {
  return glfwWindowShouldClose(m_impl_->native_window_) != 0;
}
void* Window::GetNativeWindow() const {
  return m_impl_->native_window_;
}

}  // namespace zem::core
