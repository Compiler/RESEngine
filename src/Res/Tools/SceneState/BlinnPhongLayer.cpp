#include "BlinnPhongLayer.h"

namespace res{

    BlinnPhongLayer::BlinnPhongLayer():Layer(){}

    void BlinnPhongLayer::onLoad(){
        LOG("Loading BlinnPhongLayer");
        _shader.loadShader(RES_INTERNAL_SHADER("blinn_phong.vert"), RES_INTERNAL_SHADER("blinn_phong.frag"));
        float extent = 0.5f;
        int c = 0;
        float vertices[6*4*3*6] = {
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
        -0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   

        -0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
         0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        -0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        -0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   

        -0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   

         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
         0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
         0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
         0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
         0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
    
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
        -0.5f, -0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
        -0.5f, -0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   

        -0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
        -0.5f,  0.5f,  0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
        -0.5f,  0.5f, -0.5f, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f
        };  
        glGenVertexArrays(1, &_vertexArrayID); 
        glBindVertexArray(_vertexArrayID);

        glGenBuffers(1, &_bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);  
        glEnableVertexAttribArray(1);  

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(4 * sizeof(float)));
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(8 * sizeof(float)));

        trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5)); 

        

    }

    void BlinnPhongLayer::update(){

    }

    void BlinnPhongLayer::render(){
        _shader.use();
        _shader.uniform_set1Mat4("u_transform", glm::value_ptr(trans));
        glBindVertexArray(_vertexArrayID);
        glDrawArrays(GL_TRIANGLES, 0, 36);

    }

    void BlinnPhongLayer::onUnload(){
        UNLOAD_LOG("Unloading BlinnPhongLayer '%s'", m_name);


    }

}