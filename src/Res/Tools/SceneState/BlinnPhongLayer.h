#pragma once
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <Res/Rendering/ShaderProgram.h>
#include <Res/Rendering/Geometry/Cube.h>
#include <Res/Tools/Input/InputManager.h>
#include <Res/Tools/Logging/FastLogger.h>



#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace res{

    class BlinnPhongLayer : public Layer{
        private:
            ShaderProgram _shader;
            uint32_t _bufferID, _vertexArrayID;
            glm::mat4 trans;
            float yAxis, xAxis, zAxis;
            float xPos, yPos = 1, zPos = -2;

        public:
            BlinnPhongLayer();
            virtual void onLoad() override;
            virtual void update() override;
            virtual void render() override;
            virtual void onUnload() override;

    };

}