//
// Created by vladimir on 5/5/26.
//

#include "opengl_shader.h"

namespace zem::graphics {

OpenGLShader::OpenGLShader(const std::string& vertex_path,
                           const std::string& fragment_path) {}
OpenGLShader::~OpenGLShader() {}
OpenGLShader::OpenGLShader(OpenGLShader&& other) noexcept {}
OpenGLShader& OpenGLShader::operator=(OpenGLShader&& other) noexcept {}
void OpenGLShader::Use() const {}
void OpenGLShader::Unuse() const {}
void OpenGLShader::SetFloat(const std::string& name, float value) const {}
void OpenGLShader::SetInt(const std::string& name, int value) const {}

GLuint OpenGLShader::LinkProgram(GLuint vertex_shader_id,
                                 GLuint fragment_shader_id) const {}
GLuint OpenGLShader::CompileShader(const std::string& shader_code,
                                   GLenum shader_type) const {}
std::string OpenGLShader::ParseShader(
    const std::string& shader_code_path) const {}

}  // namespace zem::graphics
