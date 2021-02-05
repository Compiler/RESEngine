#include "Layer.h"

namespace res{

    uint32_t Layer::m_LAYER_COUNT = 0;

    Layer::Layer(){
        m_name  = "DEFAULT_NAMED_LAYER" + m_LAYER_COUNT++;
    }
    Layer::Layer(const char* name):m_name(name){

    }
    void Layer::setName(const char* name){
        m_name = name;
    }

}