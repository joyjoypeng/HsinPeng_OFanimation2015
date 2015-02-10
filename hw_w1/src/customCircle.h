//
//  customCircle.h
//  hw_w1
//
//  Created by Hsin Peng on 2/7/15.
//
//

#pragma one
#include "ofMain.h"

class customCircle{
public:
    customCircle();
    void setup(ofVec2f _initPos, ofVec2f _finalPos);
    
    
    void update(float _pct);
    void updateX(float _pct);
    void updateY(float _pct);
    
  
    void easeIn(float _pct);
    
    void easeInCirc(float t,float b,float c,float d);
    void easeOutCirc(float t,float b,float c,float d);
    void easeInOutCirc(float t,float b,float c,float d);
    
    
    void draw();
    void setNewPosition(ofVec2f _newPos);
    
private:
    //float posX, posY;
    
    ofVec2f initPos, finalPos, currentPos;
    
    //percentage
    float pct;
    
};

class aroundCircle{
public:
    void setup();
    void update(ofVec2f _finalPos);
    void draw();
    
    ofVec2f pos, finalPos;
};

class aroundCircle1{
public:
    void setup();
    void update(ofVec2f _finalPos);
    void draw();
    
    ofVec2f pos, finalPos;
};

class aroundRec{
public:
    void setup();
    void update(ofVec2f _finalPos);
    void draw();
    
    ofVec2f pos, finalPos;
};

class aroundTri{
public:
    void setup();
    void update(ofVec2f _finalPos);
    void draw();
    
    ofVec2f pos, finalPos;
    ofVec2f pos1, finalPos1;
    ofVec2f pos2, finalPos2;
};
