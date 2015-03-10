//
//  Mover.h
//  w05_h02_manipulate
//
//  Created by Hsin Peng on 3/10/15.
//
//

#pragma once

#include "ofMain.h"

class Mover{
public:
    void setup(float x, float y);
    
    //for forces
    void resetForces();
    void applyForces(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float size, alpha, wave;
};
