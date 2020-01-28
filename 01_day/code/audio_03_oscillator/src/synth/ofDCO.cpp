//
//  ofDCO.cpp
//  audio_04_osc
//
//  Created by abrennec on 31.10.19.
//

#include "synth/ofDCO.h"

ofDCO::ofDCO()
{
    updatePhaseIncrement();
};


ofDCO::ofDCO(const float& freq, const float& amp, const float& phs)
: frequency(freq), amplitude{amp}, phase{phs}
{
    updatePhaseIncrement();
};

void ofDCO::updatePhaseIncrement() {
    
    phaseInc = frequency / sampleRate;
}
