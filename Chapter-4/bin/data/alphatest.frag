#version 410

uniform sampler2D charTex;
in vec2 fragUV;
out vec4 outColor;

void main(){
    outColor = texture(charTex, fragUV);
    if (outColor.a < 1.0f) discard;
}