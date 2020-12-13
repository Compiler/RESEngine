#include <stdio.h>
#include <thread>

#include <glad/glad.h>
#include <Tools/Logging/FastLogger.h>
#include <GLFW/glfw3.h>

void function(){
    printf("Hello world!");
    
}


int main(){
    function();
    std::thread t(function);
    t.join();
    LOG("LOG Level");
    DEBUG("DEBUG Level");
    WARN("WARN Level");
    ERROR("ERROR Level");

    return 0;

}