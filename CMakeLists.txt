cmake_minimum_required(VERSION 3.16)

project(opengltrain)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.h")

add_library(zem_physics INTERFACE)
target_include_directories(zem_physics INTERFACE "include/")

add_library(zem_math INTERFACE)
target_include_directories(zem_math INTERFACE "include/")

add_library(zem_core INTERFACE)
target_include_directories(zem_core INTERFACE "include/")

add_executable(opengltrain
        src/main.cpp
        src/physics_world.cpp
        src/internal/physics_data.h
        ${HEADERS}
)

target_include_directories(opengltrain
        PRIVATE src
        PRIVATE include
)

#add_subdirectory(vendor/glfw)
#add_subdirectory(vendor/glad)
#add_subdirectory(vendor/glm)
add_subdirectory(vendor/raylib)

target_link_libraries(opengltrain PRIVATE
        zem_math
        zem_physics
        zem_core
#        glfw
#        glad
        raylib
)

file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory

        ${CMAKE_SOURCE_DIR}/res

        $<TARGET_FILE_DIR:${PROJECT_NAME}>/res

        COMMENT "Copying resources to build directory..."
)