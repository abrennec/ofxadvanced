#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    grabber.setup(grabWidth, grabHeight);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    grabber.draw(0,0);

    auto stepSize = 10;
    
    for (auto x{0}; x < grabber.getWidth(); x += stepSize) {

        for (auto y{0}; y < grabber.getHeight(); y += stepSize) {

            auto brightness = grabber.getPixels().getColor(x, y).getBrightness();
            auto angle = ofMap(brightness, 0, 255, 0, TWO_PI);
            auto shift_x = x + grabWidth;
            
            
            // TODO: Explain the calculation here
            // Why are cosine and sine operations applied here?
            // What happens if you change the operations?
            // TODO: Add sound
            // How can you connect this with a synth or oscillator?
            
            ofDrawLine(shift_x, y, shift_x + stepSize * cos(angle), y + stepSize * sin(angle));
            //ofDrawCircle(i + 640, j, ofMap(brightness, 0, 255, 4,4.8));
        }
    }
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
