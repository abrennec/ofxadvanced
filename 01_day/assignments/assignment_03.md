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

## Create a Class Diagram

### 1 Checkout the Sound folder in the SDK

Review the three most important audio classes of the SDK in the code to get a first understanding of how they are implemented and how they are related:

- ofSoundBuffer
- ofSoundStream
- ofBaseSoundTypes

How do these classes interconnect? ofSoundStream is a central component of the audio implementation in openFrameworks. Use it as a starting point for creating a class diagram. Start with answering the following questions:

- How are ofSoundBuffer and ofSoundStream related?
- What are ofBaseSoundOutput and ofBaseSoundInput? How do they fit into the diagram?
- Where is the declaration of audioIn and audioOut?
- How is ofBaseApp connected to the sound classes?
- How are ofSoundStreamSettings, ofSoundStream and ofSoundBuffer connected?
