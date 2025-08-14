 #version 410

 uniform sampler2D turtleTex;

 in vec2 fragUV;
 out vec4 outColor;

 void main(){
    outColor = texture(turtleTex, fragUV);
 }