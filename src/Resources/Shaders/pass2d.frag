#version 460
in vec4 oColor;

out vec4 FragColor;
void main(){

    FragColor = vec4(oColor.r, 1, 1, 1);

}