#include <stdio.h>
#include <thread>

#include <glad/glad.h>
#include <Tools/Logging/FastLogger.h>
#include <GLFW/glfw3.h>

#include <Rendering/Window.h>
#include <Tools/Startup/StartupSystem.h>

int main(){
    res::StartupSystem::_initGLFW();
    res::Window* window = new res::Window(1920, 1080, "Research Engine");
    res::StartupSystem::_initGlad();


    while(true);

    INIT_LOG("INIT LEVEL");
    LOG("LOG LEVEL");
    UNLOAD_LOG("UNLOAD LEVEL");
    WARN("WARN LEVEL");
    ERROR("ERROR LEVEL");

    return 0;

}