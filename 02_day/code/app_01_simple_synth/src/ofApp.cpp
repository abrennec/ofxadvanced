#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
    
    setupAudio();
    setupGui();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    waveform.clear();

    // "lastBuffer" is shared between update() and audioOut(), which are called
    // on two different threads. This lock makes sure we don't use lastBuffer
    // from both threads simultaneously (see the corresponding lock in audioOut())
    std::unique_lock<std::mutex> lock_name(audioMutex);
    
    // this loop is building up a polyline representing the audio contained in
    // the left channel of the buffer
    // the x coordinates are evenly spaced on a grid from 0 to the window's width
    // the y coordinates map each audio sample's range (-1 to 1) to the height
    // of the window
    for(size_t i = 0; i < lastBuffer.getNumFrames(); i++) {
        
        float sample = lastBuffer.getSample(i, 0);
        float x = ofMap(i, 0, lastBuffer.getNumFrames(), 0, ofGetWidth());
        float y = ofMap(sample, -1, 1, 0, ofGetHeight());
        waveform.addVertex(x, y);
    }
    
    rms = lastBuffer.getRMSAmplitude();
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofBackground(ofColor::black);
    ofSetColor(ofColor::white);
    
    ofSetLineWidth(1 + (rms * 30.));
    waveform.draw();
    
    // gui stuff
    drawHelpText();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    
    synth.updateSoundBuffer(outBuffer);
    
    // THREAD INFO
    // lock_name is the "var" name of the lock guard, kind of
    // a variable that is being constructed with a mutex (audioMutex),
    // locks the mutex at its construction and unlocks the mutex
    // when it is being destroyed, i.e., at the end of the scope
    std::unique_lock<std::mutex> lock_name(audioMutex);
    lastBuffer = outBuffer;
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    frequencySlider.removeListener(this, &ofApp::updateGui);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '1' && !changeAmp) {
        
        changeAmp = true;
        oscNum = 1;
        
        // TODO: Improve the interaction with mouse move
        // For details see ofApp::mouseMoved
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == '2' && !changeAmp) {
        
        changeAmp = true;
        oscNum = 2;
        
        // TODO: Improve the interaction with mouse move
        // For details see ofApp::mouseMoved
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == '3' && !changeAmp) {
        
        changeAmp = true;
        oscNum = 3;
        
        // TODO: Improve the interaction with mouse move
        // For details see ofApp::mouseMoved
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == 'r') {
        
        // reset freq
        auto freq = synth.getFrequency(true); // get fundamental freq
        updateGui( freq );
    }
    else if (key == 'a') {
        
        float freq = 220 * pow(2,(-5/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 's') {
        
        float freq = 220 * pow(2,(-2/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'd') {
        
        float freq = 220;
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'f') {
        
        float freq = 220 * pow(2,(3/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'g') {
        
        float freq = 220 * pow(2,(5/12.f));
        //ofLogNotice("Freq is : " + ofToString(freq));
        synth.setFrequency(freq);
        updateGui(freq);
    }
    else if (key == 'h') {
        
        float freq = 220 * pow(2,(7/12.0));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'j') {
        
        float freq = 220 * pow(2,(10/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'k') {
        
        float freq = 220 * pow(2,(12/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }
    else if (key == 'l') {
        
        float freq = 220 * pow(2,(15/12.f));
        synth.setFrequency(freq);
        updateGui(freq);
        
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == '1' || key == '2' || key == '3') {
        
        changeAmp = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    if (changeAmp) {
        
        // TODO: Improve the interaction with mouse move
        // To do so, ensure that the amplitude per oscillator
        // only changes when the mouse cursor is inside of the window.
        // Ensure furthermore that whenever the direction changes
        // the amplitude increases or decreases automatically.
        // Check out the following functions to fix this issue:
        // - ofMap
        // - ofNormalize
        int currentMouseDistY = y + ofGetWindowPositionY();
        
        float amp = ofMap(currentMouseDistY, 0, ofGetScreenHeight(), 1.0, 0.0);
        
        synth.setAmplitude(oscNum, amp);
        
//        ofLogNotice("Set Osc No. " + ofToString(oscNum) + " to amp " + ofToString(amp));
//        ofLogNotice("MouseY: " + ofToString(y) + " | WindowPosition " + ofToString(ofGetWindowPositionY()));

    }
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

//--------------------------------------------------------------
void ofApp::drawHelpText() {
 
    // TODO: Correct the help text
    std::string freqString = std::to_string(synth.getFrequency());
    ofDrawBitmapString("Press 'f' and move the mouse in y-direction.", 25, 25);
    ofDrawBitmapString("Press 'r' to reset the frequency.", 25, 40);
    ofDrawBitmapString("Current frequency: " + freqString, 25, 75);
}

//--------------------------------------------------------------
void ofApp::setupAudio() {
    
    // start the sound stream with a sample rate of 44100 Hz, and a buffer
    // size of 512 samples per audioOut() call
    ofSoundStreamSettings settings;
    settings.numOutputChannels = 2;
    settings.sampleRate = 44100;
    settings.bufferSize = 512;
    settings.numBuffers = 4;
    settings.setOutListener(this);
    
    // the following setup function initiates the whole audio connection
    // it invokes the underlying RTAudioSoundStream to
    // - create an RtAudio object
    // - connect the object to the RtAudioCallback function
    // - start the stream and hence have a continious connection to audio in & out
    soundStream.setup(settings); // RtAudioCallback is called by Apple's CoreAudio
    
    synth.setSampleRate(settings.sampleRate);
}

//--------------------------------------------------------------
void ofApp::setupGui() {
    
    // TODO: Update or remove the Gui
    gui.setup();
    gui.setPosition(20, 250);
    gui.add(frequencySlider.setup("fundamental frequency", 172.5, 0.0, 1000.0));
    //gui.add(amplitudeSlider.setup("amplitude ratio", 1.0, 0.0, 1.0));
    
    frequencySlider.addListener(this, &ofApp::updateGui);
}

//--------------------------------------------------------------
void ofApp::updateGui(float& value) {
    
    frequencySlider = value; // not the best design, how to improve?
};
