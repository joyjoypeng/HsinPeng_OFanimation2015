//
//  square.h
//  hw_w2a
//
//  Created by Hsin Peng on 2/17/15.
//
//

#pragma once

#include "ofMain.h"

class square{
public:
    
    void setup();
    void update(ofVec2f _dest);
    void draw();
    
    ofVec2f pos;
    
    //set color
    ofColor sqColor;
    
};