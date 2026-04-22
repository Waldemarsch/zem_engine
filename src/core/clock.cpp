//
// Created by Владимир on 14.04.2026.
//

#include "../../include/zem/core/clock.h"

namespace zem::core {
Clock::Clock() :
  start_time_(std::chrono::steady_clock::now()),
  last_time_tick_(start_time_) {
}

math::Real Clock::Restart() {
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<math::Real>(now - last_time_tick_);
  last_time_tick_ = now;
  return elapsed.count();
}

math::Real Clock::GetElapsedTime() const {
  auto now = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<math::Real>(now - start_time_);
  return elapsed.count();
}
}