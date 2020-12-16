#pragma once
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <Res/Rendering/ShaderProgram.h>

namespace res{

    class DebugLayer : public Layer{
        private:
            ShaderProgram _shader;
            uint32_t _bufferID, _vertexArrayID;
        public:
            DebugLayer();
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

    };

}