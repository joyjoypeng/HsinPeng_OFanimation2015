//
//  firework.h
//  w05_h01_firework
//
//  Created by Hsin Peng on 3/10/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class particleSystem{
public:
    
    particleSystem(ofVec2f _pos);
    void update(ofVec2f _force);
    void draw();
    
    //call the particle file
    vector<Particle> particleList;
    ofVec2f pos;
    
};