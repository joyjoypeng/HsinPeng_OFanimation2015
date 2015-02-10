#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(0);
    pct = 0.0;

    totalIter = 100;
    currentIter = 0;
    
    //start position and final position
    CircleOne.setup(ofVec2f(0, 500), ofVec2f(800, 500));
    CircleTwo.setup(ofVec2f(0, 500), ofVec2f(800, 500));
    
    myCircle.setup();
    myCircle1.setup();
    myRec.setup();
    myTri.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(pct <0.9){
        pct +=0.01;
    }
    
    pct +=0.001;
    
    if(currentIter < totalIter){
        currentIter ++;
    }
    
    //CircleOne.update(CircleOne.easeInOutCirc(currentIter, 0.0, 1.0, totalIter));
    
    CircleOne.easeIn(pct);
    CircleTwo.easeIn(pct);
    
    myCircle.update(ofVec2f(ofVec2f(ofGetMouseX(), ofGetMouseY())));
    myCircle1.update(ofVec2f(ofVec2f(ofGetMouseX(), ofGetMouseY())));
    myRec.update(ofVec2f(ofVec2f(ofGetMouseX(), ofGetMouseY())));
    myTri.update(ofVec2f(ofVec2f(ofGetMouseX(), ofGetMouseY())));
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    CircleOne.draw();
    CircleTwo.draw();
    
    myCircle.draw();
    myCircle1.draw();
    myRec.draw();
    myTri.draw();
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
   ofSetColor(ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255)));
   //ofSetBackgroundAuto(false);
   ofBackground(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    //ofRotate(ofRandom(0, 360));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    CircleOne.setNewPosition(ofVec2f (x, y));
    CircleTwo.setNewPosition(ofVec2f(y, x));
    
    pct = 0.0;
    currentIter = 0.0;
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
