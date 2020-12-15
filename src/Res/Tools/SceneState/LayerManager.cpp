#include "LayerManager.h"

namespace res{


    LayerManager::LayerManager(){

    }
    Layer* LayerManager::emplaceLayer(){
        _layers.emplace_back(Layer());
        return &_layers.back();
    }
    
    Layer* LayerManager::emplaceLayer(const char* name){
        _layers.emplace_back(Layer(name));
        return &_layers.back();
    }

}