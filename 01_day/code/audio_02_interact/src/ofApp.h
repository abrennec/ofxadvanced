#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    public:
    
        ofApp();

        void setup();
        void update();
        void draw();
    
        void audioOut(ofSoundBuffer &outBuffer);

    	void exit();
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    
    private:

    
        void drawHelpText();
    
        double wavePhase{0};
        double pulsePhase{0};
        float rms{};
        float frequency{};
    
        bool changeFreq{};
        int initialMouseDistY{};
    
        std::mutex audioMutex{};
        ofSoundStream soundStream{};
        ofSoundBuffer lastBuffer{};
        ofPolyline waveform{};
    
};
