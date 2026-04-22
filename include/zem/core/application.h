//
// Created by Владимир on 14.04.2026.
//

#ifndef OPENGLTRAIN_APPLICATION_H
#define OPENGLTRAIN_APPLICATION_H
#include "clock.h"
#include "zem/math/precision.h"


namespace zem::core {
class Application {
public:
  Application();
  virtual ~Application();

  Application(const Application& other) = delete;
  Application& operator=(const Application& other) = delete;

  void Run();
  void Close();

private:
  void ProcessInput();
  void Update(math::Real dt);
  void Render();


  // TODO Renderer
  Clock clock_;

  bool is_running_ = false;
};
} // namespace zem::core


#endif //OPENGLTRAIN_APPLICATION_H