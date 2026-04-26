//
// Created by Владимир on 14.04.2026.
//

#include "zem/core/application.h"

#include "zem/core/window.h"
#include "zem/graphics/renderer.h"

namespace zem::core {
Application::Application(std::unique_ptr<graphics::Renderer> renderer)
    : window_(std::make_unique<Window>()), renderer_(std::move(renderer)) {}

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
void Application::Render() const { renderer_->Render(); }
}  // namespace zem::core
