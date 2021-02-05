#version 460

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;



uniform mat4 u_transform;

out vec4 oColor;

void main(){
    gl_Position = u_transform * aPos;
    oColor = aColor;

}