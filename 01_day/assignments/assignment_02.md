<!-- ---  
title: openFrameworks Advanced
author: Angela Brennecke
affiliation: Film University Babelsberg KONRAD WOLF
date: Winter term 2019/20
---   -->
**openFrameworks Advanced | CTech II**

Prof. Dr. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Assignments 2

## Explore and Adapt the Code

### 1 Review the first ofApp example and understand the code.

### 2 Check out the audioOut() function. How is it implemented and what is happening there?

- Comment things out and back in again to get an understanding of the waves

### 3 Play around with the different sound waves to your liking. 

For example, consider the following

- Change the frequency, phase, etc., of the individual sine waves
- Generate different sounds by combining different waves
- Create a underlying beat by simpling using one wave at low frequency with a fast pulse wave
- Create a beat frequency by playing back only 2 frequencies that hardly differ in frequency, i.e., 200 Hz and 201 Hz; slowly increase one frequency 

### 4 Change the Frequency through Mouse Input

Before going into the details of implementing an graphical user interface, start with a simple interface using mouse and keyboard input. Consider the following:

- When pressing "f", frequency changes are expected 
- Any change of mouse_y will result in an increase or decrease of the frequency
