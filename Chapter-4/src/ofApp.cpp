#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    using namespace glm;
    ofDisableArbTex();
    //gpu creates depth buffer. Without this draw calls need to be ordered.
    ofEnableDepthTest();
    
    ofEnableAlphaBlending();
    
    buildMesh(charMesh, 0.125f,  0.25f, ofVec3f(0.0f, -0.2f, 0.0f));
    //z coordinate points toward the screen, but normalized (uv)
    //coordinates are being passed, so the z argument is positive
    buildMesh(backgroundMesh, 1.0f, 1.0f, ofVec3f(0.0f, 0.0f, 0.1f));
    buildMesh(cloudMesh, 0.25f, 0.125f, ofVec3f(-0.55f, 0.0f, 0.0f));
    buildMesh(sunMesh, 1.0f, 1.0f, ofVec3f(0.0f, 0.0f, 0.05f));
    charShader.load("passthrough.vert","alphatest.frag");
    bgShader.load("passthrough.vert","alphablend.frag");
    spritesheetShader.load("spritesheet.vert","alphatest.frag");
    alienImage.load("alien.png");
    backgroundImage.load("forest.png");
    cloudImage.load("cloudfixed.png");
    sunImage.load("sun.png");
    spritesheetImage.load("walk_sheet.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    static float frame = 0.0f;
    frame = (frame > 10) ? 0.0 : frame += 0.1;
    glm::vec2 spriteSize = glm::vec2(0.28, 0.19);
    glm::vec2 spriteFrame = glm::vec2((int)frame % 3, (int)frame % 3);

    ofDisableBlendMode();
    ofEnableDepthTest();
    charShader.begin();
    charShader.setUniformTexture("charTex", backgroundImage, 0);
    backgroundMesh.draw();
    charShader.end();
    spritesheetShader.begin();
    spritesheetShader.setUniform2f("size", spriteSize);
    spritesheetShader.setUniform2f("offset", spriteFrame);
    spritesheetShader.setUniformTexture("charTex", spritesheetImage, 0);
    charMesh.draw();
    spritesheetShader.end();

    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
    ofDisableDepthTest();
    bgShader.begin();
    bgShader.setUniformTexture("bgTex", cloudImage, 0);
    cloudMesh.draw();

    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    bgShader.setUniformTexture("bgTex", sunImage, 0);
    sunMesh.draw();
    bgShader.end();
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


