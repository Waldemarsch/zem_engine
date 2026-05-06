//
// Created by val on 18/12/2025.
//

#include "zem/graphics/shader.h"

#include "opengl/opengl_shader.h"

namespace zem::graphics {
std::shared_ptr<Shader> Shader::Create(const std::string& vertex_path,
                                       const std::string& fragment_path) {
  return std::make_shared<OpenGLShader>(vertex_path, fragment_path);
}
}  // namespace zem::graphics
