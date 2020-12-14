#pragma once
#include <Res/res.h>
#include <Res/Rendering/Window.h>
#include <Res/Tools/Startup/StartupSystem.h>
#include <string>
namespace res{

    class EngineCore{
        private:
            res::Window* _window;

        public:
            explicit EngineCore() = default;
            void onLoad();
            void update();
            void render();
            void onUnload();

            bool shouldClose(){return  glfwWindowShouldClose(_window->getWindow());}

    };

}