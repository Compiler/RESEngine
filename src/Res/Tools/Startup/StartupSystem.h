#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <Res/Tools/Logging/FastLogger.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
namespace res{
    //static class
    class StartupSystem{
        public:
            static void _initGLFW();
            static void _initGlad();
            static void _initImGUI(GLFWwindow* window);
            StartupSystem() = delete;
            StartupSystem operator=(const StartupSystem&) = delete;
            static void initSubSystems();
    };
}