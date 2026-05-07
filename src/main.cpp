#include "graphics/opengl/opengl_renderer.h"
#include "zem/core/application.h"
#include "zem/core/platform_context.h"
int main() {
  zem::core::PlatformContext platform_ctx;

  auto app =
      zem::core::Application(std::make_unique<zem::graphics::OpenGLRenderer>("res/shaders/"));
  app.Run();
}