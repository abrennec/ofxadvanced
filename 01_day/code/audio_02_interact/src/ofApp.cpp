#include "ofApp.h"

//--------------------------------------------------------------
ofApp::ofApp()
: frequency{172.5f}, changeFreq{false}
{
    
}



//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
    
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
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &outBuffer) {
    
    // base frequency of the lowest sine wave in cycles per second (hertz)
    //float frequency = 172.5;
    
    // mapping frequencies from Hz into full oscillations of sin() (two pi)
    float wavePhaseStep = (frequency / outBuffer.getSampleRate()) * TWO_PI;
    float pulsePhaseStep = (0.5 / outBuffer.getSampleRate()) * TWO_PI;
    
    // this loop builds a buffer of audio containing sine waves at different
    // frequencies, and pulses the volume of each sine wave individually. In
    // other words, oscillators and LFOs (frequency < 20hz).
    
    for(size_t i = 0; i < outBuffer.getNumFrames(); i++) {
        
        // build up a chord out of sine waves at 3 different frequencies
        float sampleLow = sin(wavePhase);
        float sampleMid = 0. * sin(wavePhase * 3.2);
        float sampleHi = 0.5 * sin(wavePhase * 0.8);
        float sampleMidHigh = 0. * sin(wavePhase * 4);
        
        // pulse each sample's volume
        sampleLow *= sin(pulsePhase * 0.98);
        //sampleMid *= sin(pulsePhase * 1.04);
        //sampleHi *= sin(pulsePhase * 1.09);
        
        //float fullSample = (sampleLow + sampleMid + sampleHi);
        float fullSample = (sampleLow + sampleMid + sampleHi + sampleMidHigh);
        
        // reduce the full sample's volume so it doesn't exceed 1
        fullSample *= 0.3;
        
        fullSample = ofClamp(fullSample, -.9f, .9f);
        
        fullSample *= sin(pulsePhase * 3.98);
        
        
        // write the computed sample to the left and right channels
        outBuffer.getSample(i, 0) = fullSample;
        outBuffer.getSample(i, 1) = fullSample;
        
        // get the two phase variables ready for the next sample
        wavePhase += wavePhaseStep;
        pulsePhase += pulsePhaseStep;
    }
    
    unique_lock<mutex> lock(audioMutex);
    lastBuffer = outBuffer;
}

//--------------------------------------------------------------
void ofApp::exit() {
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'f' && !changeFreq) {
        
        changeFreq = true;
        initialMouseDistY = ofGetMouseY() - ofGetWindowPositionY();
    }
    else if (key == 'r') {
        
        frequency = 172.5;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 'f') {
        
        changeFreq = false;
        std::cout << "<<<<<  Freq: " << frequency << std::endl;
        std::cout << "<<<<<  FrameRate: " << ofGetFrameRate() << std::endl;
        std::cout << "<<<<<  FrameNum: " << ofGetFrameNum() << std::endl;
        std::cout << "<<<<<  ElapsedTime: " << ofGetElapsedTimef() << std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    if (changeFreq) {
        
        int currentMouseDistY = y - ofGetWindowPositionY();
        
        // only if we have actually moved the mouse
        if (currentMouseDistY != initialMouseDistY) {
            
            if (currentMouseDistY > initialMouseDistY) frequency += 10;
            if (currentMouseDistY < initialMouseDistY) frequency -= 10;
            
            frequency = ofClamp(frequency, 0, 20000);
            
            initialMouseDistY = currentMouseDistY;
        }
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
 
    std::string freqString = std::to_string(frequency);
    ofDrawBitmapString("Press 'f' and move the mouse in y-direction.", 25, 25);
    ofDrawBitmapString("Press 'r' to reset the frequency.", 25, 40);
    ofDrawBitmapString("Current frequency: " + freqString, 25, 75);
}
