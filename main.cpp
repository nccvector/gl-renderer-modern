#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

import logging;
import graphics;
import window;

int main() {
  Debug( "Application Entry Point" );

  InitWindow();
  InitOpenGL();

  while ( !WindowShouldClose() ) {
    // input
    // -----
    // processInput();

    // render
    // ------
    ClearBackground();

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    SwapAndPoll();
  }

  DestroyWindow();

  return 0;
}