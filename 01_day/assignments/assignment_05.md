<!-- ---  
title: openFrameworks Advanced
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Winter term 2019/20
---   -->
**openFrameworks Advanced | CTech II**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Assignments 5

## Combining Sine Waves

### 1 Change the Frequency through Mouse Input

Before going into details of implementing a chromatic change in frequencies, start with a simple interface:

- When pressing "f", frequency changes are expected 
- Any change of mouse_y will result in an increase or decrease of the frequency

### 2 Conceive a first software design for a synthesizer 

The synthesizer should provide at least two different types of sound wave shapes. Furthermore it should allow to change individual parameters.

### 3 Refactor the ofApp: Consider introducing ofSynth Class

Review the current implementation of the ofApp example and consider introducing a dedicated ofSynth class to encapsulate the sound specific implementations.
