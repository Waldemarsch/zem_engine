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
        src/graphics/opengl_context.cpp
)
target_include_directories(zem_graphics PRIVATE "include/")
target_link_libraries(zem_graphics PRIVATE glfw glad)

add_library(zem_core STATIC
        src/core/application.cpp
        src/core/clock.cpp
        src/core/window.cpp
        src/core/platform_context.cpp
)
target_include_directories(zem_core PUBLIC "include/")
target_link_libraries(zem_core PUBLIC zem_physics zem_graphics zem_math glfw glad)

add_executable(zem_engine src/main.cpp)

target_link_libraries(zem_engine PRIVATE
        zem_core
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory

        ${CMAKE_SOURCE_DIR}/res

        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res

        COMMENT "Copying resources to build directory..."
)

# Doxygen target
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    
    add_custom_target(zem_docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else()
    message(WARNING "Doxygen need to be installed to generate the doxygen documentation")
endif()
