#pragma once 
#include <Res/res.h>
#include <Res/Tools/SceneState/Layer.h>
#include <vector>
namespace res{

    class LayerManager{
        private:
            std::vector<Layer> _layers;

        public:
            LayerManager();
            Layer* emplaceLayer();
            Layer* emplaceLayer(const char* name);
        


    };

}