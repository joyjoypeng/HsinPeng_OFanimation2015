#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofBackground(0);


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i =1; i < 20; i++) {
        float sinOfTime = sin(ofGetElapsedTimef()*i);
        float x = ofGetWidth()/3 + (sinOfTime *100);
       
        float y = -50+ i*50;
        ofRect(x, y, 20, 40);
    }
    
    for (int i =1; i < 20; i++) {
        float sinOfTime = sin(ofGetElapsedTimef()*i);
        float x = ofGetWidth()/3+150 + (sinOfTime *100);
        
        float y = -50+ i*50;
        ofRect(x, y, 20, 40);
    }
    
    for (int i =1; i < 20; i++) {
        float sinOfTime = sin(ofGetElapsedTimef()*i);
        float x = ofGetWidth()/3+300 + (sinOfTime *100);
        
        float y = -50+ i*50;
        ofRect(x, y, 20, 40);
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

    ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    ofSetBackgroundAuto(true);

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
