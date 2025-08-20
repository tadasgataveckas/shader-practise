#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform vec3 translate;
uniform vec3 scale;
out vec2 fragUV;


void main(){
    //im semi i stay automatic, money add then multiply it (MAD operation, multiply then add)
    gl_Position = vec4((pos * scale) + translate, 1.0f); 
    fragUV = vec2(uv.x, 1.0f - uv.y);
}