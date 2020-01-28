#include "ofApp.h"

/**********  WARNING  *********************** 
To avoid the hazard of damaging your ears, 
do not listen the project's output sound with headphones.
This project uses low-level audio output, so due 
possible errors in software it can suddenly 
generate clicks and very loud sounds.
********************************************/


//--------------------------------------------------------------
void ofApp::setup() {
    
	//Set arrays sizes and fill these with zeros
	arr.resize( grabW, 0.0 ); 
	buffer.resize( N, 0.0 );  

	//Start camera
	grabber.initGrabber( grabW, grabH );
    
    // start the sound stream with a sample rate of 44100 Hz, and a buffer
    // size of 512 samples per audioOut() call
    ofSoundStreamSettings settings;
    settings.numOutputChannels = 2;
    settings.sampleRate = sampleRate;
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
void ofApp::update() {
    
	grabber.update();			//Update camera

	if ( grabber.isFrameNew() ) {	//Check for new frame

		//Get pixels of the camera image
		ofPixels &pixels = grabber.getPixels();
        
        //Check image size
        if ( pixels.getWidth() != grabW || pixels.getHeight() != grabH ) {
            return;
        }

		//Read pixels brightness from the central line of the image
		for (int x=0; x<grabW; x++) {
            
			//Get the pixel brightness
			float v = pixels.getColor( x, Y0 ).getLightness();
			//v lies in [0,255], convert it to [-1,1]
			arr.at(x) = ofMap( v, 0, 255, -1, 1, true );
		}

        //Stretch arr to buffer (having size N), using linear interpolation
        for (int i=0; i<N; i++) {
            
            float pos = float(i) * grabW / N;   //Get float position in range [0, grabW]
            int pos0 = int( pos );              //Get left index
            int pos1 = min( pos0 + 1, N-1 );    //Getright index
            //Interpolate
            buffer.at(i) = ofMap( pos, pos0, pos1, arr.at(pos0), arr.at(pos1) );
        }

		//Shift the buffer values to have a mean value
		//equal to zero
		//Compute a mean value of buffer
		float mean = 0;

		for (int i=0; i<N; i++) {
            
			mean += buffer.at(i);
		}

		mean /= N;
		//Shift the buffer by mean value
		for (int i=0; i<N; i++) {
            
			buffer.at(i) -= mean;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
	ofBackground( 255, 255, 255 );	//Set the background color
    
	//Draw a camera frame
	ofSetColor( 255, 255, 255 );
	grabber.draw( 0, 0 );
    
	//Draw the scan line area
	ofNoFill();
	ofSetColor( 255, 255, 0 );
	ofDrawRectangle( 0, Y0 - 1, N, 3 );

	//Draw the current buffer as a graph
	ofSetColor( 255, 0, 0 );
	ofFill();
	ofDrawRectangle( 0, 0, grabW, 100 );
	ofSetColor( 0 );
    
	for (int x=0; x<grabW; x++) {
        
        int i = float(x) * N / grabW;   //Find position in buffer
		ofDrawLine( x, 50, x, 50 - buffer.at(i) * 50 );
	}
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& outBuffer)
{
	for (int i=0; i < outBuffer.getNumFrames(); i++) {
        
        outBuffer.getSample(i, 0) = buffer.at( playPos ) * volume;;
        outBuffer.getSample(i, 1) = buffer.at( playPos ) * volume;;
        
		//Shift to the next audio sample
		playPos++;		
		//When the end of buffer is reached, playPos sets to 0
		//So we hear looped sound
		playPos %= N;	
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
