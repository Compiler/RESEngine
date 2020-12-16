#pragma once
#include <glad/glad.h>
#include <Res/res.h>
#include <Res/Rendering/Window.h>
#include <Res/Tools/Startup/StartupSystem.h>
#include <string>
#include <Res/Tools/SceneState/Scene3D.h>
#include <Res/Tools/SceneState/DebugLayer.h>
#include <Res/Tools/SceneState/SceneManager.h>
#include <imgui/imgui.h>

namespace res{

    class EngineCore{
        private:
            res::Window* _window;
            SceneManager _sceneManager;


        public:
            explicit EngineCore() = default;
            void onLoad();
            void update();
            void render();
            void onUnload();

            bool shouldClose(){return  glfwWindowShouldClose(_window->getWindow());}

    };

}