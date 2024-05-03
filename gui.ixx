module;

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


export module gui;

export void InitializeGui(GLFWwindow* mWindow) {
  ImGui::CreateContext();
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL( mWindow, true );
  ImGui_ImplOpenGL3_Init( "#version 330" );
}