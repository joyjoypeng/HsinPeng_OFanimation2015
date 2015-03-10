//
//  Particle.cpp
//  w05_h01_firework
//
//  Created by Hsin Peng on 3/10/15.
//
//

#include "Particle.h"

//particle part
Particle::Particle(ofVec2f _pos){
    
    pos.set(_pos);
    vel.x = ofRandom(-5, 5);
    vel.y = ofRandom(10, -5);
    lifespan = 255.0;
    
}

void Particle::resetForces(){
    
    acc *=0;
    
}

void Particle::applyForce(ofVec2f force){
    
    acc += force;
    
}

void Particle::update(){
    
    vel += acc;
    pos += vel;
    
    //don't want lifespan to be 0
    if (lifespan > 0) lifespan -= 3.0;
}

void Particle:: draw(){
    
    
    ofSetColor(ofRandom(150), 0, ofRandom(10));
    ofLine(pos, pos+20);
    
    ofSetColor(0, ofRandom(lifespan), ofRandom(lifespan));
    ofRect(pos, 5, 5);

    
    //ofSetColor(0, ofRandom(lifespan), ofRandom(lifespan));
    //ofRect(pos+80, 10, 10);

    //ofCircle(pos, 5);
    
}