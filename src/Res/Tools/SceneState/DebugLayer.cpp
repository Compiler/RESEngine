#include "DebugLayer.h"

namespace res{

    DebugLayer::DebugLayer():Layer(){}

    void DebugLayer::onLoad(){
        LOG("Loading DebugLayer");
        _shader.loadShader(RES_INTERNAL_SHADER("pass2d.vert"), RES_INTERNAL_SHADER("pass2d.frag"));

        float vertices[4*2*3] = {
           -0.5f, -0.5f, 0.0f, 1.0f,    0.3f, 0.3f, 0.3f, 1.0f,
            0.5f, -0.5f, 0.0f, 1.0f,     0.3f, 0.3f, 0.3f, 1.0f,
            0.0f,  0.5f, 0.0f, 1.0f,     0.3f, 0.3f, 0.3f, 1.0f
        };  
        glGenVertexArrays(1, &_vertexArrayID); 
        glBindVertexArray(_vertexArrayID);

        glGenBuffers(1, &_bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);  
        glEnableVertexAttribArray(1);  

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*)0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (const void*)(4 * sizeof(float)));

    }

    void DebugLayer::update(){

    }

    void DebugLayer::render(){
        _shader.use();
        glBindVertexArray(_vertexArrayID);
        glDrawArrays(GL_TRIANGLES, 0, 3);

    }

    void DebugLayer::onUnload(){

    }

}