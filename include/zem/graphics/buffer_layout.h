//
// Created by vladimir on 5/7/26.
//

#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace zem::graphics {

enum class ShaderDataType {
  None = 0,
  Float,
  Float2,
  Float3,
  Float4,
  Int1,
  Int2,
  Int3,
  Int4,
  Bool
};

namespace utils {

[[nodiscard]] uint32_t ShaderDataTypeSize(ShaderDataType type);
[[nodiscard]] uint32_t GetComponentCount(ShaderDataType type);

}  // namespace utils

struct BufferElement {
  BufferElement(std::string name, ShaderDataType type,
                bool normalized = false);

  std::string name;
  ShaderDataType type;
  uint32_t size;
  uint32_t offset{0};
  bool normalized;
};
class BufferLayout {
 public:
  BufferLayout() = default;
  BufferLayout(std::initializer_list<BufferElement> elements);

  [[nodiscard]] uint32_t stride() const { return stride_; }
  [[nodiscard]] const std::vector<BufferElement>& elements() const {
    return elements_;
  }

  [[nodiscard]] std::vector<BufferElement>::iterator begin() {
    return elements_.begin();
  }
  [[nodiscard]] std::vector<BufferElement>::iterator end() {
    return elements_.end();
  }

  [[nodiscard]] std::vector<BufferElement>::const_iterator begin() const {
    return elements_.begin();
  }
  [[nodiscard]] std::vector<BufferElement>::const_iterator end() const {
    return elements_.end();
  }

 private:
  std::vector<BufferElement> elements_;
  uint32_t stride_{0};

  void CalculateOffsetsAndStride();
};
}  // namespace zem::graphics
