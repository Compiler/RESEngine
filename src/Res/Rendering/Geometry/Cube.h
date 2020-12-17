#pragma once
#include <Res/res.h.>
#include <glm/glm.hpp>
namespace res{

    class Cube{

        private:
            glm::vec4 _center;
            glm::vec3 _dimensions;
            glm::vec4 _vertices[8];
            glm::vec4 _normals[6];
            void _updateData();


        public:
            //indices for _vertices
            static uint8_t TOP_BACK_LEFT, TOP_BACK_RIGHT, TOP_FRONT_LEFT, TOP_FRONT_RIGHT, BOTTOM_BACK_LEFT, BOTTOM_BACK_RIGHT, BOTTOM_FRONT_LEFT, BOTTOM_FRONT_RIGHT;
            static uint8_t LEFT_FACE, RIGHT_FACE, TOP_FACE, BOTTOM_FACE, FRONT_FACE, BACK_FACE;

            explicit Cube();
            explicit Cube(glm::vec4 center, glm::vec3 dimensions);
            explicit Cube(float x, float y, float z, float w = 1.0f);

            //return the 6 normals
            glm::vec4* getNormals(){return _normals;}
            //return the 8 vertices
            glm::vec4* getVertices(){return _vertices;}


            float* getTriangles();

            


    };

}