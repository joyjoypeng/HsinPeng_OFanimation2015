#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i = 0; i<10; i++){
        square xeno;
        xeno.setup();
        xenoList.push_back(xeno);
    }
    
    ofSetBackgroundAuto(false);
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos;
    mousePos.x= ofGetMouseX();
    mousePos.y= ofGetMouseY();
    
    xenoList[0].update(mousePos);
    
    //make it follow each one
    for(int i = 1; i< xenoList.size(); i++){
        //flollow the previous one
        xenoList[i].update(xenoList[i-1].pos);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i= 0; i< xenoList.size(); i++) {
        xenoList[i].draw();
    }


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

    ofBackground(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
