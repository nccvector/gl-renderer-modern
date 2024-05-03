module;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "logging.h"

export module graphics;

export bool InitializeOpenGL() {
  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if ( !gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress ) ) {
//    ERROR( "Could not load GLAD" );
//    SPDLOG_LOGGER_ERROR( spdlog::default_logger_raw(), "Could not load GLAD" );
    return false;
  }

  // Configure opengl depth settings
  glClearColor( 0.025f, 0.015f, 0.015f, 1.0f );
  glEnable( GL_DEPTH_TEST ); // ENABLE DEPTH
                             //    glEnable( GL_SCISSOR_TEST );  // Causes rectangle scissor on glfw window
  glEnable( GL_BLEND );
  glDepthFunc( GL_LEQUAL );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

  // Cull settings
  glEnable( GL_CULL_FACE );
  glCullFace( GL_BACK );
  glFrontFace( GL_CCW );

  return true;
}
