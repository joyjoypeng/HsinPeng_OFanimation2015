#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   // ofBackground(ofColor_<unsigned char>::honeyDew);
    ofBackground(ofColor_<unsigned char>::darkSlateBlue);
    
    //make smooth circle
    ofSetCircleResolution(100);
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    //male it keep looping, never stop
    float sinOfTime = sin(ofGetElapsedTimef());
    float cosOfTime = cos(ofGetElapsedTimef());
    //map with the sin looping from -1 to 1
    size = ofMap(sinOfTime, -1, 1, 50, 300);
    alpha = ofMap(sinOfTime, -1, 1, 0, 255);
    wave = ofMap(cosOfTime, -1, 1, 0, 200);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(151, 242, 207);
    ofSetCircleResolution(7);
    ofEllipse(ofGetWidth()/2, ofGetHeight()/2+10, 300, 400);
    ofEllipse(ofGetWidth()/2+270, ofGetHeight()/2+280, 600, 500);
    
    ofSetLineWidth(5);
    ofSetColor(151, 242, 207);
    ofLine(ofGetWidth()/2-130, ofGetHeight()/2+98, size/5, size);
    ofLine(ofGetWidth()/2-130, ofGetHeight()/2, size/5, size);
    ofLine(ofGetWidth()/2-130, ofGetHeight()/2-75, size/5, size);
    
    ofSetColor(247,196, 232);
    ofTriangle(ofGetWidth()/2+270, ofGetHeight()/2+250, ofGetWidth()/2+200, ofGetHeight()/2+300, ofGetWidth()/2+340, ofGetHeight()/2+350);
    //ofTriangle(ofGetWidth()/2+270, ofGetHeight()/2+250, wave);
    
    ofSetLineWidth(0);
    ofSetColor(ofRandom(255),ofRandom(0),ofRandom(0), alpha);
    
    float x1 = 0;
    float y1 = 30;
    
    float x2 = -15;
    float y2 = 20;
    
    float x3 = -27;
    float y3 = 35;
    
    float x4 = 0;
    float y4 = 65;
    
    float x5 = 27;
    float y5 = 35;
    
    float x6 = 15;
    float y6 = 20;
    
    ofBeginShape();{
        
        ofVertex(ofGetWidth()/2+x1, ofGetHeight()/2+y1 , size);
        ofVertex(ofGetWidth()/2+x2, ofGetHeight()/2+y2 , size);
        ofVertex(ofGetWidth()/2+x3, ofGetHeight()/2+y3 , size);
        ofVertex(ofGetWidth()/2+x4, ofGetHeight()/2+y4 , size);
        ofVertex(ofGetWidth()/2+x5, ofGetHeight()/2+y5 , size);
        ofVertex(ofGetWidth()/2+x6, ofGetHeight()/2+y6 , size);
    }
    ofEndShape(true);
    
    
    
    
    
    
    //myheart.draw(ofGetWindowSize()/2, size);
    //myheart.draw(ofGetWidth(),ofGetHeight());
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
