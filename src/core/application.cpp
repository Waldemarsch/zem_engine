//
// Created by Владимир on 14.04.2026.
//

#include "zem/core/application.h"

#include "zem/core/window.h"

zem::core::Application::Application()
    : window_(std::make_unique<Window>()) {}

