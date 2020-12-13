#include <Cores/EngineCore.h>



int main(){
    
    res::EngineCore core;

    core.onLoad();

    while(!core.shouldClose()){
        core.update();
        core.render();
    }

    core.onUnload();
    

    return 0;

}