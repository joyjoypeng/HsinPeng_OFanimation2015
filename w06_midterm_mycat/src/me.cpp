//
//  me.cpp
//  mycat
//
//  Created by Hsin Peng on 3/15/15.
//
//

#include "me.h"


void Me::setup(){
    
    pos.set(0);
    
}

void Me::update(float _x, float _y){
    
    ofVec2f newPos;
    newPos.set(_x, _y);
    //position
    pos = pos *0.8 + newPos *0.2;

    
    //make the tri point follow mouse
    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot/50);
    
    float sinOfTime = sin(ofGetElapsedTimef());
    size = ofMap(sinOfTime, -1, 1, 1.2, 2);
    
    master.update();
}

void Me::draw(){

    
    ofTranslate(pos/10);
    ofRotate(rot);
    master.loadImage("me.png");
    master.draw(pos, 60*size, 100*size);
    
}