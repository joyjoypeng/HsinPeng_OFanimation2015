//
//  Arrow.h
//  w05_h02_manipulate
//
//  Created by Hsin Peng on 3/10/15.
//
//

#pragma once

#include "ofMain.h"

class Arrow{
public:
    
    void setup();
    void update(float _x, float _y);
    void draw();
    
    ofVec2f pos;
    float rot;
    
};
