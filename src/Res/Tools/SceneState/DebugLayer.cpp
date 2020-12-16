#include "DebugLayer.h"

namespace res{

    DebugLayer::DebugLayer():Layer(){}

    void DebugLayer::onLoad(){
        _shader.loadShader(RES_INTERNAL_SHADER("pass2d.vert"), RES_INTERNAL_SHADER("pass2d.frag"));
    }

    void DebugLayer::update(){

    }

    void DebugLayer::render(){

    }

    void DebugLayer::onUnload(){

    }

}