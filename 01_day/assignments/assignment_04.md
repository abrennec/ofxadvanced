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

The general goal of this task is to develop and implement a first prototype of a software synthesizer. First of all, the application should generate one specific sound using one or switching between one or more oscillators. 

### 1 Base Type Oscillators

To start with, pick one of the basic wave type oscillators not creating sine wave sounds and think about an algorithmic solution to create the particular wave type that does not necessarily involve sine wave combination. How could you create a similar wave form?

### 2 Conceive a simple software synthesizer 

The software should be conceived such that it generates a specific sound to your liking. It should be possible to at least change the fundamental frequency of the sound, the corresponding amplitude and phase parameters. Moreover, the synth should feature at least two different wave types and should be designed that more oscillator types can be added easily. In terms of interaction, the synthesizer should allow for switching between the oscillator types. The synthesizer should be independent from ofApp as much as possible so that you might be able to easily re-use your code with a different SDK.
Consider the following questions to get started:

- What kind of classes and objects will you need to specify?
- How will the classes be related to each other?
- What kind of interface to the ofApp class do you have to conceive?
- What kind of oscillator types would you like to develop? Consider, for instance,
  - monophonic or polyphonic sounds based on the sine wave type
  - harmonic and / or inharmonic sounds
  - any kind of the basic sound wave types

### 3 Refactor the ofApp following your design
