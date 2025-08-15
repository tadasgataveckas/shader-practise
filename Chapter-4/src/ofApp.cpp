#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    using namespace glm;
    ofDisableArbTex();
    
    buildMesh(charMesh, 0.125,  0.25, ofVec3f(0.0, 0.15, 0.0));
    //z coordinate points toward the screen, but normalized (uv)
    //coordinates are being passed, so the z argument is positive
    buildMesh(backgroundMesh, 1, 1, ofVec3f(0.0f, 0.0f, 0.1f));
    charShader.load("passthrough.vert","alphatest.frag");
    alienImage.load("alien.png");
    backgroundImage.load("forest.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    charShader.begin();
    charShader.setUniformTexture("alienImage",backgroundImage, 0);
    backgroundMesh.draw();
    charShader.setUniformTexture("alienImage", alienImage, 0);
    charMesh.draw();
    charShader.end();
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

void ofApp::buildMesh(ofMesh &mesh, float w, float h, glm::vec3 pos)
{
        float verts[] = { -w + pos.x, -h + pos.y, pos.z,
                        -w + pos.x, h + pos.y, pos.z,
                        w + pos.x, h + pos.y, pos.z,
                        w + pos.x, -h + pos.y, pos.z };
        float uvs[] = { 0,0, 0,1, 1,1, 1,0};

        for (int i = 0; i < 4; ++i){
            int idx = i * 3;
            int uvIdx = i * 2;
            mesh.addVertex(glm::vec3(verts[idx], verts[idx + 1], verts[idx + 2]));
            mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
        }

        ofIndexType indices[6] = { 0,1,2,2,3,0 };
        mesh.addIndices(indices, 6);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


