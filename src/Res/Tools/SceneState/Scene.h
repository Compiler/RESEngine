#pragma once
#include <Res/res.h>
#include <glfw/glfw3.h>
#include <glm/vec4.hpp>
#include <Res/Tools/SceneState/LayerManager.h>
namespace res{

    class Scene{

        protected:
            LayerManager m_layerManager;
            const char* m_name;
            glm::vec4 m_clearColor;
        public:
            Scene(){
                m_name = "DEFAULT_SCENE";
                m_clearColor = glm::vec4(0.45f, 0.55f, 0.60f, 1.00f);
            }
            Scene(const char* name){
                m_name = name;
                m_clearColor = glm::vec4(0.45f, 0.55f, 0.60f, 1.00f);
            }
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;
            LayerManager& getLayerManager(){return m_layerManager;}
            void setName(const char* name){m_name = name;}
            inline const char* getName(){return m_name;}
            void setClearColor(float r, float g, float b, float a){m_clearColor = glm::vec4(r,g,b,a);}
            void setClearColor(glm::vec4 newColor){m_clearColor = newColor;}

    };

}