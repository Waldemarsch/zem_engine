cmake_minimum_required(VERSION 3.16)

project(opengltrain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

add_executable(opengltrain ${SOURCES})

target_include_directories(opengltrain PRIVATE src)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

target_link_libraries(opengltrain PRIVATE
    glfw
    glad
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})