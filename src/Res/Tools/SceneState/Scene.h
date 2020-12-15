#pragma once
#include <Res/res.h>
#include <Res/Tools/SceneState/LayerManager.h>
namespace res{

    class Scene{

        private:
            LayerManager _layerManager;
            const char* _name;
        public:
            Scene(){
                _name = "DEFAULT_SCENE";
            }
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;
            LayerManager& getLayerManager(){return _layerManager;}
            void setName(const char* name){_name = name;}
            inline const char* getName(){return _name;}

    };

}