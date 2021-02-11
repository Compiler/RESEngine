#include "BlinnPhongLayer.h"

namespace res{

    BlinnPhongLayer::BlinnPhongLayer():Layer(){}

    void BlinnPhongLayer::onLoad(){
        LOG("Loading BlinnPhongLayer");
        _shader.loadShader(RES_INTERNAL_SHADER("blinn_phong.vert"), RES_INTERNAL_SHADER("blinn_phong.frag"));
        float extent = 0.25f;
        int c = 0;
        xAxis = zAxis = yAxis = 0.0f;
        res::Cube cube;
        float vertices[6*4*3*6] = {
        -extent, -extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         extent, -extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         extent,  extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
         extent,  extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
        -extent,  extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
        -extent, -extent, -extent, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   

        -extent, -extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        extent, -extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        -extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
        -extent, -extent,  extent, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   

        -extent,  extent,  extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -extent,  extent, -extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -extent, -extent, -extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -extent, -extent, -extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -extent, -extent,  extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
        -extent,  extent,  extent, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   

        extent,  extent,  extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        extent,  extent, -extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        extent, -extent, -extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        extent, -extent, -extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        extent, -extent,  extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        extent,  extent,  extent, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
    
        -extent, -extent, -extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         extent, -extent, -extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         extent, -extent,  extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
         extent, -extent,  extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
        -extent, -extent,  extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
        -extent, -extent, -extent, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   

        -extent,  extent, -extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         extent,  extent, -extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
         extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
        -extent,  extent,  extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
        -extent,  extent, -extent, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f
        };  
        glGenVertexArrays(1, &_vertexArrayID); 
        glBindVertexArray(_vertexArrayID);

    
        SceneVerticeTuples tuple;
        glGenBuffers(1, &_bufferID);
        glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(tuple.cube_plane_scene), tuple.cube_plane_scene, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);  
        glEnableVertexAttribArray(1);  
        glEnableVertexAttribArray(2);  

        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(4 * sizeof(float)));
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (const void*)(8 * sizeof(float)));

        trans = glm::mat4(1.0f);
        trans = glm::rotate(trans, glm::radians(-45.0f), glm::vec3(1.0, 0.0, 0.0));
        trans = glm::rotate(trans, glm::radians(-15.0f), glm::vec3(1.0, 1.0, 0.0));

        

    } 

    void BlinnPhongLayer::update(){
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_UP)) yAxis += 1.01f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_DOWN)) yAxis -= 1.01f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_RIGHT)) xAxis += 1.01f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_LEFT)) xAxis -= 1.01f * res::DELTA_TIME;
        trans = glm::rotate(trans, glm::radians(xAxis), glm::vec3(1.0, 0.0, 0.0));
        trans = glm::rotate(trans, glm::radians(yAxis), glm::vec3(0.0, 1.0, 0.0));
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_W)) yPos += 0.1f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_S)) yPos -= 0.1f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_D)) zPos += 0.1f * res::DELTA_TIME;
        if(res::InputManager::isKeyPressed(KeyCodes::KEY_A)) zPos -= 0.1f * res::DELTA_TIME;
    }

    void BlinnPhongLayer::render(){
        static float elapsed = 0;
        static float count = 0;
        static float smoothStep = 0.0f;
        smoothStep += res::DELTA_TIME;
        elapsed += res::DELTA_TIME;
        xPos = sin(smoothStep) * 1.0f;
        if(elapsed > 1){
            count++;
            elapsed = 0;
        }

        

        _shader.use();
        _shader.uniform_set1Mat4("u_transform", &trans[0][0]);
        _shader.uniform_set1Float("ux", xPos);
        _shader.uniform_set1Float("uy", yPos);
        _shader.uniform_set1Float("uz", zPos);
        glBindVertexArray(_vertexArrayID);
        glDrawArrays(GL_TRIANGLES, 0, 42);

    }

    void BlinnPhongLayer::onUnload(){
        UNLOAD_LOG("Unloading BlinnPhongLayer '%s'", m_name);


    }

}