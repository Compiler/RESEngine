#include <stdio.h>
#include <thread>

#include <glad/glad.h>
#include <Tools/Logging/FastLogger.h>
#include <GLFW/glfw3.h>


int main(){
    INIT("INIT LEVEL");
    LOG("LOG LEVEL");
    UNLOAD("UNLOAD LEVEL");
    WARN("WARN LEVEL");
    ERROR("ERROR LEVEL");

    return 0;

}