#pragma once 
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <vector>
namespace res{

    class LayerManager{
        private:
            std::vector<Layer> _layers;
            int _currentLayer;

        public:
            LayerManager();
            Layer* emplaceLayer();
            Layer* emplaceLayer(const char* name);
            Layer& getCurrentLayer();
            Layer& getLayer(int index);
            void setCurrentLayer(int layerIndex);
        


    };

}