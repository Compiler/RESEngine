#include "Layer.h"

namespace res{

    uint32_t Layer::_LAYER_COUNT = 0;

    Layer::Layer(){
        _name  = "DEFAULT_NAMED_LAYER" + _LAYER_COUNT++;
    }
    Layer::Layer(const char* name):_name(name){

    }
    void Layer::setName(const char* name){
        _name = name;
    }

}