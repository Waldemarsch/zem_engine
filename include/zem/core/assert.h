//
// Created by Владимир on 03.05.2026.
//

#pragma once
#include <iostream>
#include <source_location>

#ifdef _WIN32
#define ZEM_DEBUG_BREAK() __debugbreak()
#elifdef __linux__
#define ZEM_DEBUG_BREAK() __builtin_trap()
#elifdef __APPLE__
#define ZEM_DEBUG_BREAK() __builtin_trap()
#else
#error "Platform doesn't support debugbreak yet!"
#endif

namespace zem::core {

/**
 * @brief Reports assertion failures with source location context.
 * 
 * @param expression The stringified expression that failed.
 * @param message Custom message explaining the failure.
 * @param location Automatically captured source location of the caller.
 */
inline void ReportAssertionFailure(
    const char* expression, const char* message,
    std::source_location location = std::source_location::current()) {
  std::cerr << "Assertion Failed: " << expression << "\n"
            << "Message: " << message << "\n"
            << "File: " << location.file_name() << ":" << location.line()
            << "\n"
            << "Function: " << location.function_name() << "\n";
}
}  // namespace zem::core

#ifndef NDEBUG
/**
 * @brief Runtime assertion macro. Triggers a debug break if the expression evaluates to false.
 * 
 * @param expr The boolean expression to evaluate.
 * @param msg The failure message to display if the assertion fails.
 */
#define ZEM_ASSERT(expr, msg)                        \
  do {                                               \
    if (!(expr)) {                                   \
      zem::core::ReportAssertionFailure(#expr, msg); \
      ZEM_DEBUG_BREAK();                             \
    }                                                \
  } while (false)
#else
#define ZEM_ASSERT(expr, msg)
#endif
