//
// Created by Владимир on 14.04.2026.
//
#define GLFW_INCLUDE_NONE


#include "zem/core/application.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "zem/core/window.h"
#include "zem/graphics/renderer.h"

namespace zem::core {
Application::Application(std::unique_ptr<graphics::Renderer> renderer)
    : renderer_(std::move(renderer)) {
  glfwInit();  // TODO низкий уровень абстракции, добавить контекст
  window_ = std::make_unique<Window>();
}
Application::~Application() {
  glfwTerminate();  // TODO низкий уровень абстракции, добавить контекст
}

void Application::Run() {
  is_running_ = true;
  while (is_running_) {
    ProcessInput();
    Update(clock_.GetElapsedTime());
    Render();
  }
}
void Application::Close() { is_running_ = false; }
void Application::ProcessInput() {}
void Application::Update(math::Real dt) {}
void Application::Render() const {
  // renderer_->Render();
  window_->OnUpdate();  // TODO точно ли тут должно быть?
}
}  // namespace zem::core
