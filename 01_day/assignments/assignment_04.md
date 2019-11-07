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

## Create a Software Synthesizer Prototype

The general goal of this task is to develop and implement a first prototype of a software synthesizer. First of all, the application should generate one or two specific sounds to your liking and allow for switching between one or more oscillators. 

In terms of interaction, tt should be possible to change the fundamental frequency of the sound interactively. Moreover, the synth should feature at least two different wave types and should be designed such that more oscillator types can be added easily. The synthesizer should allow for switching between the oscillator types. 

In terms of the implementation, consider making the synthesizer independent from ofApp as much as possible so that you might be able to easily re-use your code with a different SDK.

Consider the following questions to get started:

- What kind of classes and objects will you need to specify?
- How will the classes be related to each other?
- What kind of interface to the ofApp class do you have to conceive?
- What kind of oscillator types would you like to develop? Consider, for instance,
  - monophonic or polyphonic sounds based on the sine wave type
  - harmonic and / or inharmonic sounds
  - any kind of the basic sound wave types

### 1 Refactoring

Start with refactoring. The current version of the app only uses sine waves and their combinations. Refactor the implementation such that you introduce, for example, the following classes

- ofSynth - tbd
- ofOscillator - tbd 
- ofSineWaveOscillator - tbd

Keep in mind that you will want to add more specific oscillators, i.e., a pulse wave, sawtooth wave and triangle wave oscillator. How would you be able to do so?


### 2 Base Type Oscillators

#### 2.1 

Pick one of the basic wave type oscillators not creating sine wave sounds and think about an algorithmic solution to create the particular wave type that does not necessarily involve sine wave combination. How could you create a similar wave form? (Hint: the pulse wave is a good starting point).

We will discuss the solutions in class but you can feel free to start implementing your approach.

Optionally, you may want to add a second implementation of the non-sine wave using the Fourier series. How do the sounds differ?

#### 2.2 

Connect your newly introduced base type oscillator to the user interface and switch between sine wave and non-sive wave.

### 3 Play, Review and Expand 

Play around with the different oscillators and use one oscillator to modify the other. 

Specify, for example, one sound to be very harmonic and another sound to be rather inharmonic.