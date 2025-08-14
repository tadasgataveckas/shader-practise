#version 410

uniform sampler2D turtleTex;
uniform sampler2D checkersTex;

in vec2 fragUV;
out vec4 outColor;

void main(){
    vec4 turtle = texture(turtleTex, fragUV);
    vec4 checkers = texture(checkersTex, fragUV);

    outColor = mix(turtle, checkers, checkers.r);
}