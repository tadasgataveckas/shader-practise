#version 410

uniform sampler2D alienImage;
uniform sampler2D backgroundImage;
in vec2 fragUV;
out vec4 outColor;

void main(){
    outColor = texture(alienImage, fragUV);
    if (outColor.a < 1.0f) discard;
}