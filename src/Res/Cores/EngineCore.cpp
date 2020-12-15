#include "EngineCore.h"
namespace res{
    void EngineCore::onLoad(){
        res::StartupSystem::_initGLFW();
        _window = new res::Window(1920, 1080, "Research Engine");
        res::StartupSystem::_initGlad();

        auto scene = _sceneManager.emplaceScene("Scene1");
        scene->getLayerManager().emplaceLayer("S1L1");
        scene->getLayerManager().emplaceLayer("S1L2");
        auto scene2 = _sceneManager.emplaceScene("Scene2");
        scene2->getLayerManager().emplaceLayer("S2L1");
        scene2->getLayerManager().emplaceLayer("S2L2");
        LOG("Scene : '%s'", _sceneManager.getCurrentScene().getName());
        LOG("\tLayer: '%s'", _sceneManager.getCurrentScene().getLayerManager().getCurrentLayer());
        LOG("\tLayer: '%s'", _sceneManager.getCurrentScene().getLayerManager().getLayer(1));

        LOG("Scene : '%s'", _sceneManager.getScene(1).getName());
        LOG("\tLayer: '%s'", _sceneManager.getScene(1).getLayerManager().getCurrentLayer());
        LOG("\tLayer: '%s'", _sceneManager.getScene(1).getLayerManager().getLayer(1));
        

        

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