//
// Created by Владимир on 03.05.2026.
//

#pragma once

namespace zem::core {
class PlatformContext {
 public:
  PlatformContext();
  ~PlatformContext();

  PlatformContext(const PlatformContext& other) = delete;
  PlatformContext& operator=(const PlatformContext& other) = delete;
};
}  // namespace zem::core
