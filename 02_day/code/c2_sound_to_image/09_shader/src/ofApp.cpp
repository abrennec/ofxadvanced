#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    myShader.load("gradient");
    
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

    if (ofGetFrameNum() % 60 == 0){
        myShader.load("gradient");
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofSeedRandom(5);
    myShader.begin();
   
    for (int i = 0; i < 1000; i++){
        myShader.setUniform2f("ptToFadeFrom", ofVec2f(ofGetWidth()/2 + ofRandom(-mouseY,mouseY), ofGetHeight()/2 + ofRandom(-mouseY,mouseY)));
        
        ofDrawLine( ofRandom(0,1000), ofRandom(0,1000), ofRandom(0,1000), ofRandom(0,1000));
    }
    
    myShader.end();
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
