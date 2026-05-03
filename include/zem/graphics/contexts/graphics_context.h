//
// Created by Владимир on 03.05.2026.
//

#pragma once

namespace zem::graphics {
class GraphicsContext {
 public:
  virtual ~GraphicsContext() = default;

  virtual void Init() = 0;
  virtual void SwapBuffers() = 0;
};
}  // namespace zem::graphics
