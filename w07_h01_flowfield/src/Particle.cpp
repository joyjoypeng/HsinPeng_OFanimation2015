//
//  Particle.cpp
//  hw7_flowfield
//
//  Created by Hsin Peng on 4/5/15.
//
//

#include "Particle.h"

void Particle::setup() {
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
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
    pos += vel*-1;
    
}

void Particle::draw() {
    ofCircle(pos, 1);
}
