module;

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

import logging;

export module window;

typedef GLFWwindow* WindowPtr;

class WindowInstanceManager {
public:
  static WindowPtr& GetWindow() {
    // Singleton
    static WindowInstanceManager windowInstanceManager;
    return windowInstanceManager._window;
  }

  WindowInstanceManager( WindowInstanceManager const& ) = delete;
  void operator=( WindowInstanceManager const& )        = delete;

private:
  WindowInstanceManager() = default;

  WindowPtr _window;
};

export bool InitWindow() {
  glfwInit();
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

  WindowPtr& window = WindowInstanceManager::GetWindow();

  window = glfwCreateWindow( 800, 600, "LearnOpenGL", nullptr, nullptr );
  if ( window == NULL ) {
    Error( "Failed to create GLFW window" );
    glfwTerminate();
  }

  glfwMakeContextCurrent( window );
  // TODO: SET RESIZE CALLBACK HERE...

  return true;
}

export bool WindowShouldClose() {
  return glfwWindowShouldClose( WindowInstanceManager::GetWindow() );
}

export bool SwapAndPoll() {
  glfwSwapBuffers( WindowInstanceManager::GetWindow() );
  glfwPollEvents();

  return true;
}

export bool DestroyWindow() {
  glfwTerminate();
  return true;
}
