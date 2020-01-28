#pragma once

#include "ofMain.h"

/*
Example transcodes central horizontal of the image grabbed by webcamera to sound. 

It's the example 04-ImageToSound from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 6 - Working with Sounds

**********  WARNING  *********************** 
To avoid the hazard of damaging your ears, 
do not listen the project's output sound with headphones.
This project uses low-level audio output, so due 
possible errors in software it can suddenly 
generate clicks and very loud sounds.
********************************************
*/


class ofApp : public ofBaseApp {
    
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	//Function for generating audio
	void audioOut( ofSoundBuffer& outBuffer );

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
    
    ofSoundStream soundStream;    //Object for sound output setup

    ofVideoGrabber grabber; //Video grabber
    
    
    //Constants
    const int grabW{1024};                 //Width of the camera frame
    const int grabH{768};                  //Height of the camera frame
    const float duration{0.25};            //Duration of the recorded sound in seconds
    const int sampleRate{44100};           //Sample rate of sound
    const int N{44100/4};     //Size of the PCM buffer of sound sample

    const float volume{0.5};    //Output sound volume
    const float Y0{768 * 0.5};    //y-position of the scan line

    //Variables
    std::vector<float> arr;         //Temporary array of pixels brightness, mapped to range [-1,1]
    std::vector<float> buffer;  //PCM buffer of sound sample
    int playPos{0};        //The current position of the buffer playing
    
};
