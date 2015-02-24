//
//  follow.h
//  hw_w3b_atan
//
//  Created by Hsin Peng on 2/23/15.
//
//


#pragma once

#include "ofMain.h"

class follow{
public:
    
    void setup();
    void update(float _x, float _y);
    void draw();
    
    ofVec2f pos;
    float rot;
    
};
