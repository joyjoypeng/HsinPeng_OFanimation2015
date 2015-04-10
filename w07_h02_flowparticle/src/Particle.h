//
//  Particle.h
//  07_flowparticle
//
//  Created by Hsin Peng on 4/7/15.
//
//
#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup(float _offset);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float size, offset;
    
};

