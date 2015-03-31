//
//  back.cpp
//  mycat
//
//  Created by Hsin Peng on 3/15/15.
//
//

#include "back.h"


void square::drawSquare(float _x, float _y, float _w, float _h, float _alpha) {
    
    float x = _x- _w/2;
    float y = _y- _h;
    
    ofSetColor(ofColor_<unsigned char>::honeyDew, _alpha);
    //ofRect(x, y, 10, 10);
    ofCircle(x, y, 20);
    
  
    
}