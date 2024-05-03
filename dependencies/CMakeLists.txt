include(FetchContent)

# ================================================================================
# Add GLFW
# ================================================================================
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG "master"
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glfw
)

FetchContent_MakeAvailable(glfw)
# ================================================================================

# ================================================================================
# SPDLOG
# ================================================================================
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG "master"
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/spdlog
)

FetchContent_MakeAvailable(spdlog)
# ================================================================================

# ================================================================================
# IMGUI
# ================================================================================
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG "docking"
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui
)

FetchContent_MakeAvailable(imgui)

set(IMGUI_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
)
set(IMGUI_INCLUDE_DIRS ${IMGUI_INCLUDE_DIRS} CACHE INTERNAL "IMGUI INCLUDE PATHS")
add_library(imgui)
target_include_directories(imgui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
)
target_sources(imgui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_demo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_widgets.cpp
)
target_sources(imgui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_opengl3.cpp
)
target_link_libraries(imgui PRIVATE glfw)
# ================================================================================

# ================================================================================
# GLAD
# ================================================================================
set(GLAD_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/glad/include CACHE INTERNAL "GLAD INCLUDE PATH")
add_library(glad)
target_include_directories(glad PUBLIC
    ${GLAD_INCLUDE_DIRS}
)
target_sources(glad PUBLIC
    glad/src/glad.c
)
# ================================================================================
