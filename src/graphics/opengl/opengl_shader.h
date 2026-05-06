//
// Created by vladimir on 5/5/26.
//

#pragma once
#include <expected>

#include "glad/glad.h"
#include "zem/graphics/shader.h"

namespace zem::graphics {

class OpenGLShader final : public Shader {
 public:
  ~OpenGLShader() override;

  static std::expected<std::shared_ptr<OpenGLShader>, std::string> Create(
      const std::string& vertex_path, const std::string& fragment_path);

  OpenGLShader(const OpenGLShader& other) = delete;
  OpenGLShader& operator=(const OpenGLShader& other) = delete;

  OpenGLShader(OpenGLShader&& other) noexcept;
  OpenGLShader& operator=(OpenGLShader&& other) noexcept;

  void Use() const override;
  void Unuse() const override;

  void SetFloat(const std::string& name, float value) const override;
  void SetInt(const std::string& name, int value) const override;

 private:
  explicit OpenGLShader(GLuint program_id);

  GLuint id_{0};
};
}  // namespace zem::graphics
