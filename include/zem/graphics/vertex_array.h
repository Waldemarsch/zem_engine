//
// Created by val on 22/12/2025.
//

#pragma once

#include "buffer.h"
#include "glad/glad.h"

namespace zem::graphics {
/**
 * @class VertexArray
 * @brief Represents an OpenGL Vertex Array Object (VAO).
 * 
 * Manages the state of vertex attribute configurations and buffer bindings.
 */
class VertexArray {
 public:
  /**
   * @brief Constructs a new Vertex Array Object on the GPU.
   */
  VertexArray();
  ~VertexArray();

  VertexArray(const VertexArray& other) = delete;
  VertexArray& operator=(const VertexArray& other) = delete;

  VertexArray(VertexArray&& other) noexcept;
  VertexArray& operator=(VertexArray&& other) noexcept;

  /**
   * @brief Binds the VAO to the current OpenGL context.
   */
  void Bind() const;

  /**
   * @brief Unbinds the VAO.
   */
  void Unbind();

  /**
   * @brief Configures vertex attribute pointers for the bound buffers.
   */
  void AddVertexAttribPointer() const;

 private:
  GLuint id_{0};
};
}  // namespace zem::graphics
