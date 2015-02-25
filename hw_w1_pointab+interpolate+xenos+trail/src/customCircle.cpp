//
//  customCircle.cpp
//  hw_w1
//
//  Created by Hsin Peng on 2/7/15.
//
//

#include "customCircle.h"

customCircle::customCircle(){
    
}

void customCircle::setup(ofVec2f _initPos, ofVec2f _finalPos){
    initPos= _initPos;
    finalPos= _finalPos;
}
void customCircle::update(float _pct){
    pct = _pct;
    currentPos = initPos *(1-pct)+ finalPos * pct;
}
void customCircle::updateX(float _pct){
    pct = _pct;
    currentPos.x = initPos.x *(1-pct)+ finalPos.x * pct;
}
void customCircle::updateY(float _pct){
    pct = _pct;
    currentPos.y = initPos.y *(1-pct)+ finalPos.y * pct;
}
void customCircle::draw(){
    ofLine(initPos, finalPos);
    ofCircle(currentPos, 20);
    
}



void customCircle::easeIn(float _pct){
    pct = powf(_pct, 2);
    // _pct* _pct
    //pct = powf(_pct, 3) == _pct* _pct* _pct
    
    currentPos = initPos * (1-pct)+ finalPos * pct;
}

void customCircle::easeInCirc(float t, float b, float c, float d){
      return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}

void customCircle::easeOutCirc(float t, float b, float c, float d){
      return c * sqrt(1 - (t=t/d-1)*t) + b;
}

void customCircle::easeInOutCirc(float t, float b, float c, float d){
      if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
      return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
}

void customCircle::setNewPosition(ofVec2f _newPos){
    initPos = currentPos;
    finalPos = _newPos;
}


//xeno
void aroundCircle::setup(){
    pos.set(100,100);
}

void aroundCircle::update(ofVec2f _finalPos){
    //two nummber shoould be plus = 1
    pos = pos*0.99 + _finalPos*0.01;
}

void aroundCircle::draw(){
    ofCircle(pos, 10);
    
}

//xeno1
void aroundCircle1::setup(){
    pos.set(100,100);
}

void aroundCircle1::update(ofVec2f _finalPos){
    //two nummber shoould be plus = 1
    pos = pos*0.6 + _finalPos*0.4;
}

void aroundCircle1::draw(){
    ofCircle(pos, 100);
    
}

//xeno2
void aroundRec::setup(){
    pos.set(100,100);
}

void aroundRec::update(ofVec2f _finalPos){
    //two nummber shoould be plus = 1
    pos = pos*0.98 + _finalPos*0.02;
}

void aroundRec::draw(){
    ofRect(pos, 30, 30);
    
}

//xeno3
void aroundTri::setup(){
    pos.set(100,100);
    pos1.set(0,0);
    pos2.set(100,0);
}

void aroundTri::update(ofVec2f _finalPos){
    //two nummber shoould be plus = 1
    pos = pos*0.96 + _finalPos*0.04;
    //pos1 = pos1*0.94 + _finalPos*0.06;
    //pos2 = pos2*0.94+ _finalPos*0.06;
}

void aroundTri::draw(){
    ofTriangle(pos, pos1, pos2);
    
}
