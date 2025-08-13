#version 410

layout ( location = 0 ) in vec3 pos;
layout ( location = 3 ) in vec2 uv;

uniform float time;
out vec2 fragUV;

void main(){
    gl_Position = vec4(pos, 1.0f);
    fragUV = vec2(uv.x, 1.0f - uv.y) + vec2(0.25f, 0.0f) * time;
}