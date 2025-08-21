#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

//declared in common order of operations
uniform vec3 scale;
uniform float rotation;
uniform vec3 translate;

out vec2 fragUV;


void main(){
    vec3 scaled = pos * scale;

    vec3 rotated;
    rotated.x = (cos(rotation)*scaled.x) - (sin(rotation)*scaled.y);
    rotated.y = (cos(rotation)*scaled.y) + (sin(rotation)*scaled.x);
    //(MAD operation, multiply then add) (pos * scale) + translate
    gl_Position = vec4(rotated + translate, 1.0f); 
    fragUV = vec2(uv.x, 1.0f - uv.y);
}