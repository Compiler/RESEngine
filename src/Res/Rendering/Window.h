#pragma once
#include <Res/res.h>
#include <GLFW/glfw3.h>

namespace res{

    class Window{

        private:
            const char* _windowName;
            GLFWwindow* _window;
        public:
            static float SCREEN_WIDTH;
            static float SCREEN_HEIGHT;

            Window() = default;
            Window(float width, float height, const char* name, bool fullscreen = false);
            
            void setTitle(const char* title){glfwSetWindowTitle(_window, title);}
            void setPosition(float x, float y);
            GLFWwindow* getWindow()const{return _window;}

    };


}