#version 410

uniform sampler2D turtleTex;
uniform float brightness;
uniform vec4 addColor;
in vec2 fragUV;
out vec4 outColor;

void main(){
    vec4 tex = texture(turtleTex, fragUV) * brightness - addColor;
    outColor = tex;
}