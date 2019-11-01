<!-- ---  
title: openFrameworks Advanced
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Winter term 2019/20
---   -->
**openFrameworks Advanced | CTech II**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Assignments 4

## User Driven Interaction

### 1 Change the Frequency through Mouse Input

Before going into details of implementing a chromatic change in frequencies, start with a simple interface:

- When pressing "f", frequency changes are expected 
- Any change of mouse_y will result in an increase or decrease of the frequency


### 2 Consider introducing ofSynth Class

Review the current implementation of the ofApp example and consider introducing a dedicated ofSynth class to encapsulate the sound specific implementations.


### 3 Consider the Chromatics Scale and MIDI Note Numbers  

Conceive a user interface for your ofApp that allows for playing back 128 different pitches with mouse and/or keyboard. 

- What kind of data types and what kind of functions do you have to specify in order to play back different pitches?
- Often, the following computer keys are used to represent an octave of piano keys
  - a,  w, s,  e, d, f,  t, g,  z, h,  u, j
  - C, C#, D, D#, E, F, F#, G, G#, A, A#, B 
- How could swtich between octaves in the interface?

Implement your interface concept for playing back 128 different pitches according to the chromatic scale.


### 3 Consider Sound Adjustments

In addition to playing back sound at different pitches, pick one or two more sound specific parameters (i.e., pulse wave properties) and map them to your interface to adjust the sound.