#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    yOffset = 1000.0;
    
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float noiseX = ofNoise(ofGetElapsedTimef());
    float noiseY = ofNoise(ofGetElapsedTimef()+yOffset);
    float noiseZ = ofNoise(ofGetElapsedTimef()+(yOffset+200));
    
    
    pos.x = ofMap(noiseX, 0, 1, 0, ofGetWidth());
    pos.y = ofMap(noiseY, 0, 1, 0, ofGetHeight());
    pos.z = ofMap(noiseZ, 0, 1, 0, 500);


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofLine(pos.x, pos.y, pos.z, ofGetWidth()/2, ofGetHeight()/10, pos.z+50);

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
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
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
