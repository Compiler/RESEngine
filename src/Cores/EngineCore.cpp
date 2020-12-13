#include "EngineCore.h"
namespace res{
    void EngineCore::onLoad(){
        res::StartupSystem::_initGLFW();
        _window = new res::Window(1920, 1080, "Research Engine");
        res::StartupSystem::_initGlad();

    }
    
    void EngineCore::update(){



        glfwPollEvents();

    }
    
    void EngineCore::render(){

    }
    
    void EngineCore::onUnload(){
        UNLOAD_LOG("Unloading Engine...");

    }
    
}