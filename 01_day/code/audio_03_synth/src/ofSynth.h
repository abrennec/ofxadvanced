//
//  ofSynth.h
//  audio_03_synth
//
//  Created by abrennec on 16.10.19.
//

#pragma once

class ofSoundBuffer;

class ofSynth {
    
    
public:
    
    ofSynth(){};
    ofSynth(float fundamentalfreq);
    ~ofSynth(){};
    
    void fillSoundBuffer(ofSoundBuffer& buffer);

    float getFrequency() const;
    void setFrequency(float freq);
    void increaseFrequency();
    void decreaseFrequency();
    
    
private:
  
    double wavePhase{};
    double pulsePhase{};
    float rms{};
    float frequency{};
    
    
};
