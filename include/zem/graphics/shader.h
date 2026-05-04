//
// Created by val on 17/12/2025.
//

#pragma once

#include <string>

#include "glad/glad.h"

namespace zem::graphics {
/**
 * @class Shader
 * @brief Represents an OpenGL shader program.
 *
 * Handles loading from source, compilation, linking, and uniform setting.
 */
class Shader {
 public:
  /**
   * @brief Constructs and compiles a shader program from vertex and fragment
   * shader files.
   * @param vertex_shader_path Path to the vertex shader source file.
   * @param fragment_shader_path Path to the fragment shader source file.
   */
  Shader(const std::string &vertex_shader_path,
         const std::string &fragment_shader_path);
  ~Shader();

  Shader(const Shader &other) = delete;
  Shader &operator=(const Shader &other) = delete;

  Shader(Shader &&other) noexcept;
  Shader &operator=(Shader &&other) noexcept;

  /**
   * @brief Activates the shader program for use in subsequent draw calls.
   */
  void Use() const;

  /**
   * @brief Deactivates the shader program.
   */
  void Unuse() const;

  /**
   * @brief Sets a float uniform variable in the shader.
   * @param uniform_name Name of the uniform variable.
   * @param value The float value to set.
   */
  void SetUniformVar(const std::string &uniform_name, float value) const;

  /**
   * @brief Sets an integer uniform variable in the shader.
   * @param uniform_name Name of the uniform variable.
   * @param value The integer value to set.
   */
  void SetUniformVar(const std::string &uniform_name, int value) const;

 private:
  GLuint id_;
  /**
   * @brief Links compiled vertex and fragment shaders into a program.
   * @param vertex_shader_id The OpenGL ID of the compiled vertex shader.
   * @param fragment_shader_id The OpenGL ID of the compiled fragment shader.
   * @return The OpenGL ID of the linked shader program.
   */
  [[nodiscard]] GLuint LinkProgram(GLuint vertex_shader_id,
                                   GLuint fragment_shader_id) const;

  /**
   * @brief Compiles a single shader from source code.
   * @param shader_code The raw shader source code.
   * @param shader_type The OpenGL shader type (e.g., GL_VERTEX_SHADER).
   * @return The OpenGL ID of the compiled shader.
   */
  [[nodiscard]] GLuint CompileShader(const std::string &shader_code,
                                     GLenum shader_type) const;

  /**
   * @brief Reads a shader source file from disk.
   * @param shader_code_path The file path to the shader source.
   * @return The contents of the shader file as a string.
   */
  [[nodiscard]] std::string ParseShader(
      const std::string &shader_code_path) const;
};
}  // namespace zem::graphics
