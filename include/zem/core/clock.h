//
// Created by Владимир on 14.04.2026.
//

#ifndef OPENGLTRAIN_CLOCK_H
#define OPENGLTRAIN_CLOCK_H
#include <chrono>

#include "zem/math/precision.h"


namespace zem::core {
class Clock {
public:

  Clock();

  math::Real Restart();

  [[nodiscard]] math::Real GetElapsedTime() const;

private:
  using TimePoint = std::chrono::steady_clock::time_point;

  TimePoint start_time_;
  TimePoint last_time_tick_;
};
} // namespace zem::core

#endif  // OPENGLTRAIN_CLOCK_H