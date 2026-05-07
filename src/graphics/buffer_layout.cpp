//
// Created by vladimir on 5/7/26.
//

#include <utility>

#include "zem/graphics/buffer_layout.h"

#include "zem/core/assert.h"

namespace zem::graphics {
uint32_t utils::ShaderDataTypeSize(ShaderDataType type) {
  switch (type) {
    case ShaderDataType::None:
      break;
    case ShaderDataType::Float:
      return 4;
    case ShaderDataType::Float2:
      return 8;
    case ShaderDataType::Float3:
      return 12;
    case ShaderDataType::Float4:
      return 16;
    case ShaderDataType::Int1:
      return 4;
    case ShaderDataType::Int2:
      return 8;
    case ShaderDataType::Int3:
      return 12;
    case ShaderDataType::Int4:
      return 16;
    case ShaderDataType::Bool:
      return 1;
  }
  ZEM_ASSERT(false, "Unknown ShaderDataType!");
  return 0;
}

uint32_t utils::GetComponentCount(ShaderDataType type) {
  switch (type) {
    case ShaderDataType::None:
      return 0;
    case ShaderDataType::Float:
      return 1;
    case ShaderDataType::Float2:
      return 2;
    case ShaderDataType::Float3:
      return 3;
    case ShaderDataType::Float4:
      return 4;
    case ShaderDataType::Int1:
      return 1;
    case ShaderDataType::Int2:
      return 2;
    case ShaderDataType::Int3:
      return 3;
    case ShaderDataType::Int4:
      return 4;
    case ShaderDataType::Bool:
      return 1;
  }
  ZEM_ASSERT(false, "Unknown ShaderDataType!");
  return 0;
}

BufferElement::BufferElement(std::string name, ShaderDataType type,
                             bool normalized)
    : name(std::move(name)),
      type(type),
      size(utils::ShaderDataTypeSize(type)),
      normalized(normalized) {}

BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements)
    : elements_(elements) {
  CalculateOffsetsAndStride();
}

void BufferLayout::CalculateOffsetsAndStride() {
  for (auto& element : elements_) {
    element.offset = stride_;
    stride_ += element.size;
  }
}
}  // namespace zem::graphics