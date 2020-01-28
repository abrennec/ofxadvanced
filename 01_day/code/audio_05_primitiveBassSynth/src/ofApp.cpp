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
    
    // "lastBuffer" is shared between update() and audioOut(), which are called
    // on two different threads. This lock makes sure we don't use lastBuffer
    // from both threads simultaneously (see the corresponding lock in audioOut())
    unique_lock<mutex> lock(audioMutex);

    // this loop is building up a polyline representing the audio contained in
    // the left channel of the buffer
    
    // the x coordinates are evenly spaced on a grid from 0 to the window's width
    // the y coordinates map each audio sample's range (-1 to 1) to the height
    // of the window
    
    waveform.clear();
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
    
    drawHelpText();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    
    synth.fillSoundBuffer(outBuffer);
    
    unique_lock<mutex> lock(audioMutex);
    lastBuffer = outBuffer;
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    frequencySlider.removeListener(this, &ofApp::updateFrequency);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '1' && !changeFreq) {
        
        changeFreq = true;
        oscNum = 1;
        
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == '2' && !changeFreq) {
        
        changeFreq = true;
        oscNum = 2;
        
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == '3' && !changeFreq) {
        
        changeFreq = true;
        oscNum = 3;
        
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == 'r') {
        
        auto freq = synth.getFrequency(true); // get fundamental freq
        updateFrequency( freq );
    }
    
    else if (key == 'a') {
        
        float freq = 220 * pow(2,(-5/12.f));
        updateFrequency(freq);
        
        // play back sine
    }
    else if (key == 's') {
        
        float freq = 220 * pow(2,(-2/12.f));
        updateFrequency(freq);
        
        // play back pulse
    }
    else if (key == 'd') {
        
        float freq = 220;
        updateFrequency(freq);
        
        // play back sine
    }
    else if (key == 'f') {
        
        float freq = 220 * pow(2,(3/12.f));
        updateFrequency(freq);
        
        // play back pulse
    }
    else if (key == 'g') {
        
        float freq = 220 * pow(2,(5/12.f));
//        ofLogNotice("Freq is : " + ofToString(freq));
        updateFrequency(freq);
    }
    else if (key == 'h') {
        
        float freq = 220 * pow(2,(7/12.0));
        updateFrequency(freq);
        
        // play back triangle
    }
    else if (key == 'j') {
        
        float freq = 220 * pow(2,(10/12.f));
        updateFrequency(freq);
        
        // play back pulse
    }
    else if (key == 'k') {
        
        float freq = 220 * pow(2,(12/12.f));
        updateFrequency(freq);
        
        // play back pulse
    }
    else if (key == 'l') {
        
        float freq = 220 * pow(2,(15/12.f));
        updateFrequency(freq);
        
        // play back pulse
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == '1' || key == '2' || key == '3') {
        
        changeFreq = false;
        std::cout << "<<<<<  Freq: " << synth.getFrequency() << std::endl;
        std::cout << "<<<<<  FrameRate: " << ofGetFrameRate() << std::endl;
        std::cout << "<<<<<  FrameNum: " << ofGetFrameNum() << std::endl;
        std::cout << "<<<<<  ElapsedTime: " << ofGetElapsedTimef() << std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    if (changeFreq) {
        
        int currentMouseDistY = y + ofGetWindowPositionY();
        
        float amp = ofMap(currentMouseDistY, 0, ofGetScreenHeight(), 1.0, 0.0);
        
        synth.setAmplitude(oscNum, amp);
        
//        ofLogNotice("Set Osc No. " + ofToString(oscNum) + " to amp " + ofToString(amp));
        ofLogNotice("MouseY: " + ofToString(y) + " | WindowPosition " + ofToString(ofGetWindowPositionY()));
        
        
        
        
        
        // only if we have actually moved the mouse
//        if (currentMouseDistY != initialMouseDistY) {
//            
//            if (currentMouseDistY > initialMouseDistY) synth.increaseFrequency();
//            if (currentMouseDistY < initialMouseDistY) synth.decreaseFrequency();
//            
//            float frequency = ofClamp(synth.getFrequency(), 0.0, 20000.0);
//            updateFrequency(frequency);
//            
//            initialMouseDistY = currentMouseDistY;
//        }
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
    
    gui.setup();
    gui.setPosition(20, 250);
    gui.add(frequencySlider.setup("fundamental frequency", 172.5, 0.0, 1000.0));
    gui.add(amplitudeSlider.setup("amplitude ratio", 1.0, 0.0, 1.0));
    
    frequencySlider.addListener(this, &ofApp::updateFrequency);
}

//--------------------------------------------------------------
void ofApp::updateFrequency(float& value) {
    
    synth.setFrequency(value);
    frequencySlider = value; // not the best design, how to improve?
};
