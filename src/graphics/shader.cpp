//
// Created by val on 18/12/2025.
//

#include "zem/graphics/shader.h"

#include "opengl/opengl_shader.h"

namespace zem::graphics {
std::expected<std::shared_ptr<Shader>, std::string> Shader::Create(
    const std::string& vertex_path, const std::string& fragment_path) {
  return OpenGLShader::Create(vertex_path, fragment_path);
}
}  // namespace zem::graphics
