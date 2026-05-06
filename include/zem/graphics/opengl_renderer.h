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
 * @class OpenGLRenderer
 * @brief OpenGL implementation of the Renderer interface.
 */
class OpenGLRenderer : public Renderer {
 public:
  /**
   * @brief Constructs an OpenGL renderer.
   * @param shader_path Base directory path for shader source files.
   */
  explicit OpenGLRenderer(std::string shader_path);

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

  std::shared_ptr<Shader> shader_;
  std::shared_ptr<VertexArray> vao_;
  std::shared_ptr<VertexBuffer> vbo_;
};
}  // namespace zem::graphics
