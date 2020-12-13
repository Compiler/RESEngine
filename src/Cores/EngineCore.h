#pragma once
#include <res.h>
#include <Cores/Core.h>
#include <Rendering/Window.h>
#include <Tools/Startup/StartupSystem.h>
#include <string>
namespace res{

    class EngineCore : public Core{
        private:
            res::Window* _window;

        public:
            explicit EngineCore() = default;
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

            bool shouldClose(){return  glfwWindowShouldClose(_window->getWindow());}

    };

}