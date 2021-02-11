#pragma once
#define _EXTENT 0.25f
namespace res{
    struct SceneVerticeTuples{
        float cube_plane_scene[6*4*3*6 + 6 * 12] = {
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
            _EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
            _EXTENT,  _EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
            _EXTENT,  _EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
            -_EXTENT,  _EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 1.0f, 1.0f,     0.0f,  0.0f, -1.0f, 1.0f,   

            -_EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
            _EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
            -_EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   
            -_EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 1.0f, 1.0f,     0.0f,  0.0f,  1.0f, 1.0f,   

            -_EXTENT,  _EXTENT,  _EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
            -_EXTENT,  _EXTENT, -_EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
            -_EXTENT, -_EXTENT,  _EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   
            -_EXTENT,  _EXTENT,  _EXTENT, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,    -1.0f,  0.0f,  0.0f, 1.0f,   

            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
            _EXTENT,  _EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT, -_EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT,  _EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  1.0f, 0.0f, 0.0f, 1.0f,     1.0f,  0.0f,  0.0f, 1.0f,   
        
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT, -_EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
            _EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
            -_EXTENT, -_EXTENT,  _EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   
            -_EXTENT, -_EXTENT, -_EXTENT, 1.0f,  0.0f, 0.0f, 1.0f, 1.0f,     0.0f, -1.0f,  0.0f, 1.0f,   

            -_EXTENT,  _EXTENT, -_EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
            _EXTENT,  _EXTENT, -_EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
            _EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
            -_EXTENT,  _EXTENT,  _EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,   
            -_EXTENT,  _EXTENT, -_EXTENT, 1.0f,  0.0f, 1.0f, 0.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,

            -5000,  -10, -5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,
            5000,  -10, -5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,
            5000,  -10, 5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,

            5000,  -10, 5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,
            5000,  -10, -5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f,
            -5000,  -10, 5000, 1.0f,  1.0f, 1.0f, 1.0f, 1.0f,     0.0f,  1.0f,  0.0f, 1.0f
            };
    };

}