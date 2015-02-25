//
//  character.h
//  hw_w2c
//
//  Created by Hsin Peng on 2/17/15.
//
//


#pragma once

#include "ofMain.h"

class character{
public:
    
    
    void setup();
    void update();
    void draw(float _x, float _y, float _size );
    
    ofColor myColor;
    ofPoint pos;
    float size;

};

