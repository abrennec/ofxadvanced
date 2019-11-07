//
//  ofSynth.h
//  audio_03_synth
//
//  Created by abrennec on 16.10.19.
//

#pragma once

#include "synth/ofDCOBaseTypes.h"

class ofSoundBuffer;

class ofSynth {
    
public:
    
    ofSynth(){};
    ofSynth(float fundamentalfreq);
    ~ofSynth(){};
    
    void fillSoundBuffer(ofSoundBuffer& buffer);

    float getFrequency() const;
    void setFrequency(const float& freq);
    void increaseFrequency();
    void decreaseFrequency();
    
    
private:
  
    void updateOscillatorFreq(const float& freq);
    
    
    float rms{};
    float fundamentalFreq{};
    
    //std::shared_ptr<ofDCOSine> sineWaveOscillator{};
    ofDCOSine sineWaveOscillator1{};
    ofDCOSine sineWaveOscillator2{};
    ofDCOSine sineWaveOscillator3{};
    ofDCOSine sineWaveOscillator4{};
    ofDCOPulse sineWavePulse1{};
    ofDCOSine sineWavePulse2{};
    
    
};


// inline can improve performance but this is not ensured
// more info at https://isocpp.org/wiki/faq/inline-functions
inline
float ofSynth::getFrequency() const {
    
    return fundamentalFreq;
}

