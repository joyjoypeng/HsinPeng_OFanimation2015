//
//  Particle.cpp
//  07_flowparticle
//
//  Created by Hsin Peng on 4/7/15.
//
//

#include "Particle.h"

void Particle::setup(float _offset) {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    offset= _offset;
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    float sineOfTime = sin(ofGetElapsedTimef()+offset);
    size = ofMap(sineOfTime, -1, 1, 0, 15);
    

    
}

void Particle::draw() {
    ofRect(pos, 8*0.1*size, 8*0.1*size);
    ofCircle(pos, 3*0.1*size);
    ofCircle(pos.x+8*0.1*size, pos.y, 3*0.1*size);
}
