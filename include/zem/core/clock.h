//
// Created by Владимир on 14.04.2026.
//

#pragma once

#include <chrono>

#include "zem/math/precision.h"

namespace zem::core {
/**
 * @class Clock
 * @brief High-resolution timer for calculating delta time.
 */
class Clock {
 public:
  Clock();

  /**
   * @brief Restarts the clock and returns the elapsed time since the last tick.
   * @return The elapsed time in seconds.
   */
  math::Real Restart();

  /**
   * @brief Gets the elapsed time since the last tick without restarting the clock.
   * @return The elapsed time in seconds.
   */
  [[nodiscard]] math::Real GetElapsedTime() const;

 private:
  using TimePoint = std::chrono::steady_clock::time_point;

  TimePoint start_time_;
  TimePoint last_time_tick_;
};
}  // namespace zem::core