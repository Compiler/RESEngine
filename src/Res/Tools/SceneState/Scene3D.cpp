#include "Scene3D.h"

namespace res{

    Scene3D::Scene3D(){}

    void Scene3D::onLoad(){
        m_layerManager.onLoad();

    }

    void Scene3D::update(){

        m_layerManager.update();
    }

    void Scene3D::render(){
        glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT);

        m_layerManager.render();
    }

    void Scene3D::onUnload(){
        UNLOAD_LOG("Unloading Scene3D '%s'", m_name);
        m_layerManager.onUnload();
    }


}