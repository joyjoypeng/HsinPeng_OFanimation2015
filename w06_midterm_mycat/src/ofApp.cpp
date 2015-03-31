#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   ofBackground(ofColor_<unsigned char>::skyBlue);
    ofSetFullscreen(true);
    gravity.set(0, 0.2);
    
    
    ofEnableAlphaBlending();
    mult = 0.005;
    z = 0.0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < catList.size(); i++) {
        catList[i].update();
    }
    
    while (catList.size() > 20) {
        catList.erase(catList.begin());
    }
    
    me.update(ofGetMouseX(), ofGetMouseY());
    
    z+= 0.01;
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int x = 0;  x < ofGetWidth()+10; x+= 10) {
        for (int y = 0;  y < ofGetHeight()+50; y+= 10){
            
            square m;
            float noise = ofNoise(x*mult, y*mult, z);
            float w = ofMap(noise, 0, 1, 20, 50);
            float h = ofMap(noise, 0, 1, 40, 70);
            float alpha = ofMap(noise, 0, 1, 0, 255);
            
            if(noise > 0.1) {
                m.drawSquare(x, y, w, h, alpha);
            }
            
            
        }
    }
    
    for (int i = 0; i < catList.size(); i++) {
        catList[i].draw();
        
        //ofSetColor(ofRandom(lifespan),ofRandom(255),ofRandom(255));
        if(i > 0)ofLine(catList[i].pos, catList[i-1].pos);
    }
    
    ofSetColor(255);
    me.draw();

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
   
    ofVec2f vel;
    vel.x = x - ofGetPreviousMouseX();
    vel.y = y - ofGetPreviousMouseY();
    Cat cat(ofVec2f(x, y), vel*0.5);
    catList.push_back(cat);

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
