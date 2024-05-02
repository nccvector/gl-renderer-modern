cmake_minimum_required(VERSION 3.28)
project(renderer)

set(CMAKE_CXX_STANDARD 26)

# Configure Dependencies
add_subdirectory(dependencies)

## Add module as library
#add_library(modmod)
#target_sources(modmod PUBLIC
#    FILE_SET CXX_MODULES FILES
#    modmod.ixx
#)

include_directories(
    ${GLFW_INCLUDE_DIRS}    # must have been set as CACHE INTERNAL by the 3rdparty cmake
)

add_executable(renderer
    main.cpp
)
target_link_libraries(renderer PRIVATE glfw)