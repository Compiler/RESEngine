#pragma once 
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <vector>
namespace res{

    class LayerManager{
        private:
            std::vector<Layer> _layers;
            Layer* _currentLayer;

        public:
            LayerManager();
            Layer* emplaceLayer();
            Layer* emplaceLayer(const char* name);
            Layer& getCurrentLayer();

            void setCurrentLayer(int layerIndex);
        


    };

}