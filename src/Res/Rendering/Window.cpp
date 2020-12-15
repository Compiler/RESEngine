#include "Window.h"


namespace res{

    float res::Window::SCREEN_WIDTH;
    float res::Window::SCREEN_HEIGHT;
    Window::Window(float width, float height, const char* name, bool fullscreen){
         Window::SCREEN_HEIGHT = height; Window::SCREEN_WIDTH = width; _windowName = name;
         _window = glfwCreateWindow(width, height, name, NULL, NULL);
         glfwMakeContextCurrent(_window);
    
         if(!_window){
		     ERROR("!!Failed to load window!!");
	     }

    }
    void Window::setPosition(float x, float y){
		glfwSetWindowPos(_window, x, y);

    }


}