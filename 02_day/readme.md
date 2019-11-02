<!-- ---  
title: openFrameworks Advanced
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Winter term 2019/20
---   -->
**openFrameworks Advanced | CTech II**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

**Table of Contents**
- [Day 2: Interaction and MIDI Control](#day-2-interaction-and-midi-control)
  - [MIDI Protocol](#midi-protocol)
  - [Bouncing Balls Concept](#bouncing-balls-concept)
  - [Applying your Synth to Bouncing Balls](#applying-your-synth-to-bouncing-balls)
  - [Performance Aspects](#performance-aspects)
  - [Generic Containers](#generic-containers)
  - [Further Thoughts on Expanding the ofApp](#further-thoughts-on-expanding-the-ofapp)


# Day 2: Interaction and MIDI Control

The second day of the workshop will be dedicated to interaction and aspects of performance. We will connect the previously developed synthesizer to a MIDI controller. Moreover, we will aim for developing a user-driven visual synth. We will explore a classical "bouncing balls" example as a starting point for further development and check out certain generic STL containers to support the object management.

## MIDI Protocol 

Get back to coding and extend the ofApp with interaction. Primarily, add some functionality to change the frequency that is being generated. Frequency changes should follow the chromatic scale and implement a simple MIDI (Musical Instrument Digital Interface) approach. Although we will not look into MIDI deeply, the following information will give you enough input to get started.

The MIDI standard was introduced in the 1980's as a communication protocol and digital interface description. MIDI allows for connecting computers and musical instruments like keyboards and synthesizers and having them exchanging musical data defined by the MIDI standard. This way, digital instruments as well as simple hardware controllers can be used to send MIDI data, "MIDI messages", to computers, other instruments and/or vice versa. 

A MIDI message usually contains all the information necessary to describe (and thus trigger) a musical event, for example. One part of a MIDI message is the **note number** which refers to the actual pitch. MIDI supports 128 different note numbers aka pitches and thus up to 10 different octaves. One octave is comprised of 12 individual pitches, for example: 

- C, C#, D, D#, E, F, F#, G, G#, A, A#, B (chromatic scale with sharps "#")
- C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B (equivalent scale with flats "b")

The general formula to calculate any frequency given a certain reference frequency is as follows:

- af = rf * 2 ^ ((cn - rn) / 12.0) 

.. with these components:

- "^" meaning "to the power of"
- af referring to the frequency to be calculate, i.e., any frequency
- rf referring to the reference frequency
- cn referring to the current MIDI note number
- rn referring to the reference MIDI note number

For example, given 440 Hz (pitch A4, MIDI note number 69) as a reference frequency, the formula would look like this:

- af = 440.0 * 2 ^ (midiVal-69)/12.0))

Your task will now be to think about how to implement this exact formula for a set of 128 different note numbers. Check out the second assignment sheet for further instructions. 

For further information on MIDI refer to
- https://www.midi.org
- https://www.delamar.de/beats/selber-machen/sequenzer-midi/ 



## Bouncing Balls Concept



## Applying your Synth to Bouncing Balls

- scales (major, minor)


## Performance Aspects

- object creation
- slider to adjust number of objects
- copying data, audio input ?


## Generic Containers



## Further Thoughts on Expanding the ofApp 

To deepen your understanding of audio programming either in regards to software design or in regards to the implementation of MIDI communication protocol, take a closer look at the implementations in the following ofxAddon:

- ofxMidi

Interestingly, ofxMidi has been build on top of RtMidi (Midi counterpart to RtAudio). More information can be found at the github repository https://github.com/danomatika/ofxMidi.