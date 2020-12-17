#version 460

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec4 aNormal;



uniform mat4 u_transform;

out vec4 oColor;
out vec4 oNormal;
out vec3 oFragPos;

void main(){
    gl_Position = u_transform * aPos;
    oFragPos = (u_transform * aPos).xyz;
    oColor = aColor;
    oNormal = aNormal;

}