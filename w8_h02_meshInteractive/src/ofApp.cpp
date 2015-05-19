#include "ofApp.h"

const int N = 256;
float spectrum[ N ];
float Rad = 500;
float Vel = 0.1;
int bandRad = 2;
int bandVel = 100;
const int n = 30;
float tx[n], ty[n];
ofPoint p[n];
float time0 = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    //Set up sound sample
    sound.loadSound( "Krafty.mp3" );
    sound.setLoop( true );
    sound.play();
    //Set spectrum values to 0
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom(100);
        ty[j] = ofRandom(100);
    }

    icoSphere.setRadius(200);
    origTriangles = icoSphere.getMesh().getUniqueFaces();
    
    ofSetSmoothLighting(true);
    
    extLight.setPointLight();
    extLight.setDiffuseColor(ofFloatColor(0,0,1));
    extLight.setPosition(ofGetWidth()/2, ofGetHeight()/2, 500);
}

//--------------------------------------------------------------
void ofApp::update(){

    //Update sound engine
    ofSoundUpdate();
    //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum( N );
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.8;    //Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.5 );
    time0 = time;
    Rad = ofMap( spectrum[ bandRad ], 1, 3, 100, 150, true );
    Vel = ofMap( spectrum[ bandVel ], 0, 0.1, 0.05, 100 );
    
    
    for (int j=0; j<n; j++) {
        tx[j] += Vel * dt;  //move offset
        ty[j] += Vel * dt;  //move offset
       
        p[j].x = ofSignedNoise( tx[j] ) * Rad;
        p[j].y = ofSignedNoise( ty[j] ) * Rad;
    }
    
    triangles = icoSphere.getMesh().getUniqueFaces();
    
    ofVec3f faceNormal;
    
    //manipulate meshes
    for (int i=0; i< triangles.size(); i++) {
        faceNormal = triangles[i].getFaceNormal();
        
        //facenormal point inside, so -faceNormal let it point outside
        for(int j = 0; j<3; j++){
            triangles[i].setVertex(j, origTriangles[i].getVertex(j)-faceNormal*Vel);
        }
    }
    //delete all the faces, replace new faces
    icoSphere.getMesh().setFromTriangles(triangles);
}

//--------------------------------------------------------------
void ofApp::draw(){

        //Draw cloud
    //Move center of coordinate system to the screen center
    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    ofSetColor(ofColor_<unsigned char>::honeyDew);
    
    for (int i=0; i<n; i++) {
        ofCircle( p[i], 10 );
    }
    ofPopMatrix();
    
    ofEnableDepthTest();
    ofEnableLighting();
    extLight.enable();
    
    cam.begin();
    
    icoSphere.draw();
    cam.end();
    
    ofDisableLighting();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
