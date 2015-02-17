//
//  character.cpp
//  hw_w2c
//
//  Created by Hsin Peng on 2/17/15.
//
//

#include "character.h"

void character::setup(){
    
    
}

void character::update(){
    
    
}

void character::draw(float _x, float _y, float _size){
    
    pos.x = _x;
    pos.y = _y;
    size = _size;
   
    //myColor = (ofRandom(255), ofRandom(255), ofRandom(255));
    //ofSetColor(myColor);
    ofRect(pos.x, pos.y, 20, 20);
    ofRect(pos.x+20, pos.y+10, 10, 70);
}
