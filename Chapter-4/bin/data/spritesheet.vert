#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

uniform vec2 size;
uniform vec2 offset;
uniform vec3 charPos;

out vec2 fragUV;

void main(){
    gl_Position = vec4(pos + charPos, 1.0f);
    fragUV = vec2(uv.x, 1.0f - uv.y) * size + (offset*size);
}