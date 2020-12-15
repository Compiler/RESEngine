#include "EngineCore.h"
namespace res{
    void EngineCore::onLoad(){
        res::StartupSystem::_initGLFW();
        _window = new res::Window(1920, 1080, "Research Engine");
        res::StartupSystem::_initGlad();
		glfwSetWindowPos(_window->getWindow(), 2560, 360);
		glfwMakeContextCurrent( _window->getWindow() );

        auto scene = _sceneManager.emplaceScene("Scene1");
        scene->getLayerManager().emplaceLayer("S1L1");
        scene->getLayerManager().emplaceLayer("S1L2");
        auto scene2 = _sceneManager.emplaceScene("Scene2");
        scene2->getLayerManager().emplaceLayer("S2L1");
        scene2->getLayerManager().emplaceLayer("S2L2");
        
        _sceneManager.onLoad();


        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(_window->getWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 460");
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        

        

    }
    
    void EngineCore::update(){
        _sceneManager.update();
        #ifdef DEBUG_MODE
        _window->setTitle(std::string("ENGINE - fps " + std::to_string((int)res::CUR_FPS) + " - ms " + std::to_string(res::DELTA_TIME)).c_str());
        #endif

        glfwPollEvents();

    }
    
    void EngineCore::render(){
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        _sceneManager.render();

         // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(Window::SCREEN_WIDTH / 6.0f, Window::SCREEN_HEIGHT / 2.0f));
        ImGui::Begin("Demo window");
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

    }
    
}