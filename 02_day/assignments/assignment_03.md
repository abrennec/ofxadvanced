<!-- ---  
title: openFrameworks Advanced
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Winter term 2019/20
---   -->
**openFrameworks Advanced | CTech II**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Assignments 3

Reconsider your software synthesizer prototype. Connect the MIDI controller with your synthesizer in such a way that it allows you to play back melodies. 

### 1 Connect the MIDI controller to your synthesizer ofApp 

Apart from connecting the Midi controller to your software synthesizer via ofxMidi, the goal of this task is to have it control the playing back your sound at different pitches. To do so, consider the following questions:

- What kind of ofxMidi objects will you need to receive Midi messages?
- How can you receive and process the Midi messages?
- What kind of part of the Midi message do you have to evaluate?
- How can you trigger your synth at different pitches?

### 2 Add Sound Changes

In addition to playing back sound at different pitches, conceive an adjustment to the sound itself and trigger a change in sound by sending and processing a program change event. 

