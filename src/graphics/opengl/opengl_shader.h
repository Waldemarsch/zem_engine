//
// Created by vladimir on 5/5/26.
//

#pragma once
#include "glad/glad.h"
#include "zem/graphics/shader.h"

namespace zem::graphics {

class OpenGLShader : public Shader {
 public:
  OpenGLShader(const std::string& vertex_path,
               const std::string& fragment_path);
  ~OpenGLShader() override;

  OpenGLShader(const OpenGLShader& other) = delete;
  OpenGLShader& operator=(const OpenGLShader& other) = delete;

  OpenGLShader(OpenGLShader&& other) noexcept;
  OpenGLShader& operator=(OpenGLShader&& other) noexcept;

  void Use() const override;
  void Unuse() const override;
  void SetFloat(const std::string& name, float value) const override;
  void SetInt(const std::string& name, int value) const override;

 private:
  GLuint id_{0};

  [[nodiscard]] GLuint LinkProgram(GLuint vertex_shader_id,
                                   GLuint fragment_shader_id) const;
  [[nodiscard]] GLuint CompileShader(const std::string& shader_code,
                                     GLenum shader_type) const;
  [[nodiscard]] std::string ParseShader(
      const std::string& shader_code_path) const;
};
}  // namespace zem::graphics
