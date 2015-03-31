//
//  cat.h
//  mycat
//
//  Created by Hsin Peng on 3/15/15.
//
//

#pragma once

#include "ofMain.h"


class Cat {
public:
    
    Cat(ofVec2f _pos, ofVec2f _vel);
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void setup();
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float lifespan;
    
    ofImage image;
    
    ofSoundPlayer  meow;

    
};
