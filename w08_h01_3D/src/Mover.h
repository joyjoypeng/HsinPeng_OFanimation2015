//
//  Mover.h
//  w08_h01_3D
//
//  Created by Hsin Peng on 4/26/15.
//
//
#pragma once

#include "ofMain.h"

class Mover{
public:
    void setup(float x, float y, float z);
    
    //for forces
    void resetForces();
    void applyForces(ofVec3f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec3f pos, vel, acc;
    ofMaterial material;
    
    float size, alpha;
};

