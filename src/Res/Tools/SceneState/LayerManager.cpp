#include "LayerManager.h"

namespace res{


    LayerManager::LayerManager(){
        _currentLayer = -1;
    }
    void LayerManager::onLoad(){
        _layers[_currentLayer]->onLoad();
    }

    void LayerManager::update(){
        _layers[_currentLayer]->update();
    }

    void LayerManager::render(){
        _layers[_currentLayer]->render();
    }


    void LayerManager::setCurrentLayer(int layerIndex){
        if(layerIndex == _currentLayer) return;
        if(layerIndex < _layers.size() && layerIndex >= 0){
            LOG("Swapped from '%s' to '%s'", _layers[_currentLayer]->getName(), _layers[layerIndex]->getName());
            _currentLayer = layerIndex;
        }else{
            WARN("Layer not set: %d out of bounds", layerIndex);
        }

    }

    Layer& LayerManager::getCurrentLayer(){
        if(_currentLayer == -1){
            ERROR("Requested currentLayer but it isnt set");
        }
        return *_layers[_currentLayer];
     }

    Layer& LayerManager::getLayer(int index){
        if(index < 0 && index >= _layers.size()){
            ERROR("getIndex failed, '%d' out of bounds", index);
        }
        return *_layers[index];
    }


}