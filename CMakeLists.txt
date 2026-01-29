cmake_minimum_required(VERSION 3.16)

project(opengltrain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

add_library(zem_physics INTERFACE)
target_include_directories(zem_physics INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_library(zem_math INTERFACE)
target_include_directories(zem_math INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

add_executable(opengltrain ${SOURCES}
        src/core/window.h
)

target_include_directories(opengltrain
        PRIVATE src
        PRIVATE include
)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glm)

target_link_libraries(opengltrain PRIVATE
        zem_math
        zem_physics
        glfw
        glad
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory

        ${CMAKE_SOURCE_DIR}/res

        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res

        COMMENT "Copying resources to build directory..."
)