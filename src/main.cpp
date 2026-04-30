#include "zem/core/application.h"
#include "zem/graphics/renderer_open_gl.h"
int main() {
  auto app =
      zem::core::Application(std::make_unique<zem::graphics::RendererOpenGL>("res/shaders/"));
  app.Run();
}