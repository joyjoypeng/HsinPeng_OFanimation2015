//
//  mover.h
//  w04
//
//  Created by Hsin Peng on 3/3/15.
//
//
#pragma once
#include "ofMain.h"

class mover{
public:
    void setup(float _pos, float _mass);
    void update();
    
    //when u apply other force the previos goes to 0
    void resetForce();
    
    //add force
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void draw();
    
    ofVec2f pos, vel, acc;
    float mass;
    
};
