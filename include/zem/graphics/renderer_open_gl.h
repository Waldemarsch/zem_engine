//
// Created by Владимир on 25.04.2026.
//

#pragma once
#include <optional>
#include <string>

#include "renderer.h"
#include "shader.h"

namespace zem::graphics {
class RendererOpenGL : public Renderer {
 public:
  explicit RendererOpenGL(std::string shader_path);

  void Init() override;
  void Render() override;

 private:
  void VertexSpecification();
  void ApplyVertexShader();
  void ApplyFragmentShader();
  void ApplyShaders();  // TODO Temp method, should be separated
  void Draw();
  void Clear();

  std::string shader_path_;
  std::optional<Shader> shader_;

  std::optional<VertexArray> vao_;
  std::optional<VertexBuffer> vbo_;
};
}  // namespace zem::graphics
