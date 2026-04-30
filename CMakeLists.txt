cmake_minimum_required(VERSION 3.24)

project(zem_engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_UNITTESTS OFF CACHE BOOL "" FORCE)
set(TARGET_HELLO_WORLD OFF CACHE BOOL "" FORCE)
set(TARGET_PERFORMANCE_TEST OFF CACHE BOOL "" FORCE)
set(INTERPROCEDURAL_OPTIMIZATION ON CACHE BOOL "" FORCE)
set(DOUBLE_PRECISION OFF CACHE BOOL "" FORCE)
set(CPP_EXCEPTIONS_ENABLED OFF CACHE BOOL "" FORCE)
set(CPP_RTTI_ENABLED OFF CACHE BOOL "" FORCE)


set(USE_SSE4_1 ON CACHE BOOL "" FORCE)
set(USE_SSE4_2 ON CACHE BOOL "" FORCE)
set(USE_AVX ON CACHE BOOL "" FORCE)
set(USE_AVX2 ON CACHE BOOL "" FORCE)

include(FetchContent)

FetchContent_Declare(
        JoltPhysics
        GIT_REPOSITORY https://github.com/jrouwe/JoltPhysics.git
        GIT_TAG v5.5.0
        SOURCE_SUBDIR Build
)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.3
)

FetchContent_MakeAvailable(JoltPhysics glfw glm)

add_subdirectory(vendor/glad)

add_library(zem_physics INTERFACE)
target_include_directories(zem_physics INTERFACE "include/")
target_link_libraries(zem_physics INTERFACE Jolt)

add_library(zem_math INTERFACE)
target_include_directories(zem_math INTERFACE "include/")
target_link_libraries(zem_math INTERFACE glm)


add_library(zem_graphics STATIC
        src/graphics/buffer.cpp
        src/graphics/shader.cpp
        src/graphics/vertex_array.cpp
        src/graphics/renderer_open_gl.cpp
        include/zem/graphics/renderer_open_gl.h)
target_include_directories(zem_graphics PUBLIC "include/")
target_link_libraries(zem_graphics PUBLIC glfw glad)

add_library(zem_core STATIC
        src/core/application.cpp
        src/core/clock.cpp
        src/core/window.cpp
)
target_include_directories(zem_core PUBLIC "include/")
target_link_libraries(zem_core PUBLIC zem_physics zem_graphics zem_math)

add_executable(zem_engine src/main.cpp)

target_link_libraries(opengltrain PRIVATE
        zem_core
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory

        ${CMAKE_SOURCE_DIR}/res

        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res

        COMMENT "Copying resources to build directory..."
)