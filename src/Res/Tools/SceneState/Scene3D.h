#pragma once
#include <Res/Tools/SceneState/Scene.h>

namespace res{

    class Scene3D : public Scene{
        private:
            

        public:
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

    };

}