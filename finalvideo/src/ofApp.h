#pragma once

#include "ofMain.h"


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
		
    ofEasyCam cam;
    ofVideoPlayer video, video1; //Prerecorded video
    
    ofFbo fbo;
    ofMesh mesh;
    ofImage image;
    ofPixels fboPixels;
    

    float tiltCurrent = 0;
    float tiltTarget = 0;
    float turnCurrent = 1;
    float turnTarget = 1;

    
private:
    
    int videoWidth = 1920;
    int videoHeight = 1080;
    int W =384; //Grid size
    int H =216;
    int meshSize = 5;
};
