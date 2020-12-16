#pragma once
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <Res/Rendering/ShaderProgram.h>

namespace res{

    class DebugLayer : public Layer{
        private:
            ShaderProgram _shader;
        public:
            DebugLayer();
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

    };

}