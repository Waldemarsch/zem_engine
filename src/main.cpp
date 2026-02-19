//
// Created by vovaz on 02.12.2025.
//
#include <string.h>

#include <cstdio>
#include <filesystem>
#include <iostream>
#include <vector>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "graphics/renderer.h"
#include "graphics/shader.h"

std::vector<GLfloat> triangleVertices = {
    1.0f,
    1.0f,
    0.0f,
    1.0f,
    -1.0f,
    0.0f,
    0.0f,
    0.0f,
    0.0f,
};

int main() {
  if (!glfwInit()) {
    std::printf("GLFW");
    glfwTerminate();
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  // Хуйня, определяющая отношение к deprecated
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *mainWindow = glfwCreateWindow(640, 480, "HUI", NULL, NULL);

  if (!mainWindow) {
    printf("Наебнулось создание окна GLFW");
    glfwTerminate();
    return 1;
  }

  int bufferWidth, bufferHeight;
  glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

  glfwMakeContextCurrent(mainWindow);

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    printf("Наебнулась инициализация GLAD");
    glfwTerminate();
    return 1;
  }

  VertexBuffer vbo(triangleVertices);
  vbo.Bind();

  VertexArray vao;
  vao.AddBuffer(vbo);

  Shader shader("res/shaders/vertex_shader.glsl",
                "res/shaders/fragment_shader.glsl");
  shader.Use();

  Renderer renderer;
  renderer.Init();

  float cur_offset_x = 0.0f;
  int dir = 1;

  while (!glfwWindowShouldClose(mainWindow)) {
    glfwPollEvents();

    renderer.Clear();

    if (cur_offset_x > 1.f)
      dir = -1;
    else if (cur_offset_x < -1.f)
      dir = 1;
    cur_offset_x += 0.01f * (float)dir;
    shader.SetUniformVar("xMove", cur_offset_x);
    std::cout << cur_offset_x << std::endl;

    renderer.Draw(shader, vao);

    glfwSwapBuffers(mainWindow);
  }

  return 0;
}
