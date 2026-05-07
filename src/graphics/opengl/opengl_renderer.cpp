//
// Created by Владимир on 25.04.2026.
//

#include "opengl_renderer.h"

#include "glad/glad.h"
#include "zem/core/assert.h"
#include "zem/graphics/vertex_array.h"
#include "zem/graphics/vertex_buffer.h"

namespace zem::graphics {

OpenGLRenderer::OpenGLRenderer(std::string shader_path)
    : shader_path_(std::move(shader_path)) {}

void OpenGLRenderer::Init() {
  VertexSpecification();
  ApplyShaders();

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void OpenGLRenderer::Render() {
  Clear();
  Draw();
}
void OpenGLRenderer::VertexSpecification() {
  vao_ = VertexArray::Create();
  vao_->Bind();

  GLfloat vertices[] = {
      -0.5f, -0.5f, 0.0f,  // левый нижний угол
      0.5f,  -0.5f, 0.0f,  // правый нижний угол
      0.0f,  0.5f,  0.0f   // верхний центр
  };

  vbo_ = VertexBuffer::Create(vertices, sizeof(vertices));
  vbo_->Bind();
  vbo_->set_layout({{"pos", ShaderDataType::Float3}});

  vao_->AddVertexBuffer(vbo_);
}
void OpenGLRenderer::ApplyVertexShader() {}

void OpenGLRenderer::Draw() {
  shader_->Use();
  vao_->Bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderer::ApplyShaders() {
  auto shader_res = Shader::Create(shader_path_ + "vertex_shader.glsl",
                                   shader_path_ + "fragment_shader.glsl");
  if (!shader_res.has_value()) {
    ZEM_ASSERT(false, shader_res.error().c_str());
  }

  shader_ = shader_res.value();
}
void OpenGLRenderer::Clear() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}
}  // namespace zem::graphics
