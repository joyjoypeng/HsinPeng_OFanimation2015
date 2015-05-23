#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    video.loadMovie( "Mhtn_1.mov" );
    video.play();
    
    video1.loadMovie( "Space.mp4" );
    video1.play();

    
    //setup fbo
    fbo.allocate(videoWidth, videoHeight);
    // clear fbo
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    //Set up vertices
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            mesh.addVertex(ofPoint((x - W/2) * meshSize, (y - H/2) * meshSize, 0 ));
            mesh.addTexCoord(ofPoint(x * (videoWidth / W), y * (videoHeight / H)));
            mesh.addColor(ofColor(255, 255, 255));
        }
    }
    
    //Set up triangles' indices
    for (int y=0; y<H-1; y++) {
        for (int x=0; x<W-1; x++) {
            int i1 = x + W * y;
            int i2 = x+1 + W * y;
            int i3 = x + W * (y+1);
            int i4 = x+1 + W * (y+1);
            mesh.addTriangle( i1, i2, i3 );
            mesh.addTriangle( i2, i4, i3 );
        }
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update video
    video.update();
    video1.update();
    
    if (video.isFrameNew()) {
        
        fbo.begin();
        
        int alpha = 10;
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        
        video.draw(0, 0, 1920 ,1080);
        ofDisableAlphaBlending();
        fbo.end();
    }
    
    if (video1.isFrameNew()) {
        
        fbo.begin();
        
        int alpha = 10;
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255, alpha);
        
        video1.draw(0, -400, 1920 ,3240);
        ofDisableAlphaBlending();
        fbo.end();
    }

    
    fbo.readToPixels(fboPixels);
    image.setFromPixels(fboPixels);
    
    //Change vertices
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            
            //Vertex index
            int i = x + W * y;
            ofPoint p = mesh.getVertex( i );
            
            float scaleX = videoWidth / W;
            float scaleY = videoHeight / H;
            
            // get brightness
            int index = ((x * scaleX) + videoWidth * (y * scaleY)) * 4;
            int brightness = fboPixels[index] / 4;
            
            //Change z-coordinate of vertex
            p.z = brightness*5;
            mesh.setVertex( i, p );
            
            //Change color of vertex
            mesh.setColor(i , ofColor(255, 255, 255));
        }
    }

   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    ofSetHexColor(0xffffff);
    
    ofSetColor(ofRandom(90, 100), ofRandom(80, 100));
    fbo.draw(0, 0, 1980, 1080);
    /*for (int j = 0; j<ofGetWidth(); j+= 198) {
        for (int q = 0; q<ofGetHeight(); q += 108) {
        ofSetColor(ofRandom(100), ofRandom(80, 100));
        fbo.draw(j, q, 198, 108);
        }
    }*/
    

    ofPushMatrix();
    ofTranslate( ofGetWidth()/2, ofGetHeight()/2, -1000);

    cam.begin();
    
    
    ofScale (1,-1,1);
    image.bind();
    mesh.draw();
    image.unbind();
    // mesh.drawWireframe();
     cam.end();
    
    ofPopMatrix(); //Restore the coordinate system

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
