//
//  Arrow.cpp
//  w05_h02_manipulate
//
//  Created by Hsin Peng on 3/10/15.
//
//

#include "Arrow.h"

void Arrow::setup(){
    
    pos.set(0);
    
}

void Arrow::update(float _x, float _y){
    
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

void Arrow::draw(){
    
    float x1 =0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    //for follow the mouse to its position
    ofTranslate(pos);
    // make thing point to each other
    ofRotate(rot);
    ofTriangle(x1, y1, x2, y2, x3, y3);
    
}