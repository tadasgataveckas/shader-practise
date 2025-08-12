#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    quad.addVertex(glm::vec3(-1.0f, -1.0f, 0.0f));
    quad.addVertex(glm::vec3(-1.0f, 1.0f, 0.0f));
    quad.addVertex(glm::vec3(1.0f, 1.0f, 0.0f));
    quad.addVertex(glm::vec3(1.0f, -1.0f, 0.0f));
 
    quad.addTexCoord(glm::vec2(0, 0));
    quad.addTexCoord(glm::vec2(0, 1));
    quad.addTexCoord(glm::vec2(1, 1));
    quad.addTexCoord(glm::vec2(1, 0));

    ofIndexType indices[6] = { 0,1,2,2,3,0 };
    quad.addIndices(indices,6);

    shader.load("uv_passthrough.vert", "uv_vis.frag");

    ofDisableArbTex();
    img.load("turtle.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniformTexture("turtleTex", img, 0);
    quad.draw();
    shader.end();
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
