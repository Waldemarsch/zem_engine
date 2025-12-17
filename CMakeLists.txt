cmake_minimum_required(VERSION 3.16)

project(opengltrain)

add_executable(opengltrain src/main.cpp
        src/graphics/shader.h)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

target_link_libraries(opengltrain PRIVATE
    glfw
    glad
)