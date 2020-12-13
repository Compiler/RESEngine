#include <stdio.h>
#include <thread>

#include <glad/glad.h>
#include <Tools/Logging/FastLogger.h>
#include <GLFW/glfw3.h>


int main(){
    LOG("l Level");
    DEBUG("d Level");
    WARN("w Level");
    ERROR("e Level");

    return 0;

}