//
// Created by Владимир on 25.04.2026.
//

#pragma once
#include <optional>
#include <string>

#include "renderer.h"
#include "shader.h"

namespace zem::graphics {
/**
 * @class RendererOpenGL
 * @brief OpenGL implementation of the Renderer interface.
 */
class RendererOpenGL : public Renderer {
 public:
  /**
   * @brief Constructs an OpenGL renderer.
   * @param shader_path Base directory path for shader source files.
   */
  explicit RendererOpenGL(std::string shader_path);

  void Init() override;
  void Render() override;

 private:
  /**
   * @brief Configures vertex attributes and layout.
   */
  void VertexSpecification();
  
  /**
   * @brief Compiles and attaches the vertex shader.
   */
  void ApplyVertexShader();
  
  /**
   * @brief Compiles and attaches the fragment shader.
   */
  void ApplyFragmentShader();
  
  /**
   * @brief Loads and activates the shader program.
   */
  void ApplyShaders();  // TODO Temp method, should be separated
  
  /**
   * @brief Issues the draw call for the current vertex array.
   */
  void Draw();
  
  /**
   * @brief Clears the color and depth buffers.
   */
  void Clear();

  std::string shader_path_;
  std::optional<Shader> shader_;

  std::optional<VertexArray> vao_;
  std::optional<VertexBuffer> vbo_;
};
}  // namespace zem::graphics
