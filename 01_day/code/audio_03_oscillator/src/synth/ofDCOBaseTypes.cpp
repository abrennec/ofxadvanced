//
//  ofDCOBaseTypes.cpp
//  audio_04_osc
//
//  Created by abrennec on 31.10.19.
//

#include "ofDCOBaseTypes.h"
#include "ofMathConstants.h"

ofDCOSine::ofDCOSine()
: ofDCO()
{
    updatePhaseIncrement();
}

ofDCOSine::ofDCOSine(const float& freq)
:ofDCO(freq)
{
    updatePhaseIncrement();
}

ofDCOSine::ofDCOSine(const float& freq, const float& amp, const float& phs)
: ofDCO(freq, amp, phs)
{
    updatePhaseIncrement();
}

float ofDCOSine::generate() {
    
    currentSample = amplitude * sin(phase * phaseMod);
    phase += phaseInc;
    return currentSample;
}

void ofDCOSine::updatePhaseIncrement() {
    
    // calculating phase increment
    phaseInc = frequency * TWO_PI / sampleRate;
}

// -----------------

ofDCOTriangle::ofDCOTriangle()
: ofDCO()
{
    updatePhaseIncrement();
}

ofDCOTriangle::ofDCOTriangle(const float& freq)
:ofDCO(freq)
{
    updatePhaseIncrement();
}

ofDCOTriangle::ofDCOTriangle(const float& freq, const float& amp, const float& phs)
: ofDCO(freq, amp, phs)
{
    updatePhaseIncrement();
}

float ofDCOTriangle::generate() {
    
    currentSample = amplitude * sin(phase * phaseMod);
    phase += phaseInc;
    return currentSample;
}

void ofDCOTriangle::updatePhaseIncrement() {
    
    // calculating phase increment
    phaseInc = frequency * TWO_PI / sampleRate;
}


// -----------------

ofDCOSawTooth::ofDCOSawTooth()
: ofDCO()
{
    updatePhaseIncrement();
}

ofDCOSawTooth::ofDCOSawTooth(const float& freq)
:ofDCO(freq)
{
    updatePhaseIncrement();
}

ofDCOSawTooth::ofDCOSawTooth(const float& freq, const float& amp, const float& phs)
: ofDCO(freq, amp, phs)
{
    updatePhaseIncrement();
}

float ofDCOSawTooth::generate() {
    
    currentSample = amplitude * sin(phase * phaseMod);
    phase += phaseInc;
    return currentSample;
}

void ofDCOSawTooth::updatePhaseIncrement() {
    
    // calculating phase increment
    phaseInc = frequency * TWO_PI / sampleRate;
}


// -----------------

ofDCOPulse::ofDCOPulse()
: ofDCO()
{
    updatePhaseIncrement();
}

ofDCOPulse::ofDCOPulse(const float& freq)
:ofDCO(freq)
{
    updatePhaseIncrement();
}

ofDCOPulse::ofDCOPulse(const float& freq, const float& amp, const float& phs)
: ofDCO(freq, amp, phs)
{
    updatePhaseIncrement();
}

float ofDCOPulse::generate() {
    
    currentSample = sin(phase * phaseMod) > 0 ? 1. : -1.;
    currentSample *= amplitude;
    
    phase += phaseInc;
    return currentSample;
}

void ofDCOPulse::updatePhaseIncrement() {
    
    // calculating phase increment
    phaseInc = frequency * TWO_PI / sampleRate;
}

