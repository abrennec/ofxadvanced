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
  - [Practice: Code Review](#practice-code-review)
  - [Interaction](#interaction)
  - [MIDI Protocol](#midi-protocol)
    - [Hardware Interface](#hardware-interface)
    - [Communications Protocol](#communications-protocol)
  - [Practice](#practice)
    - [Check out ofxMidi (A1)](#check-out-ofxmidi-a1)
    - [MIDI Notes (A2)](#midi-notes-a2)
  - [Bouncing Balls Concept](#bouncing-balls-concept)
  - [Applying your Synth to Bouncing Balls](#applying-your-synth-to-bouncing-balls)
  - [Performance Aspects](#performance-aspects)
  - [Generic Containers](#generic-containers)
  - [Further Thoughts on Expanding the ofApp](#further-thoughts-on-expanding-the-ofapp)


# Day 2: Interaction and MIDI Control

The second day of the workshop will be dedicated to interaction and aspects of performance. We will connect the previously developed synthesizer to a MIDI controller. Moreover, we will aim for developing a user-driven visual synth. We will explore a classical "bouncing balls" example as a starting point for further development and check out certain generic STL containers to support the object management.

## Practice: Code Review

Before we start working on further features of the synthesizer, we will start with a code review session. Review the previously developed prototype and identify one or two aspects of your implementation that you would like to show and review with the group. Consider aspects where you felt stuck as well as aspects where you found a good solution. 

## Interaction 

With a first software synthesizer application at hand, we will need to find a convenient way to actually trigger the generation of sounds and melodies. Classically, this is achieved by connecting a keyboard controller to the computer that holds the synthesizer software. The keyboard controller themselves do not play or generate any kind of sound. Rather, they serve as host for specific controller knobs and send certain control parameters to the synthesizer. The receiving synthesizer evaluates the sent messages and triggers certain actions, i.e., generates and plays back a sound, switches between sounds, changes certain modulation parameters, etc. The communications protocol that is used for sending and receiving musical information was developed in the early 1980s. It combines both a hardware interface with a software data exchange protocol and is called MIDI - Musical Instrument Digital Interface.

## MIDI Protocol 

The MIDI standard was introduced in the 1980's as a one-way communications protocol and digital interface description. MIDI allows for connecting software and hardware synthesizers as well as for controlling more than one synthesizer with only one keyboard controller. This is achieved by a dedicated **MIDI hardware interface** and data communications protocol. The latter defines how **MIDI messages** package and exchange musical data between the connected instruments and is defined by the MIDI standard. 

### Hardware Interface

The MIDI hardware interface consist of three different **MIDI ports** that are connected via specific **MIDI cables**

- MIDI IN - for receiving MIDI messages (and subsequently processing them)
- MIDI THRU - for passing on MIDI messages (to another instruments)
- MIDI OUT - for sending MIDI message out (to other instruments)

The introduction of these three ports allowed to easily connect several different MIDI instruments with each other resulting in new ways of layering sounds and playing back polyphonic notes. The following image illustrates the typical MIDI interface ports.

Image

With the increase of software synthesizers and computer generated music, MIDI-to-USB ports have been introduced simplifying the connection of MIDI controllers to computers further. Prior to that, MIDI ports often times were only directly connected to computers with the help of sound cards and audio interfaces.

### Communications Protocol

Central to the communications protocol is the **MIDI message** which carries the musical information encoded in the form of bytes. The byte information a MIDI message contains is composed of two different types of bytes:

- 1 **status byte** which is divdided into 2 Nybbles (2*4 bits) to define
  - MIDI events (bits 5 to 8, stores up to 8 different values)
  - MIDI channels (bits 1 to 4, stores up to 16 different values)
- 1 or more **data bytes** which provide more information on the specific event being sent.

The status byte is defined by the fact that its most significant bit (msb) is always set to 1 whereas the data bytes are defined such that their most significant bit (msb) is always set to 0. This way, you can clearly differentiate the two byte types. Status byte values range from 128 (1000 0000) to 255 (1111 1111) whereas data byte values range from 0 (0000 0000) to 127 (0111 1111).

The following Image illustrates the 8 different **MIDI event types** and the information encoded in the corresponding data bytes:

Image

Midi was primarily introduced to connect and control multiple instruments. One central element of the midi protocol therefore is the **MIDI Channel**. MIDI protocol supports 16 MIDI channels which means, a MIDI controller can send data to 16 different instruments. The sending and receiving MIDI control and/or instrument must specify the channel it is sending and receiving on. Only then a receiving instrument will be able to further process the sent MIDI message.

## Practice

### Check out ofxMidi (A1)

openFrameworks also supports the MIDI communications protocol with the help of a dedicated ofxMidi addon. 

- Check out the first assignment sheet in the assignments folder for further instructions.
- You are encouraged to discuss the questions and answers in the group.



### MIDI Notes (A2)

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

Reconsider your software synthesizer prototype. Connect the MIDI controller with your synthesizer in such a way that it allows you to play back melodies. Check out the second assignment sheet for further instructions. 

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

For further information on MIDI refer to

- Refining Sound, Chapter 7 - External Control Sources
- https://www.midi.org
- https://www.delamar.de/beats/selber-machen/sequenzer-midi/ 