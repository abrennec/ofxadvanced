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
- [Overview of the Course](#overview-of-the-course)
  - [Organization](#organization)
  - [Course Description](#course-description)
  - [Learning Objectives](#learning-objectives)
  - [Grading](#grading)
- [Syllabus](#syllabus)
  - [Day 1 - Sound Generation with openFrameworks](#day-1---sound-generation-with-openframeworks)
  - [Day 2 - MIDI Control and Graphical Objects](#day-2---midi-control-and-graphical-objects)
  - [Day 3 - Driving Sound with Images](#day-3---driving-sound-with-images)
- [Communication & Materials](#communication--materials)
- [Technical Setup](#technical-setup)
  - [Pre-requisites](#pre-requisites)
  - [XCode 11 | Note for MacOS Users](#xcode-11--note-for-macos-users)
- [Further Readings](#further-readings)
  - [Books](#books)
  - [Online Resources](#online-resources)

---

# Overview of the Course

## Organization 

- Friday 8th, Thursday 14th & Friday 15th November,  10 h - 17 h
- 1.5 SWS | 1 ECTS minimum
- openFrameworks Advanced workshop

## Course Description 

In this course, we will use [openFrameworks](http://openframeworks.cc) as our creative coding toolkit and will explore its capabilities to work with audio and visuals. To do so, we will first dive into the specifics of how openFrameworks implements audio and provides access to the underlying audio hardware APIs. Following that, we will synthesize sounds using openFrameworks soundbuffers and output routines. We will use MIDI control and the chromatic scale to create melody and interact with the sounds. Finally, we will explore how to visualize certain sound parameters and connect them with graphical sound objects. The interaction will primarily be user-driven yet in a last step we will explore image data to drive our sound generation.

The assignments will help you understanding more advanced programming concepts of openFrameworks. Moreover, the coding assignments are intended to be built upon in the case you would like to extend them further.


## Learning Objectives

- Deepening the understanding of the openFrameworks SDK and C++ 
- Understanding the connection between application and driver software 
- Getting to know the STL containers list, deque, and map and exploiting them for performance
- Reading unknown code and understanding its software design 
- Applying your theoretical knowledge in smaller and larger practical programming examples
- Developing and expressing your own artistic ideas with openFrameworks 

## Grading 

Attendance is everything. You will receive 1 ECTS for participation. If you would like to further develop the workshop project, we can agree on a feature set and additional ECTS.

---

# Syllabus

## Day 1 - Sound Generation with openFrameworks

The first day of the workshop will be dedicated to understanding how openFrameworks implements sound and connects software with the underlying hardware (i.e., audio interface / soundcard). We will derive a first software design diagram and implement a first prototype of an interactive synthesizer. 


## Day 2 - MIDI Control and Graphical Objects

The second day of the workshop will be dedicated to connecting your synthesizer to a MIDI controller and certain graphical objects. We will check out generic STL containers and aim for developing a user-driven visual synth. We will explore a classical "bouncing balls" example as a starting point for further development.

## Day 3 - Driving Sound with Images

The third day of the workshop will be dedicated to continuing the implementation of our interactive visual synths. We will explore image data as an input source for driving the sound generators. 

--- 

# Communication & Materials

As a communication platform, we will use [GitHub.com](https://github.com/) to share code, lecture materials, comments, and submit project assignments.

- [GitHub repository (public)](https://github.com/ctechfilmuniversity/ws1920_ofa)

The repository will be used to share lectures, coding examples, homework and project materials. The Wiki will be used to share information that might be useful for everyone. 

---

# Technical Setup

## Pre-requisites

To participate in this workshop, you will need the following:

- Ideally, a notebook with access to web cam, speakers, and headphones (will be provided). 
- The latest version of openFrameworks that you can download online at https://openframeworks.cc/download/
- Git for version control as well as access to GitHub
- A development IDE supported by openFrameworks like
  - XCode on MacOS
  - MS Visual Studio on Windows
  - Visual Studio Code, supported on both machines but you usually have to manually adjust your build scripts, etc.

**Note** If you would like to borrow a notebook, please get in touch with Angela on 4th Nov the latest.


## XCode 11 | Note for MacOS Users

With XCode 11, a new codesigning restriction has been introduced by Apple that requires all dynamic libraries that are used in the development process to be code signed. This is not true for the external libraries required by openFrameworks that ship with the last stable release of openFrameworks v0.10.1. Whenever you try to compile an ofApp v0.10.1, the linker error message "Command /usr/bin/codesign failed with exit code 1 running Xcode project" is thrown and the build process interrupts. 

To fix this problem, you have three solutions:

- Downgrade XCode to pre-v11
- Download a nightly build of openFrameworks and
  - use it or
  - simply copy the library "libmodex.dylib" from the folder libs/fmodex/lib/osx/* from the ofx nightly build to that same folder of the latest stable build; nightly builds can be downloaded from here
  - https://openframeworks.cc/download/ 
- Alternatively, you might also use the latest Github version of openFrameworks and its external dependencies. The nightly builds can be downloaded from the official website here:


More details can be found here:

- https://stackoverflow.com/questions/58189980/command-usr-bin-codesign-failed-with-exit-code-1-running-xcode-project
- https://forum.openframeworks.cc/t/cant-run-examples-in-xcode-signing-issue-with-libfmodex-dylib/33463



---

# Further Readings

## Books 

Main source of the theoretical aspects of the workshop is the book

- Brian K. Shepard (2013): Refining Sound. A Practical Guide to Synthesis and Synthesizers. Oxford University Press.

### Creative Coding <!-- omit in toc -->

- Ira Greenberg (2007): Processing: Creative Coding & Computational Art. Berkley, CA: Friends of ED/Apress Press.
- Bill Manaris & Andrews R. Brown (2014): Making Music with Computers. New York, NY: Chapman & Hall / CRC Press.
- Joshua Noble (2009): Programming Interactivity. A Designer’s Guide to Processing, Arduino & openFrameworks. Sebastopol, CA: O’Reilly Media Inc.

### C/C++  <!-- omit in toc -->

- Bjarne Stroustrup (2013): The C++ Programming Language. Upper Saddle River, NJ: Pearson Education, Inc.
- Bjarne Stroustrup (2014): Programming. Principles & Practices Using C++. Upper Saddle River, NJ: Addison-Wesley.
- Scott Meyers („Effective C++“ series, advanced)
- Herb Sutter („Exceptional C++“ series, really advanced)

### Software Design <!-- omit in toc -->

- Grady Booch (1994): Object-oriented Analysis and Design. Addison-Wesley. NY, USA.
- Robert C. Martin (2009): Clean Code. Prentice Hall. NY, USA.
- Robert C. Martin (2017): Clean Architecture. Prentice Hall. NY, USA.


## Online Resources

- [learncpp](http://www.learncpp.com)
- [cppreference](http://www.cppreference.com/)
- [cplusplus](http://www.cplusplus.com/)
- [fluentcpp](https://www.fluentcpp.com)
- [ofBook](https://github.com/openframeworks/ofBook/tree/master/chapters)
- [openFrameworks Forum](http://forum.openframeworks.cc/)
