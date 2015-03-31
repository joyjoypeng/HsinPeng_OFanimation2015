//
//  cat.cpp
//  mycat
//
//  Created by Hsin Peng on 3/15/15.
//
//

#include "cat.h"


Cat::Cat(ofVec2f _pos, ofVec2f _vel) {
    vel = _vel;
    pos = _pos;
    lifespan = 300;
    image.loadImage("cat.png");
    //image.setAnchorPercent(0.5, 0.5);
    
    meow.loadSound("meow.mp3");
    meow.setMultiPlay(true);
    meow.setLoop(false);
}

void Cat::resetForces() {
    acc *= 0;
}

void Cat::applyForce(ofVec2f force) {
    acc += force;
}

void Cat::update() {
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) lifespan -= 1.0;
    

    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
        meow.setPan(-1.0);
        meow.play();
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
        meow.setPan(1.0);
        meow.play();
        
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
        
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
        
    }

    
    
    image.update();
}

void Cat::draw() {
    ofSetColor(ofRandom(lifespan*5),ofRandom(lifespan*5),ofRandom(lifespan*5));
    image.draw(pos,50,50);
    
}