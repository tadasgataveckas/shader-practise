#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    using namespace glm;
    ofDisableArbTex();
    //gpu creates depth buffer. Without this draw calls need to be ordered.
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    //z coordinate points toward the screen, but normalized (uv)
    //coordinates are being passed, so the z argument is positive
    buildMesh(charMesh, 0.125f,  0.25f, ofVec3f(0.0f, -0.2f, 0.0f));
    buildMesh(backgroundMesh, 1.0f, 1.0f, ofVec3f(0.0f, 0.0f, 0.1f));
    buildMesh(cloudMesh, 0.25f, 0.125f, ofVec3f(0.0f, 0.0f, 0.0f));
    buildMesh(sunMesh, 1.0f, 1.0f, ofVec3f(0.0f, 0.0f, 0.05f));

    alphaTestShader.load("passthrough.vert","alphatest.frag");
    alphaBlendShader.load("passthrough.vert","alphablend.frag");
    spritesheetShader.load("spritesheet.vert","alphatest.frag");
    transformShader.load("transform.vert", "alphablend.frag");

    alienImage.load("alien.png");
    backgroundImage.load("forest.png");
    cloudImage.load("cloudfixed.png");
    sunImage.load("sun.png");
    spritesheetImage.load("walk_sheet.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    if (walkRight)
    {
        float speed = 0.4 * ofGetLastFrameTime();
        charPos += glm::vec3(speed, 0.0f, 0.0f);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    static float frame = 0.0f;
    frame = frame > 10.0f ? 0.0f : frame + 0.1f;
    glm::vec2 spriteSize = glm::vec2(0.28, 0.19);
    glm::vec2 spriteFrame = glm::vec2((int)frame % 3, (int)frame % 3);


    ofDisableBlendMode();
    ofEnableDepthTest();
    alphaTestShader.begin();
    alphaTestShader.setUniformTexture("tex", backgroundImage, 0);
    backgroundMesh.draw();
    alphaTestShader.end();

    spritesheetShader.begin();
    spritesheetShader.setUniform3f("charPos", charPos);
    spritesheetShader.setUniform2f("size", spriteSize);
    spritesheetShader.setUniform2f("offset", spriteFrame);
    spritesheetShader.setUniformTexture("tex", spritesheetImage, 0);
    charMesh.draw();
    spritesheetShader.end();

    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ALPHA);
    ofDisableDepthTest();
    transformShader.begin();
    transformShader.setUniform3f("translate", translation);
    transformShader.setUniform3f("scale", scale);
    transformShader.setUniformTexture("tex", cloudImage, 0);
    cloudMesh.draw();
    transformShader.end();

    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    alphaTestShader.begin();
    alphaBlendShader.setUniformTexture("tex", sunImage, 0);
    sunMesh.draw();
    alphaBlendShader.end();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == OF_KEY_RIGHT ){ walkRight = true;}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if ( key == OF_KEY_RIGHT ){ walkRight = false;}
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


