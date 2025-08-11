#include "ofApp.h"
ofMesh triangle;
ofShader shader;
glm::vec4 redColor(1.0f, 0.0f, 0.0f, 1.0f);
glm::vec4 greenColor(0.0f, 1.0f, 0.0f, 1.0f);
glm::vec4 blueColor(0.0f, 0.0f, 1.0f, 1.0f);
glm::vec4 setColor;

//--------------------------------------------------------------
void ofApp::setup(){
    triangle.addVertex(glm::vec3(-1.0f,1.0f,0.0));
    triangle.addVertex(glm::vec3(-1.0f,-1.0f, 0.0));
    triangle.addVertex(glm::vec3(1.0f, -1.0f, 0.0));

//    triangle.addColor(ofFloatColor(1.0f, 0.0f, 0.0f, 1.0f));
//    triangle.addColor(ofFloatColor(0.0f, 1.0f, 0.0f, 1.0f));
//    triangle.addColor(ofFloatColor(0.0f, 0.0f, 1.0f, 1.0f));
    shader.load("first_vertex.vert", "first_fragment.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform4f("fragColor", setColor);
    triangle.draw();
    shader.end();
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // up 111, down 116, left 113, right 114
        glm::vec3 curPos = triangle.getVertex(2);
    switch (key) {
    case OF_KEY_UP:
        triangle.setVertex(2, curPos + glm::vec3(0.0, 0.02f, 0.0));
        setColor = redColor;
        break;
    case OF_KEY_DOWN:
        triangle.setVertex(2, curPos + glm::vec3(0.0, -0.02f, 0.0));
        setColor = blueColor;
        break;
    case OF_KEY_LEFT:
        triangle.setVertex(2, curPos + glm::vec3(-0.02f, 0.0, 0.0));
        setColor = greenColor;
        break;
    case OF_KEY_RIGHT:
        triangle.setVertex(2, curPos + glm::vec3(0.02f, 0.0, 0.0));
        setColor = redColor;
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
