cmake_minimum_required(VERSION 3.28)
project(renderer)

set(CMAKE_CXX_STANDARD 26)

# Configure Dependencies
add_subdirectory(dependencies)

# Add Logging module as library
add_library(logging)
target_sources(logging PUBLIC
    FILE_SET CXX_MODULES FILES
    logging.ixx
)
target_link_libraries(logging PRIVATE
    spdlog
)

# Add Graphics module as library
add_library(graphics)
target_sources(graphics PUBLIC
    FILE_SET CXX_MODULES FILES
    graphics.ixx
)
target_link_libraries(graphics PRIVATE
    glfw
    glad
    logging
)

# Add Window module as library
add_library(window)
target_sources(window PUBLIC
    FILE_SET CXX_MODULES FILES
    window.ixx
)
target_link_libraries(window PRIVATE
    glad
    glfw
    logging
)

# Add Gui module as library
add_library(gui)
target_sources(gui PUBLIC
    FILE_SET CXX_MODULES FILES
    gui.ixx
)
target_include_directories(gui PRIVATE
    ${IMGUI_INCLUDE_DIRS}
)
target_link_libraries(gui PRIVATE
    glfw
    imgui
    logging
)

# Add executable
add_executable(renderer
    main.cpp
)
target_link_libraries(renderer PRIVATE
    glad
    glfw
    logging
    graphics
    window
    gui
)