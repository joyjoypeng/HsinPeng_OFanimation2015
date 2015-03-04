#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor_<unsigned char>::cadetBlue);
    ofSetCircleResolution(100);

    // set x y to the middle
    pos.set(ofGetWindowSize()/2);
    
    acc.set(0.1, 0.1);
    
    gravity.set(0, 0.5);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    pos += vel;

    
    if(pos.x >ofGetWidth()  || pos.x <0){
        vel.x *= -1;
        
    }
    if (pos.y > ofGetHeight() ||  pos.y<0) {
        vel.y *= -1;
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(ofColor_<unsigned char>::pink);
    ofCircle(pos, 50);
  //  Mover(pos, 50);
    
    
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

    vel  += -2*acc;
    //newpos.x = 10*(finalPos.x - initPos.x);
    //newpos.y = 10*(finalPos.y - initPos.y);
    
    //ofCircle(newpos, 100);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
