//
//  ofSynth.cpp
//  audio_03_synth
//
//  Created by abrennec on 16.10.19.
//

#include "ofSoundBuffer.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "synth/ofSynth.h"


// needs to be improved
// potential improvements:
// array of oscillators - problem parameterization
// setup function to specify synth and oscillators separately
// ref or ptr to sound settings in order to reduce amount of function calls

ofSynth::ofSynth(float fundamentalfreq)
: fundamentalFreq{fundamentalfreq},
sineWaveOscillator1{fundamentalfreq, 1.0, 0.0},
sineWaveOscillator2{fundamentalfreq, 0., 0.0},
sineWaveOscillator3{fundamentalfreq, 0.5, 0.0},
sineWaveOscillator4{fundamentalfreq, 0., 0.0},
sineWavePulse1{2.5},
sineWavePulse2{0.5, 1.0, 0.0}
{
    sineWaveOscillator1.setPhaseModifier(1.0);
    sineWaveOscillator2.setPhaseModifier(3.2);
    sineWaveOscillator3.setPhaseModifier(0.8);
    sineWaveOscillator4.setPhaseModifier(4.0);
    
    sineWavePulse1.setPhaseModifier(0.98);
    sineWavePulse2.setPhaseModifier(3.98);
}

void ofSynth::fillSoundBuffer(ofSoundBuffer& outBuffer)
{
    auto sampleRate = outBuffer.getSampleRate();
    
    sineWaveOscillator1.setSampleRate(sampleRate);
    sineWaveOscillator2.setSampleRate(sampleRate);
    sineWaveOscillator3.setSampleRate(sampleRate);
    sineWaveOscillator4.setSampleRate(sampleRate);
    
    sineWavePulse1.setSampleRate(sampleRate);
    sineWavePulse2.setSampleRate(sampleRate);
    
    // this loop builds a buffer of audio containing 3 sine waves at different
    // frequencies, and pulses the volume of each sine wave individually. In
    // other words, 4 oscillators and 2 LFOs (frequency < 20hz).
    
    for(auto i = 0; i < outBuffer.getNumFrames(); i++) {
        
        // build up a chord out of sine waves at 3 different frequencies
        auto sampleLow = sineWaveOscillator1.generate();
        auto sampleMid = sineWaveOscillator2.generate();
        auto sampleHi = sineWaveOscillator3.generate();
        auto sampleMidHi = sineWaveOscillator4.generate();
        
        auto samplePulse = sineWavePulse1.generate();
        
        // pulse one frequency
        auto freq = sineWaveOscillator1.getFrequency();
        freq *= samplePulse;
        sineWaveOscillator1.setFrequency(freq);
        
        //float fullSample = (sampleLow + sampleMid + sampleHi);
        auto sampleFull = (sampleLow + sampleMid + sampleHi + sampleMidHi);
        
        // reduce the full sample's volume so it doesn't exceed 1
        sampleFull *= 0.3;
        
        sampleFull = ofClamp(sampleFull, -.9f, .9f);
        
        // write the computed sample to the left and right channels
        outBuffer.getSample(i, 0) = sampleFull;
        outBuffer.getSample(i, 1) = sampleFull;

    }
}


void ofSynth::setFrequency(const float& freq) {
    
    fundamentalFreq = freq;
    updateOscillatorFreq(freq);
}

void ofSynth::increaseFrequency() {
    
    fundamentalFreq += 10.0;
    updateOscillatorFreq(fundamentalFreq);
}

void ofSynth::decreaseFrequency() {
    
    fundamentalFreq -= 10.0;
    updateOscillatorFreq(fundamentalFreq);
}

void ofSynth::updateOscillatorFreq(const float& freq) {
    
    sineWaveOscillator1.setFrequency(freq);
    sineWaveOscillator2.setFrequency(freq);
    sineWaveOscillator3.setFrequency(freq);
    sineWaveOscillator4.setFrequency(freq);
}
