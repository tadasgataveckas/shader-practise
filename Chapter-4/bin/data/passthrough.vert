#version 410

layout ( location = 0 ) in vec3 pos;
layout ( location = 3 ) in vec2 uv;

out vec2 fragUV;

void main(){
    vec3 scale = vec3(0.3f, 0.4f, 1.0f);
    gl_Position = vec4(pos, 1.0f);
    fragUV = vec2(uv.x, 1.0f - uv.y);
}