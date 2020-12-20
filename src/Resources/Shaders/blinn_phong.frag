#version 460
in vec4 oColor;
in vec4 oNormal;
in vec3 oFragPos;

out vec4 FragColor;
void main(){

    vec3 lightColor = vec3(1);
    vec3 lightPos = vec3(0, 2, 0);
     // ambient
    float ambientStrength = 0.25;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 norm = normalize(oNormal.xyz);
    vec3 lightDir = normalize(lightPos - oFragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
            
    vec3 result = (ambient + diffuse) * oColor.xyz;
    FragColor = vec4(result, 1.0);

}