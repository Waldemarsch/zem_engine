//
// Created by vovaz on 02.12.2025.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string.h>

#include <cstdio>

GLuint VAO, VBO, shader;

GLfloat triangleVertices[] = {
    1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};

GLuint shader_program;

static const char *vertex_shader_code = R"(
#version 330

layout (location = 0) in vec3 pos;
void main() {
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}
)";

static const char *fragment_shader_code = R"(
#version 330

out vec4 color;
void main() {
    color = vec4(0.0, 1.0, 0, 1.0);
}
)";

void AddShader(GLuint program, const char *shader_code, GLenum shader_type) {
  GLuint shader = glCreateShader(shader_type);

  const GLchar *code[1] = {shader_code};
  GLint code_length[1];
  code_length[0] = {strlen(code[0])};

  glShaderSource(shader, 1, code, code_length);
  glCompileShader(shader);

  GLint result = 0;
  GLchar elog[1024] = {0};

  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (!result) {
    glGetShaderInfoLog(shader, sizeof(elog), NULL, elog);
    printf("Error while compiling shader: %s\n", elog);
    return;
  }

  glAttachShader(program, shader);
}

void CompileShaders() {
  shader_program = glCreateProgram();

  if (!shader_program) {
    printf("Не создалась шейдер-программа");
    return;
  }

  AddShader(shader_program, vertex_shader_code, GL_VERTEX_SHADER);
  AddShader(shader_program, fragment_shader_code, GL_FRAGMENT_SHADER);

  glLinkProgram(shader_program);

  GLint result = 0;
  GLchar elog[1024] = {0};

  glGetProgramiv(shader_program, GL_LINK_STATUS, &result);
  if (!result) {
    glGetProgramInfoLog(shader_program, sizeof(elog), NULL, elog);
    printf("Error while linking program: %s\n", elog);
    return;
  }

  glValidateProgram(shader_program);
  glGetProgramiv(shader_program, GL_VALIDATE_STATUS, &result);
  if (!result) {
    glGetProgramInfoLog(shader_program, sizeof(elog), NULL, elog);
    printf("Error while validating program: %s\n", elog);
    return;
  }
}

void DrawTriangle() {
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices,
               GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

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

  DrawTriangle();
  CompileShaders();

  while (!glfwWindowShouldClose(mainWindow)) {
    glfwPollEvents();  // Обработка инпута

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Очистка цвета
    glClear(GL_COLOR_BUFFER_BIT);          // Очистка кадра

    glUseProgram(shader_program);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glfwSwapBuffers(mainWindow);
  }

  return 0;
}
