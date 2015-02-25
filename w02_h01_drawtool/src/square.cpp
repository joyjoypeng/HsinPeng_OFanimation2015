//
//  square.cpp
//  hw_w2a
//
//  Created by Hsin Peng on 2/17/15.
//
//

#include "square.h"


void square::setup(){
    ofSetBackgroundAuto(true);
    pos.set(0,0);
    sqColor.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
}

void square::update(ofVec2f _dest){
    pos = pos* 0.9+ _dest *0.1;
    
}

void square::draw(){
    ofSetColor(sqColor);
    ofRect(pos, ofRandom(20), ofRandom(20));
    //ofCircle(pos,10);
}
