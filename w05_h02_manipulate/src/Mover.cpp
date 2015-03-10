//
//  Mover.cpp
//  w05_h02_manipulate
//
//  Created by Hsin Peng on 3/10/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y){
    
    pos.set(x, y);
    
}

void Mover::resetForces(){
    
    acc *= 0;
}

void Mover::applyForces(ofVec2f force){
    acc +=force;
    
}

void Mover::applyDampingForce(float damping){
    
    ofVec2f dampingForce;
    
    // for opposite force
    dampingForce = vel.getNormalized()* damping* -10*size;
    //dampingforce is already negative
    acc += dampingForce;
    
}

void Mover::update(){
    vel += acc;
    pos += vel;
    
    float sinOfTime = sin(ofGetElapsedTimef());
    float cosOfTime = cos(ofGetElapsedTimef());
    //map with the sin looping from -1 to 1
    size = ofMap(sinOfTime, -1, 1, 50, 300);
    alpha = ofMap(sinOfTime, -1, 1, 0, 255);

}

void Mover::draw(){
    //ofCircle(pos, 3);
   
    ofSetColor(151, 242, 207, alpha);
    ofRect(pos, size/15, size/15);
}
