//
//  ofSynth.cpp
//  audio_03_synth
//
//  Created by abrennec on 16.10.19.
//

#include "ofSoundBuffer.h"
#include "ofMath.h"
#include "ofMathConstants.h"
#include "ofSynth.h"

ofSynth::ofSynth(float fundamentalfreq)
: frequency{fundamentalfreq}
{
    
}

void ofSynth::fillSoundBuffer(ofSoundBuffer& outBuffer)
{
    // mapping frequencies from Hz into full oscillations of sin() (two pi)
    float wavePhaseStep = (frequency / outBuffer.getSampleRate()) * TWO_PI;
    float pulsePhaseStep = (0.5 / outBuffer.getSampleRate()) * TWO_PI;
    
    // this loop builds a buffer of audio containing 3 sine waves at different
    // frequencies, and pulses the volume of each sine wave individually. In
    // other words, 3 oscillators and 3 LFOs (frequency < 20hz).
    
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
}


float ofSynth::getFrequency() const {
    
    return frequency;
}


void ofSynth::setFrequency(float freq) {
    
    frequency = freq;
}

void ofSynth::increaseFrequency() {
    
    frequency += 10.0;
}

void ofSynth::decreaseFrequency() {
    
    frequency -= 10.0;
}
