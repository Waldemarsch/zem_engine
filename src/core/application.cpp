//
// Created by Владимир on 14.04.2026.
//
#define GLFW_INCLUDE_NONE


#include "zem/core/application.h"

#include "zem/core/window.h"
#include "zem/graphics/renderer.h"

namespace zem::core {
Application::Application(std::unique_ptr<graphics::Renderer> renderer)
    : renderer_(std::move(renderer)) {
}
Application::~Application() {
}

void Application::Run() {
  is_running_ = true;
  while (is_running_) {
    window_.PollEvents();
    ProcessInput();
    Update(clock_.GetElapsedTime());
    Render();
    window_.SwapBuffers();
  }
}
void Application::Close() { is_running_ = false; }
void Application::ProcessInput() {}
void Application::Update(math::Real dt) {}
void Application::Render() const {
  // renderer_->Render();
}
}  // namespace zem::core
