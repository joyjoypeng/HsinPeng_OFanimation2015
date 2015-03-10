#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(ofColor_<unsigned char>::honeyDew);
    
    for (int i = 0; i <500; i++) {
        Mover mover;
        float x = ofRandomWidth();
        float y = ofRandomHeight();
        
        mover.setup(x, y);
        moverList.push_back(mover);
    }


    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myArrow.update(ofGetMouseX(), ofGetMouseY());
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i = 0; i< moverList.size(); i++) {
        ofVec2f diff = mousePos -  moverList[i].pos;
        
        attraction.set(diff.getNormalized() *0.8);
        
        repulsion.set(attraction*-1);
        
        moverList[i].resetForces();
        
        if(diff.length() < 100){
            
            moverList[i].applyForces(repulsion);
            
        }else if(diff.length() < 200){
            
            moverList[i].applyForces(attraction);
        }
        
        moverList[i].applyDampingForce(0.01);
        moverList[i].update();
    }
    
    



}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i< moverList.size(); i++) {
        moverList[i].draw();
    }

    ofSetColor(ofColor_<unsigned char>::salmon);
    myArrow.draw();
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
