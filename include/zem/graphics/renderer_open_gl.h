//
// Created by Владимир on 25.04.2026.
//

#pragma once
#include <string>

#include "renderer.h"

namespace zem::graphics {
class RendererOpenGL : public Renderer {
 public:
  explicit RendererOpenGL(std::string shader_path);

  void Init() override;
  void Render() override;

 private:
  void Draw(const Shader& shader, const VertexArray& vao);
  void Clear();

  std::string shader_path_;
};
}  // namespace zem::graphics
