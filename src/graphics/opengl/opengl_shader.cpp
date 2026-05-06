//
// Created by vladimir on 5/5/26.
//

#include "opengl_shader.h"

#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

#include "zem/core/assert.h"

namespace {

std::expected<std::string, std::string> ParseShader(
    const std::string& shader_code_path) {
  std::ifstream file(shader_code_path);
  if (!file.is_open()) {
    return std::unexpected(
        "Failed to read Shader .glsl file: " + shader_code_path + "\n");
  }

  std::stringstream ss;
  ss << file.rdbuf();
  return ss.str();
}
std::expected<GLuint, std::string> CompileShader(const std::string& shader_code,
                                                 GLenum shader_type) {
  GLuint id = glCreateShader(shader_type);
  const char* src = shader_code.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);
  GLint isCompiled = 0;
  glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);

  if (isCompiled == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<GLchar> infoLog(maxLength);
    glGetShaderInfoLog(id, maxLength, &maxLength, &infoLog[0]);

    glDeleteShader(id);
    return std::unexpected(std::string(infoLog.begin(), infoLog.end()));
  }
  return id;
}
std::expected<GLuint, std::string> LinkProgram(GLuint vertex_shader_id,
                                               GLuint fragment_shader_id) {
  GLuint program_id = glCreateProgram();

  glAttachShader(program_id, vertex_shader_id);
  glAttachShader(program_id, fragment_shader_id);
  glLinkProgram(program_id);
  GLint isLinked = 0;
  glGetProgramiv(program_id, GL_LINK_STATUS, &isLinked);

  if (isLinked == GL_FALSE) {
    GLint maxLength = 0;
    glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxLength);
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(program_id, maxLength, &maxLength, &infoLog[0]);
    glDeleteProgram(program_id);
    return std::unexpected(std::string(infoLog.begin(), infoLog.end()));
  }

  glDetachShader(program_id, vertex_shader_id);
  glDetachShader(program_id, fragment_shader_id);
  return program_id;
}
}  // namespace

namespace zem::graphics {

OpenGLShader::OpenGLShader(GLuint program_id) : id_(program_id) {}
OpenGLShader::~OpenGLShader() { glDeleteProgram(id_); }

std::expected<std::shared_ptr<OpenGLShader>, std::string> OpenGLShader::Create(
    const std::string& vertex_path, const std::string& fragment_path) {
  auto vertex_src = ParseShader(vertex_path);
  if (!vertex_src.has_value()) return std::unexpected(vertex_src.error());

  auto fragment_src = ParseShader(fragment_path);
  if (!fragment_src.has_value()) return std::unexpected(fragment_src.error());

  auto vertex_id = CompileShader(vertex_src.value(), GL_VERTEX_SHADER);
  if (!vertex_id.has_value()) return std::unexpected(vertex_id.error());

  auto fragment_id = CompileShader(fragment_src.value(), GL_FRAGMENT_SHADER);
  if (!fragment_id.has_value()) {
    glDeleteShader(vertex_id.value());
    return std::unexpected(fragment_id.error());
  }

  auto program_id = LinkProgram(vertex_id.value(), fragment_id.value());

  glDeleteShader(vertex_id.value());
  glDeleteShader(fragment_id.value());

  if (!program_id.has_value()) {
    return std::unexpected(program_id.error());
  }

  return std::shared_ptr<OpenGLShader>(new OpenGLShader(program_id.value()));
}

OpenGLShader::OpenGLShader(OpenGLShader&& other) noexcept
    : id_(std::exchange(other.id_, 0)) {}
OpenGLShader& OpenGLShader::operator=(OpenGLShader&& other) noexcept {
  if (this == &other) return *this;
  std::swap(id_, other.id_);
  return *this;
}

void OpenGLShader::Use() const { glUseProgram(id_); }
void OpenGLShader::Unuse() const { glUseProgram(0); }
void OpenGLShader::SetFloat(const std::string& name, float value) const {
  GLint location = glGetUniformLocation(id_, name.c_str());
  ZEM_ASSERT(location != -1, "Failed to get uniform location");
  glUniform1f(location, value);
}
void OpenGLShader::SetInt(const std::string& name, int value) const {
  GLint location = glGetUniformLocation(id_, name.c_str());
  ZEM_ASSERT(location != -1, "Failed to get uniform location");
  glUniform1i(location, value);
}
}  // namespace zem::graphics
