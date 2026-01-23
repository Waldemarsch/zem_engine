//
// Created by val on 18/12/2025.
//

#include "renderer.h"

#include "glad/glad.h"
#include "shader.h"
#include "vertex_array.h"

void Renderer::Init() { glClearColor(0.1f, 0.1f, 0.1f, 1.0f); }

void Renderer::Draw(const Shader& shader, const VertexArray& vao) {
  shader.Use();
  vao.Bind();
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Renderer::Clear() { glClear(GL_COLOR_BUFFER_BIT); }