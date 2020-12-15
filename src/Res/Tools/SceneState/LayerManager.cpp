#include "LayerManager.h"

namespace res{


    LayerManager::LayerManager(){

    }
    Layer* LayerManager::emplaceLayer(){
        _layers.emplace_back(Layer());
        if(_layers.size() == 1) _currentLayer = &_layers.back();
        return &_layers.back();
    }
    
    Layer* LayerManager::emplaceLayer(const char* name){
        _layers.emplace_back(Layer(name));
        if(_layers.size() == 1) _currentLayer = &_layers.back();
        return &_layers.back();
    }

    void LayerManager::setCurrentLayer(int layerIndex){
        if(layerIndex < _layers.size() && layerIndex >= 0){
            _currentLayer = &_layers[layerIndex];
        }else{
            WARN("Layer not set: %d out of bounds", layerIndex);
        }

    }


     Layer& LayerManager::getCurrentLayer(){
        if(_currentLayer == nullptr) WARN("Requested currentLayer but it is nullptr");
        return (*_currentLayer);
     }


}