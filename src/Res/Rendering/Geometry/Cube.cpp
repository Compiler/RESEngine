#include "Cube.h"

namespace res{

    uint8_t Cube::TOP_BACK_LEFT =       0;
    uint8_t Cube::TOP_BACK_RIGHT =      1;
    uint8_t Cube::TOP_FRONT_LEFT =      2;
    uint8_t Cube::TOP_FRONT_RIGHT =     3;
    uint8_t Cube::BOTTOM_BACK_LEFT =    4;
    uint8_t Cube::BOTTOM_BACK_RIGHT =   5;
    uint8_t Cube::BOTTOM_FRONT_LEFT =   6;
    uint8_t Cube::BOTTOM_FRONT_RIGHT =  7;
    uint8_t Cube::LEFT_FACE = 0;
    uint8_t Cube::RIGHT_FACE = 1;
    uint8_t Cube::TOP_FACE = 2;
    uint8_t Cube::BOTTOM_FACE = 3;
    uint8_t Cube::FRONT_FACE = 4;
    uint8_t Cube::BACK_FACE = 5;

    Cube::Cube(){
        _center = glm::vec4(0);
        _dimensions = glm::vec3(1);
        _updateData();
    }

    Cube::Cube(glm::vec4 center, glm::vec3 dimensions): _center(center), _dimensions(dimensions){
        _updateData();
    }

    Cube::Cube(float x, float y, float z, float w){
        _center = glm::vec4(x, y, z, w);
        _dimensions = glm::vec3(1);
        _updateData();
    }

    void Cube::_updateData(){
        _vertices[TOP_BACK_LEFT] = glm::vec4(_center.x - (_dimensions.x / 2.0f), _center.y + (_dimensions.y / 2.0f), _center.z - (_dimensions.z / 2.0f), 1.0f);
        _vertices[TOP_BACK_RIGHT] = glm::vec4(_center.x + (_dimensions.x / 2.0f), _center.y + (_dimensions.y / 2.0f), _center.z - (_dimensions.z / 2.0f), 1.0f);
        _vertices[TOP_FRONT_LEFT] = glm::vec4(_center.x - (_dimensions.x / 2.0f), _center.y + (_dimensions.y / 2.0f), _center.z + (_dimensions.z / 2.0f), 1.0f);
        _vertices[TOP_FRONT_RIGHT] = glm::vec4(_center.x + (_dimensions.x / 2.0f), _center.y + (_dimensions.y / 2.0f), _center.z + (_dimensions.z / 2.0f), 1.0f);

        _vertices[BOTTOM_BACK_LEFT] = glm::vec4(_center.x - (_dimensions.x / 2.0f), _center.y - (_dimensions.y / 2.0f), _center.z - (_dimensions.z / 2.0f), 1.0f);
        _vertices[BOTTOM_BACK_RIGHT] = glm::vec4(_center.x + (_dimensions.x / 2.0f), _center.y - (_dimensions.y / 2.0f), _center.z - (_dimensions.z / 2.0f), 1.0f);
        _vertices[BOTTOM_FRONT_LEFT] = glm::vec4(_center.x - (_dimensions.x / 2.0f), _center.y - (_dimensions.y / 2.0f), _center.z + (_dimensions.z / 2.0f), 1.0f);
        _vertices[BOTTOM_FRONT_RIGHT] = glm::vec4(_center.x + (_dimensions.x / 2.0f), _center.y - (_dimensions.y / 2.0f), _center.z + (_dimensions.z / 2.0f), 1.0f);

        _normals[LEFT_FACE] = glm::vec4(-1, 0, 0, 0);
        _normals[RIGHT_FACE] = glm::vec4(1, 0, 0, 0);
        _normals[TOP_FACE] = glm::vec4(0, 1, 0, 0);
        _normals[BOTTOM_FACE] = glm::vec4(0, -1, 0, 0);
        _normals[FRONT_FACE] = glm::vec4(0, 0, 1, 0);
        _normals[BACK_FACE] = glm::vec4(0, 0, -1, 0);


    }


    float* Cube::getTriangles(){
        float triangles[4*6*6] = {
            //front face
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,
            _vertices[TOP_FRONT_LEFT].x, _vertices[TOP_FRONT_LEFT].y, _vertices[TOP_FRONT_LEFT].z, _vertices[TOP_FRONT_LEFT].w,                 
            _vertices[TOP_FRONT_RIGHT].x, _vertices[TOP_FRONT_RIGHT].y, _vertices[TOP_FRONT_RIGHT].z, _vertices[TOP_FRONT_RIGHT].w,             
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,      
            _vertices[BOTTOM_FRONT_RIGHT].x, _vertices[BOTTOM_FRONT_RIGHT].y, _vertices[BOTTOM_FRONT_RIGHT].z, _vertices[BOTTOM_FRONT_RIGHT].w,                 
            _vertices[TOP_FRONT_RIGHT].x, _vertices[TOP_FRONT_RIGHT].y, _vertices[TOP_FRONT_RIGHT].z, _vertices[TOP_FRONT_RIGHT].w,

            //left face
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,
            _vertices[TOP_FRONT_LEFT].x, _vertices[TOP_FRONT_LEFT].y, _vertices[TOP_FRONT_LEFT].z, _vertices[TOP_FRONT_LEFT].w,                 
            _vertices[TOP_BACK_LEFT].x, _vertices[TOP_BACK_LEFT].y, _vertices[TOP_BACK_LEFT].z, _vertices[TOP_BACK_LEFT].w, 
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,
            _vertices[BOTTOM_BACK_LEFT].x, _vertices[BOTTOM_BACK_LEFT].y, _vertices[BOTTOM_BACK_LEFT].z, _vertices[BOTTOM_BACK_LEFT].w,                 
            _vertices[TOP_BACK_LEFT].x, _vertices[TOP_BACK_LEFT].y, _vertices[TOP_BACK_LEFT].z, _vertices[TOP_BACK_LEFT].w,

            //right face
            _vertices[BOTTOM_FRONT_RIGHT].x, _vertices[BOTTOM_FRONT_RIGHT].y, _vertices[BOTTOM_FRONT_RIGHT].z, _vertices[BOTTOM_FRONT_RIGHT].w,
            _vertices[TOP_FRONT_RIGHT].x, _vertices[TOP_FRONT_RIGHT].y, _vertices[TOP_FRONT_RIGHT].z, _vertices[TOP_FRONT_RIGHT].w,                 
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w, 
            _vertices[BOTTOM_FRONT_RIGHT].x, _vertices[BOTTOM_FRONT_RIGHT].y, _vertices[BOTTOM_FRONT_RIGHT].z, _vertices[BOTTOM_FRONT_RIGHT].w,
            _vertices[BOTTOM_BACK_RIGHT].x, _vertices[BOTTOM_BACK_RIGHT].y, _vertices[BOTTOM_BACK_RIGHT].z, _vertices[BOTTOM_BACK_RIGHT].w,                 
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w,

            //back face
            _vertices[BOTTOM_BACK_LEFT].x, _vertices[BOTTOM_BACK_LEFT].y, _vertices[BOTTOM_BACK_LEFT].z, _vertices[BOTTOM_BACK_LEFT].w,
            _vertices[TOP_BACK_LEFT].x, _vertices[TOP_BACK_LEFT].y, _vertices[TOP_BACK_LEFT].z, _vertices[TOP_BACK_LEFT].w,                 
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w,             
            _vertices[BOTTOM_BACK_LEFT].x, _vertices[BOTTOM_BACK_LEFT].y, _vertices[BOTTOM_BACK_LEFT].z, _vertices[BOTTOM_BACK_LEFT].w,      
            _vertices[BOTTOM_BACK_RIGHT].x, _vertices[BOTTOM_BACK_RIGHT].y, _vertices[BOTTOM_BACK_RIGHT].z, _vertices[BOTTOM_BACK_RIGHT].w,                 
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w,        

            //top face
            _vertices[TOP_FRONT_LEFT].x, _vertices[TOP_FRONT_LEFT].y, _vertices[TOP_FRONT_LEFT].z, _vertices[TOP_FRONT_LEFT].w,
            _vertices[TOP_BACK_LEFT].x, _vertices[TOP_BACK_LEFT].y, _vertices[TOP_BACK_LEFT].z, _vertices[TOP_BACK_LEFT].w,
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w,
            _vertices[TOP_FRONT_LEFT].x, _vertices[TOP_FRONT_LEFT].y, _vertices[TOP_FRONT_LEFT].z, _vertices[TOP_FRONT_LEFT].w,
            _vertices[TOP_FRONT_RIGHT].x, _vertices[TOP_FRONT_RIGHT].y, _vertices[TOP_FRONT_RIGHT].z, _vertices[TOP_FRONT_RIGHT].w,
            _vertices[TOP_BACK_RIGHT].x, _vertices[TOP_BACK_RIGHT].y, _vertices[TOP_BACK_RIGHT].z, _vertices[TOP_BACK_RIGHT].w,

            //bottom face
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,
            _vertices[BOTTOM_BACK_LEFT].x, _vertices[BOTTOM_BACK_LEFT].y, _vertices[BOTTOM_BACK_LEFT].z, _vertices[BOTTOM_BACK_LEFT].w,
            _vertices[BOTTOM_BACK_RIGHT].x, _vertices[BOTTOM_BACK_RIGHT].y, _vertices[BOTTOM_BACK_RIGHT].z, _vertices[BOTTOM_BACK_RIGHT].w,
            _vertices[BOTTOM_FRONT_LEFT].x, _vertices[BOTTOM_FRONT_LEFT].y, _vertices[BOTTOM_FRONT_LEFT].z, _vertices[BOTTOM_FRONT_LEFT].w,
            _vertices[BOTTOM_FRONT_RIGHT].x, _vertices[BOTTOM_FRONT_RIGHT].y, _vertices[BOTTOM_FRONT_RIGHT].z, _vertices[BOTTOM_FRONT_RIGHT].w,
            _vertices[BOTTOM_BACK_RIGHT].x, _vertices[BOTTOM_BACK_RIGHT].y, _vertices[BOTTOM_BACK_RIGHT].z, _vertices[BOTTOM_BACK_RIGHT].w
        };
        return &triangles[0];

    }



}