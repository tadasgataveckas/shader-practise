#version 410

uniform sampler2D bgTex;
in vec2 fragUV;
out vec4 outColor;

void main(){
    outColor = texture(bgTex, fragUV);
    if(outColor.a > 0.8) outColor.a = 0.8;
}