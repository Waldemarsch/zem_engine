//
// Created by val on 16/01/2026.
//

#ifndef OPENGLTRAIN_BUFFER_H
#define OPENGLTRAIN_BUFFER_H
#include <vector>

#include "glad/glad.h"

namespace zem::graphics {
/**
 * @class VertexBuffer
 * @brief Represents an OpenGL Vertex Buffer Object (VBO).
 *
 * Handles the allocation and uploading of vertex data to GPU memory.
 */
class VertexBuffer {
 public:
  /**
   * @brief Constructs a new Vertex Buffer and uploads data to the GPU.
   * @param vertices The raw vertex data to upload.
   */
  explicit VertexBuffer(const std::vector<GLfloat>& vertices);

  ~VertexBuffer();

  VertexBuffer(const VertexBuffer& other) = delete;
  VertexBuffer& operator=(const VertexBuffer& other) = delete;

  VertexBuffer(VertexBuffer&& other) noexcept;
  VertexBuffer& operator=(VertexBuffer&& other) noexcept;

  /**
   * @brief Binds the buffer to the current OpenGL context.
   */
  void Bind() const;

  /**
   * @brief Unbinds the current buffer.
   */
  void Unbind();

 private:
  GLuint id_{0};
};
}  // namespace zem::graphics

#endif  // OPENGLTRAIN_BUFFER_H
