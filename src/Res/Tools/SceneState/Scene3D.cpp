#include "Scene3D.h"

namespace res{

    Scene3D::Scene3D(){}

    void Scene3D::onLoad(){

    }

    void Scene3D::update(){

    }

    void Scene3D::render(){
        glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Scene3D::onUnload(){

    }


}