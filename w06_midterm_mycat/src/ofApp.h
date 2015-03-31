#pragma once

#include "ofMain.h"
#include "cat.h"
#include "me.h"
#include "back.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    vector<Cat> catList;
    ofVec2f gravity;
    
    Me me;
    
    float mult;
    float z;
		
};
