include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG "master"
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glfw
)

FetchContent_MakeAvailable(glfw)
