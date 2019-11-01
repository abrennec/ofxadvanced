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
- [Day 1: Sound Generation with openFrameworks](#day-1-sound-generation-with-openframeworks)
  - [openFrameworks and Sound](#openframeworks-and-sound)
    - [ofSoundBuffer](#ofsoundbuffer)
    - [ofSoundStream](#ofsoundstream)
    - [ofSoundBaseTypes](#ofsoundbasetypes)
  - [Recap C++ Programming Specifics (A1)](#recap-c-programming-specifics-a1)
  - [ofApp: Sound Buffer Example (A2)](#ofapp-sound-buffer-example-a2)
  - [Software Design Diagram (A3)](#software-design-diagram-a3)
  - [ofApp: User Driven Interaction (A4)](#ofapp-user-driven-interaction-a4)
  - [Further Thoughts on Expanding the ofApp](#further-thoughts-on-expanding-the-ofapp)


# Day 1: Sound Generation with openFrameworks

The first day of the workshop will be dedicated to understanding how openFrameworks implements sound and connects software with the underlying hardware (i.e., audio interface / soundcard). You will derive a first software design diagram and implement a first prototype of an interactive synthesizer. 


## openFrameworks and Sound

The openFrameworks SDK has dedicated components for audio and sound processing located in the “sound” folder of the SDK. Most important concepts to understand how openFrameworks handles sound and audio processing are defined in these three classes:

- ofSoundBuffer
- ofSoundStream
- ofSoundBaseTypes

### ofSoundBuffer

The **ofSoundBuffer** class is the main class that defines an audio buffer object including parameters like buffer data, channels, frames, sampleRate, etc. and functionality like getSample(), fillWithTone(...), etc.
It is used to hold the real audio data which is implemented as an array of interleaved floating point samples. In order to process the audio data correctly, it is of utmost importance to understand, set and evaluate the following two parameteres:

- channel
- frame

The channel describes the "spatial" setup of the audio buffer, i.e., how the audio data will be mapped to the speakers. For example, 1 channel means "mono" playback, 2 channels mean "stereo" playback, 6 channels mean "surround sound" or 5.1 playback with 3 channels in the front, two channels in the back (all of them in the range of 20-20k Hz) and one low frequency (in the range of 20-120Hz) channel, etc. An example of a mono channel array would be 

- Mono channel array: [L, L, L, L, L, L, L, L]
- Stereo channel array: [L,R, L,R, L,R, L,R, L,R, L,R, L,R, L,R] 
- Surround channel array: [ ??? ] 

The frame describes the set of related audio samples, i.e., in the example of the mono channel array, we have 8 frames, 1 channels and also 8 individual samples. In contrast, in the stereo case, we have again 8 frames yet 2 channels and accordingly 8 (frames) x 2 (channels) = 16 samples. How would that look like in case of surround sound?

### ofSoundStream

The **ofSoundStream** class is a "wrapper" class that defines a sound stream object. A sound stream object describes how the (openFrameworks) software connects with the hardware’s audio input and output devices, i.e., the audio interfaces and soundcards. To be more precise, the concept behind a sound stream object is to connect the application software with the (harwdware) driver software (i.e., the API of the soundcard driver). 

The ofSoundStream object is rarely used directly. It can be specified by proceeding as follows:

- Add an **ofSoundStreamSettings** object to the ofApp and set its parameters.
- Call the static function **ofSoundStreamSetup( ofSoundStreamSettings& )** to initialize the sound stream.
- Define the callback methods **audioIn (...)** and  **audioOut(...)** in your ofApp.

The latter are defined in ofBaseApp and are automatically called whenever the system receives sound from the soundcard or before the app sends sound out to the soundcard. Both methods require the function ofSoundStreamSetup( ofSoundStreamSettings& ) to be called in advance.

#### Advanced Implementation Details <!-- omit in toc -->

openFrameworks itself does not handle the connection to a specific driver API however. Instead, it makes use of an external audio library called RTAudio library. RTAudio library is developed at McGill University and takes care of easily providing access to various different audio interface driver API's. For example, RTAudio library is an API that can handle OSX Core Audio, ALSA, Asio4all, and many more. Hence, calling the ofSoundStreamSetup function actually starts the RTAudio library and triggers the setup of a sound stream.

To be more precise, openFrameworks provides an ofRTAudioSoundStream class which derives from ofSoundStream and implements the connection to the RTAudio library. All applications or "clients" that want to make use of RTAudio must create a function called **RtAudioCallback**. This function is being called by RTAudio and allows for reading and writing data from and to the audio stream. When the underlying audio system is ready for new input, this function is being invoked. Check out how openFrameworks implements and uses this function.

Finally, during compilation the compiler defines the sound stream API to be used (RTAudio for desktop, Android, iOS, emscripten, .. ) as defined in utils/ofConstants.h.

- See also RTAudio.h 
- See also https://openframeworks.cc/documentation/sound/ofSoundStream/


### ofSoundBaseTypes

The ofSoundBaseTypes header file provides a collection of different objects required to setup audio processing with openFrameworks. The following classes are part of the ofSoundBaseTypes:

- ofBaseSoundInput & ofBaseSoundOutput (ofBaseApp’s parents, audioIn, audioOut)
- ofSoundDevice (sound device interface APIs)
- ofSoundStreamSettings (connects app & device through callback function; specifies the sound stream, setOutListenenr, setInListener)
- ofBaseSoundStream (the real sound stream base class; sends sound buffer through ofSoundStreamSettings callback to app)
- ofBaseSoundPlayer (playback audio files)


## Recap C++ Programming Specifics (A1)

To understand the way the openFrameworks SDK implements sound and audio, you might want to recap some specifics of the C++ programming language. Please check out the first assignment sheet in the assignments folder and start to answer the questions there. You are encouraged to discuss the questions and answers in the group.


## ofApp: Sound Buffer Example (A2)

Check out the first coding example in the code folder. Build and run the example. Review the ofApp code and understand what is happing there. Start to adjust the parameters in the audioOut method and change the sound that is being played back. Check out the second assignment sheet for further instructions. 


## Software Design Diagram (A3)

Now that you have become a little familiar with the ofApp class and started to adapt the example, check out the underlying implementation in the SDK and review the audio classes **ofSoundBuffer**, **ofSoundStream** and **ofBaseSoundTypes**. How are these classes connected? Try to derive a software design diagram as best as you can. Check out the second assignment sheet for further instructions. You are encouraged to discuss all questions that come up in the group.


## ofApp: User Driven Interaction (A4)

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


## Further Thoughts on Expanding the ofApp 

To deepen your understanding of audio programming either in regards to software design or in regards to the implementation of sound generators, interaction with sound and sound modulation, check out the following ofxAddons:

- ofxATK
- ofxPDSP
- ofxMidi

The addons ofxATK and ofxPDSP provide deep inside into audio programming and come with a bunch of nice examples. Unfortunately, ofxATK has not been maintained recently; ofxPDSP is continuously being developed however some of the examples do not compile. Nonetheless, I recommend to look into both addons to get more and more familiar with the underlying concepts and / or to exploit some of the provided functionalities. 

Interestingly, ofxMidi has been build on top of RtMidi (Midi counterpart to RtAudio). More information can be found at the github repository https://github.com/danomatika/ofxMidi.
