//
// Created by val on 17/12/2025.
//

#ifndef OPENGLTRAIN_SHADER_H
#define OPENGLTRAIN_SHADER_H
#include <string>

#include "glad/glad.h"

#endif  // OPENGLTRAIN_SHADER_H

class Shader {
 public:
  Shader(const std::string &vertex_shader_path,
         const std::string &fragment_shader_path);
  ~Shader();

  void Bind() const;
  void Unbind() const;

 private:
  [[nodiscard]] GLuint LinkProgram(GLuint vertex_shader_id,
                                   GLuint fragment_shader_id) const;
  [[nodiscard]] GLuint CompileShader(const std::string &shader_code,
                                     GLenum shader_type) const;
  [[nodiscard]] std::string ParseShader(
      const std::string &shader_code_path) const;
  GLuint id_;
};