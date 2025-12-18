cmake_minimum_required(VERSION 3.16)

project(opengltrain)

add_executable(opengltrain src/main.cpp
        src/graphics/shader.h
        src/graphics/shader.cpp)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

target_link_libraries(opengltrain PRIVATE
    glfw
    glad
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})