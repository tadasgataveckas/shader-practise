#version 410

layout ( location = 0 ) in vec3 position;
layout ( location = 1 ) in vec4 color;

out vec4 fragColor;


void main(){

    ////for use with screen pixel positions, improved by replacing divisor with current window size.
    //float x = (position.x / 1024.0f) * 2.0 - 1.0;
    //float y = (position.y / 768.0f) * 2.0 - 1.0;
    //gl_Position = vec4(x, y, 0.0f, 1.0f);


    ////for use with normalized screen coordinates
    gl_Position = vec4(position, 1.0);
    fragColor = color;
}