cmake_minimum_required(VERSION 3.23)
project(gravityLab3D)

# specify C++ standard
if(ENABLE_CXX_20)
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

find_package(OpenGL REQUIRED)

add_subdirectory(libs/glfw-3.4)
add_subdirectory(libs/glm)

add_library(glad
    libs/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_SOURCE_DIR}/libs/glad/include
)

add_executable(gravityLab3D
    main.cpp
)

target_link_libraries(gravityLab3D
    PRIVATE
        glfw
        glm
        glad
        OpenGL::GL
)