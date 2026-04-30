//
// Created by Владимир on 25.04.2026.
//

#include "zem/graphics/renderer_open_gl.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "zem/graphics/shader.h"
#include "zem/graphics/vertex_array.h"

namespace zem::graphics {
RendererOpenGL::RendererOpenGL(std::string shader_path)
    : shader_path_(std::move(shader_path)) {}

void RendererOpenGL::Init() {
  auto shader = Shader(shader_path_ + "vertex_shader.glsl",
                       shader_path_ + "fragment_shader.glsl");

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void RendererOpenGL::Render() {
  Clear();
  VertexSpecification();
  ApplyShaders();
}
void RendererOpenGL::VertexSpecification() {
  auto vao = VertexArray();
  vao.Bind();

  auto vbo =
      VertexBuffer({0, 0, 0, 0.5, 0.5, 0, 1, 1, 0} /* TODO Vertices passing */);
  vbo.Bind();

  vao.AddVertexAttribPointer();
}
void RendererOpenGL::ApplyVertexShader() {}

void RendererOpenGL::Draw(const Shader& shader, const VertexArray& vao) {
  shader.Use();
  vao.Bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererOpenGL::ApplyShaders() {
  auto shader = Shader(shader_path_ + "vertex_shader.glsl",
                       shader_path_ + "fragment_shader.glsl");
  shader.Use();
}
void RendererOpenGL::Clear() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
}  // namespace zem::graphics
