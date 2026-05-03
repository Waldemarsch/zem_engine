#include "zem/core/application.h"
#include "zem/core/platform_context.h"
#include "zem/graphics/renderer_open_gl.h"
int main() {
  zem::core::PlatformContext platform_ctx;

  auto app =
      zem::core::Application(std::make_unique<zem::graphics::RendererOpenGL>("res/shaders/"));
  app.Run();
}