#include "EngineCore.h"
#include <iostream>

namespace res{
    void EngineCore::onLoad(){
        res::StartupSystem::_initGLFW();
        _window = new res::Window(1920, 1080, "Research Engine");
        res::StartupSystem::_initGlad();
        res::StartupSystem::_initImGUI(_window->getWindow());
		//_window->setPosition(2560, 360);
		glfwMakeContextCurrent( _window->getWindow() );


        auto scene = _sceneManager.emplaceScene<Scene3D>("Blinn-Phong");
        scene->getLayerManager().emplaceLayer<BlinnPhongLayer>("S1L1");
        scene->setClearColor(0.15f, 0.15f, 0.15f, 1.00f);
        auto scene2 = _sceneManager.emplaceScene<Scene3D>("Ray tracing");
        scene2->getLayerManager().emplaceLayer<DebugLayer>("S2L1");
        scene2->setClearColor(0.25f, 0.55f, 0.60f, 1.00f);
        
        _sceneManager.onLoad();



    }
    
    void EngineCore::update(){
        _sceneManager.update();
        #ifdef DEBUG_MODE
        _window->setTitle(std::string("Research Engine - fps " + std::to_string((int)res::CUR_FPS) + " - ms " + std::to_string(res::DELTA_TIME)).c_str());
        #endif

        glfwPollEvents();

    }
    
    void EngineCore::render(){


        _sceneManager.render();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(Window::SCREEN_WIDTH / 6.0f, Window::SCREEN_HEIGHT / 2.0f));
        ImGui::Begin("Rendering Scheme");
        int i = 0;
        for(const auto& scene : _sceneManager.getScenes()){
            if(ImGui::Button(scene->getName())){
                _sceneManager.setCurrentScene(i);
            }
            i++;
        }
        
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(_window->getWindow());
    }
    
    void EngineCore::onUnload(){
        UNLOAD_LOG("Unloading Engine...");
        _sceneManager.onUnload();

    }
    
}