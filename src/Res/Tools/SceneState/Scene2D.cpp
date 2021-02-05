#include "Scene2D.h"

namespace res{

    Scene2D::Scene2D(){}

    void Scene2D::onLoad(){
        m_layerManager.onLoad();

    }

    void Scene2D::update(){

        m_layerManager.update();
    }

    void Scene2D::render(){
        glClearColor(m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_layerManager.render();
    }

    void Scene2D::onUnload(){
        UNLOAD_LOG("Unloading Scene2D '%s'", m_name);
        m_layerManager.onUnload();


    }


}