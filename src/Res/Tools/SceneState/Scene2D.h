#pragma once
#include <res.h>
#include <Tools/SceneState/Scene.h>
namespace res{

    class Scene2D : Scene{
        private:
        

        public:
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;

    };

}