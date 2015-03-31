//
//  me.h
//  mycat
//
//  Created by Hsin Peng on 3/15/15.
//
//

#pragma once

#include "ofMain.h"

class Me {
public:
    
    void setup();
    void update(float _x, float _y);
    void draw();
    
    ofVec2f pos;
    float rot, size;
    
    ofImage master;

    
};