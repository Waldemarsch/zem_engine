//
// Created by Владимир on 25.04.2026.
//

#include "zem/graphics/renderer_open_gl.h"

#include "glad/glad.h"
#include "zem/graphics/shader.h"
#include "zem/graphics/vertex_array.h"

namespace zem::graphics {
RendererOpenGL::RendererOpenGL(std::string shader_path)
    : shader_path_(std::move(shader_path)) {}

void RendererOpenGL::Init() { glClearColor(0.1f, 0.1f, 0.1f, 1.0f); }

void RendererOpenGL::Render() {}

void RendererOpenGL::Draw(const Shader& shader, const VertexArray& vao) {
  shader.Use();
  vao.Bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererOpenGL::Clear() { glClear(GL_COLOR_BUFFER_BIT); }
}  // namespace zem::graphics
