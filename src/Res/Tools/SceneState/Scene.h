#pragma once
#include <Res/res.h>
#include <Res/Tools/SceneState/LayerManager.h>
namespace res{

    class Scene{

        private:
            LayerManager _layerManager;

        public:
            virtual void onLoad() = 0;
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void onUnload() = 0;
            LayerManger& getLayerManager(){return _layerManager;}

    };

}