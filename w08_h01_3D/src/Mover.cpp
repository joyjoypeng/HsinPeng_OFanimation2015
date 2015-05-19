//
//  Mover.cpp
//  w08_h01_3D
//
//  Created by Hsin Peng on 4/26/15.
//
//
#include "Mover.h"

void Mover::setup(float x, float y, float z){
    
    pos.set(x, y, z);
    material.setShininess(120);
    material.setSpecularColor(ofFloatColor(1.f, 1.f, 1.f));
    
    
}
void Mover::resetForces(){
    
    acc *= 0;
}

void Mover::applyForces(ofVec3f force){
    acc +=force;
    
}
void Mover::applyDampingForce(float damping){
    
    ofVec3f dampingForce;
    
    // for opposite force
    dampingForce = vel.getNormalized()* damping* -5*size;
    //dampingforce is already negative
    acc += dampingForce;
    
}

void Mover::update(){
    vel += acc;
    pos += vel;
    
    float sinOfTime = sin(ofGetElapsedTimef());
    float cosOfTime = cos(ofGetElapsedTimef());
    
    size = ofMap(sinOfTime, -1, 1, 50, 200);
    alpha = ofMap(sinOfTime, -1, 1, 20, 255);
    
}


void Mover::draw(){
    
    ofSetColor(151, 242, 207, alpha);
    ofEnableDepthTest();
    
    material.begin();
    ofDrawBox(pos, size/15, size/15, size/15);
    material.end();
}