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
