//
// Created by val on 17/12/2025.
//

#pragma once

#include <memory>
#include <string>

namespace zem::graphics {

class Shader {
 public:
  virtual ~Shader() = default;

  virtual void Use() const = 0;

  virtual void Unuse() const = 0;

  virtual void SetFloat(const std::string& name, float value) const = 0;

  virtual void SetInt(const std::string& name, int value) const = 0;

  static std::shared_ptr<Shader> Create(const std::string& vertex_path,
                                        const std::string& fragment_path);
};
}  // namespace zem::graphics
