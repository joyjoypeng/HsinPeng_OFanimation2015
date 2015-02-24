//
//  follow.cpp
//  hw_w3b_atan
//
//  Created by Hsin Peng on 2/23/15.
//
//

#include "follow.h"


void follow::setup(){
    
    pos.set(0);
    
}

void follow::update(float _x, float _y){
    
    ofVec2f newPos;
    newPos.set(_x, _y);
    //position
    pos = pos *0.97 + newPos *0.03;
    
    //make the tri point follow mouse
    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
}

void follow::draw(){
    
    float x1 =0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    float x4= -17;
    float y4= -18;
    
    float x5= -13;
    float y5= 128;
    
    //for follow the mouse to its position
    ofTranslate(pos);
    // make thing point to each other
    ofRotate(rot);
    ofTriangle(x1, y1, x2, y2, x3, y3);
    ofSetCircleResolution(100);
    ofCircle(x1-15, y3, 20);
    ofRect(x4, y4, 4, 150);
    
    ofBeginShape();{
        
        ofVertex(x5, y5);
        ofVertex(x5-50, y5-10);
        ofVertex(x5-150, y5+70);
        ofVertex(x5, y5+50);
    }
    ofEndShape(true);
    
}