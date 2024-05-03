cmake_minimum_required(VERSION 3.28)
project(renderer)

set(CMAKE_CXX_STANDARD 26)

# Configure Dependencies
add_subdirectory(dependencies)

# Add module as library
add_library(graphics)
target_sources(graphics PUBLIC
    FILE_SET CXX_MODULES FILES
    graphics.ixx
)
target_link_libraries(graphics PRIVATE
    glfw
    glad
    spdlog
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(renderer
    main.cpp
)
target_link_libraries(renderer PRIVATE
    glad
    glfw
    spdlog
    graphics
)
