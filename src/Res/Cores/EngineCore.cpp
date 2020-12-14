#include "EngineCore.h"
namespace res{
    void EngineCore::onLoad(){
        res::StartupSystem::_initGLFW();
        _window = new res::Window(1920, 1080, "Research Engine");
        res::StartupSystem::_initGlad();

    }
    
    void EngineCore::update(){
        #ifdef DEBUG_MODE
        _window->setTitle(std::string("ENGINE - fps " + std::to_string((int)res::CUR_FPS) + " - ms " + std::to_string(res::DELTA_TIME)).c_str());
        #endif


        glfwPollEvents();

    }
    
    void EngineCore::render(){

    }
    
    void EngineCore::onUnload(){
        UNLOAD_LOG("Unloading Engine...");

    }
    
}