//
// Created by val on 18/12/2025.
//

#include "zem/graphics/shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace zem::graphics {
Shader::Shader(const std::string& vertex_shader_path,
                    const std::string& fragment_shader_path) {
  std::string vertex_src = ParseShader(vertex_shader_path);
  std::string fragment_src = ParseShader(fragment_shader_path);

  GLuint vertex_sh_id = CompileShader(vertex_src, GL_VERTEX_SHADER);
  GLuint fragment_sh_id = CompileShader(fragment_src, GL_FRAGMENT_SHADER);

  id_ = LinkProgram(vertex_sh_id, fragment_sh_id);

  if (id_ <= 0) {
    std::cerr << "Shader build failed" << std::endl;
  }
}
Shader::~Shader() { glDeleteProgram(id_); }

void Shader::Use() const { glUseProgram(id_); }

void Shader::Unuse() const { glUseProgram(0); }

void Shader::SetUniformVar(const std::string& uniform_name, float value) const {
  GLint loc = glGetUniformLocation(id_, uniform_name.c_str());
  glUniform1f(loc, value);
}

void Shader::SetUniformVar(const std::string& uniform_name, int value) const {
  GLint loc = glGetUniformLocation(id_, uniform_name.c_str());
  glUniform1i(loc, value);
}

GLuint Shader::LinkProgram(GLuint vertex_shader_id,
                           GLuint fragment_shader_id) const {
  const GLuint id = glCreateProgram();
  if (!id) {
    printf("Error while creating shader program\n");
    return 0;
  }

  glAttachShader(id, vertex_shader_id);
  glAttachShader(id, fragment_shader_id);

  glLinkProgram(id);

  glDeleteShader(vertex_shader_id);
  glDeleteShader(fragment_shader_id);

  GLint result = 0;
  GLchar elog[1024] = {0};

  glGetProgramiv(id, GL_LINK_STATUS, &result);
  if (!result) {
    glGetProgramInfoLog(id, sizeof(elog), nullptr, elog);
    printf("Error while linking program: %s\n", elog);
    return 0;
  }

  glValidateProgram(id);
  glGetProgramiv(id, GL_VALIDATE_STATUS, &result);
  if (!result) {
    glGetProgramInfoLog(id, sizeof(elog), nullptr, elog);
    printf("Error while validating program: %s\n", elog);
    return 0;
  }

  return id;
}
GLuint Shader::CompileShader(const std::string& shader_code,
                             GLenum shader_type) const {
  GLuint shader = glCreateShader(shader_type);

  const char* src = shader_code.c_str();
  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  GLint result = 0;
  GLchar elog[1024] = {0};

  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (!result) {
    glGetShaderInfoLog(shader, sizeof(elog), NULL, elog);
    printf("Error while compiling shader: %s\n", elog);
    return 0;
  }
  return shader;
}
std::string Shader::ParseShader(const std::string& shader_code_path) const {
  std::ifstream stream(shader_code_path);
  if (!stream.is_open()) {
    std::cerr << "Failed to parse shader code: " << shader_code_path
              << std::endl;
    return "";
  }
  std::stringstream buffer;

  buffer << stream.rdbuf();

  stream.close();

  return buffer.str();
}
}


