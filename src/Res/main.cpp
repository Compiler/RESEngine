#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <Res/res.h>
#include <Res/Cores/EngineCore.h>

float  res::DELTA_TIME = 0.0f;
int    res::CUR_FPS;
float  res::SCREEN_LEFT;
float  res::SCREEN_RIGHT;
float  res::SCREEN_BOTTOM;
float  res::SCREEN_TOP;
//double res::MAX_FPS = 144.0;
double res::MAX_FPS = 99999999.0;

int main(){
    
    res::EngineCore core;

    core.onLoad();

    double lastTime = glfwGetTime();
    float elapsed = 0.0f;
    int actualFPS = 0;
    while(!core.shouldClose()){
        double time = glfwGetTime();
        double deltaTime = time - lastTime;
        res::DELTA_TIME = deltaTime;
        elapsed += deltaTime;
        actualFPS = 1 / deltaTime; // delta should never = 0 but if it could we do : (deltaTime == 0 ? 0.0000001 : deltaTime);
        if(elapsed > 1){
            res::CUR_FPS = actualFPS;
            elapsed = 0;
        }
        if( deltaTime >= 1.0/res::MAX_FPS ) {
            lastTime = time;
            core.update();
            core.render();
        }
    }

    core.onUnload();
    

    return 0;

}