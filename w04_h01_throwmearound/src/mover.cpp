//
//  mover.cpp
//  w04
//
//  Created by Hsin Peng on 3/3/15.
//
//

#include "mover.h"
void mover::setup(float _pos, float _mass){
    
    //pos.set(x, y);
    mass = _mass;
    
}

void mover::resetForce(){
    //make every frame back to 0
    acc *=0;
}

void mover::applyForce( ofVec2f force){
    
    acc += force / mass;
}

void mover::applyDampingForce(float damping){
    acc -= vel.getNormalized() *damping;
}


void mover::update(){
    
    vel +=acc;
    pos +=vel;
    
    //reach the edge then return to the edge
    if(pos.x <0){
        pos.x = 0;
        vel.x *= -1;
        
    }
    
    if(pos.x >ofGetWidth()){
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if(pos.y <0){
        pos.y = 0;
        vel.y *= -1;
        
    }
    
    if(pos.y >ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
    
}

void mover::draw(){
    
    ofCircle(pos, 10*mass);
    
}