cmake_minimum_required(VERSION 3.16)

project(opengltrain)

add_executable(opengltrain main.cpp)

add_subdirectory(external/glfw)

target_link_libraries(opengltrain PRIVATE
    glfw
)