//
// Created by Владимир on 25.04.2026.
//

#include "zem/graphics/renderer_open_gl.h"


#include "glad/glad.h"
#include "zem/graphics/vertex_array.h"

namespace zem::graphics {
RendererOpenGL::RendererOpenGL(std::string shader_path)
    : shader_path_(std::move(shader_path)) {
}

void RendererOpenGL::Init() {
  VertexSpecification();
  ApplyShaders();

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void RendererOpenGL::Render() {
  Clear();
  Draw();
}
void RendererOpenGL::VertexSpecification() {
  vao_.emplace();
  vao_->Bind();

  vbo_.emplace(std::initializer_list<float>{-0.5f, -0.5f, 0.0f, // левый нижний угол
     0.5f, -0.5f, 0.0f, // правый нижний угол
     0.0f,  0.5f, 0.0f  // верхний центр
    });
  vbo_->Bind();

  vao_->AddVertexAttribPointer();
}
void RendererOpenGL::ApplyVertexShader() {}

void RendererOpenGL::Draw() {
  shader_.value().Use();
  vao_->Bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RendererOpenGL::ApplyShaders() {
  shader_ = Shader(shader_path_ + "vertex_shader.glsl",
                       shader_path_ + "fragment_shader.glsl");
  shader_.value().Use();
}
void RendererOpenGL::Clear() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
}  // namespace zem::graphics
