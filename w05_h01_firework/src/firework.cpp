//
//  firework.cpp
//  w05_h01_firework
//
//  Created by Hsin Peng on 3/10/15.
//
//

#include "firework.h"

//class description so don't need void blablabla
particleSystem::particleSystem(ofVec2f _pos){
    
    pos.set(_pos);
    
}

//--------------------------------------------------------------
void particleSystem::update(ofVec2f _force){
    
    for (int i =0; i<10; i++) {
        Particle particle(pos);
        particleList.push_back(particle);
    }
    
    for (int i = 0; i < particleList.size(); i++){
        
        particleList[i].resetForces();
        particleList[i].applyForce(_force);
        particleList[i].update();
    }
    
    //erase the begining particles
    while (particleList.size() > 500){
        
        particleList.erase(particleList.begin());
    }
}

//--------------------------------------------------------------
void particleSystem::draw(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
}
