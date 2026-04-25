//
// Created by Владимир on 14.04.2026.
//

#include "zem/core/application.h"

#include "zem/core/window.h"
#include "zem/graphics/renderer.h"

zem::core::Application::Application()
    : window_(std::make_unique<Window>()),
      renderer_(std::make_unique<graphics::Renderer>()) {}

void zem::core::Application::Run() {
  is_running_ = true;
  while (is_running_) {
    ProcessInput();
    Update(clock_.GetElapsedTime());
    Render();
  }
}
void zem::core::Application::Close() {
  is_running_ = false;
}
void zem::core::Application::ProcessInput() {

}