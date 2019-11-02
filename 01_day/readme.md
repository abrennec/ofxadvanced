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
  - [Practice](#practice)
    - [Recap C++ Programming Specifics (A1)](#recap-c-programming-specifics-a1)
  - [openFrameworks and Sound](#openframeworks-and-sound)
    - [ofSoundBuffer](#ofsoundbuffer)
    - [ofSoundStream](#ofsoundstream)
    - [ofSoundBaseTypes](#ofsoundbasetypes)
  - [Practice](#practice-1)
    - [ofApp: Sound Buffer Example (A2)](#ofapp-sound-buffer-example-a2)
    - [Software Design Diagram (A3)](#software-design-diagram-a3)
  - [Sound Generation and Synthesis](#sound-generation-and-synthesis)
  - [Basic Oscillator Wave Types](#basic-oscillator-wave-types)
    - [Sine wave](#sine-wave)
      - [Harmonic sounds](#harmonic-sounds)
    - [Pulse wave](#pulse-wave)
    - [Triangle wave](#triangle-wave)
    - [Sawtooth wave](#sawtooth-wave)
  - [Practice](#practice-2)
    - [Create a Software Synthesizer Prototype (A4)](#create-a-software-synthesizer-prototype-a4)
  - [Controlling An Oscillator with Another](#controlling-an-oscillator-with-another)
    - [Sound Synthesis Sync](#sound-synthesis-sync)
    - [Amplitude Modulation (AM)](#amplitude-modulation-am)
    - [Frequency Modulation (FM)](#frequency-modulation-fm)
  - [Practice](#practice-3)
    - [Extend the Software Synthesizer Prototype (A5)](#extend-the-software-synthesizer-prototype-a5)
  - [Further Thoughts on Expanding the ofApp](#further-thoughts-on-expanding-the-ofapp)


# Day 1: Sound Generation with openFrameworks

The first day of the workshop will be dedicated to sound generation and software design. First, we will focus on understanding how openFrameworks implements sound and connects software with the underlying hardware (i.e., audio interface / soundcard). Second we will start exploring an ofApp synthesis example and develop a first prototype of a software synthesizer.


## Practice

### Recap C++ Programming Specifics (A1) 

To understand the way the openFrameworks SDK implements sound and audio, we will recap some specifics of the C++ programming language first of all. 

- Check out the first assignment sheet in the assignments folder and start to answer the questions there. 
- You are encouraged to discuss the questions and answers in the group.


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

**Advanced: Implementation Details**

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

## Practice

### ofApp: Sound Buffer Example (A2)

Check out the first coding example in the code folder. Build and run the example. Review the ofApp code and understand what is happing there. Start to adjust the parameters in the audioOut method and change the sound that is being played back and connect the fundamental frequency with mouse interaction to change pitch. 

- Check out the second assignment sheet for further instructions. 


### Software Design Diagram (A3)  

Now that you have become a little familiar with the ofApp class and started to adapt the example, check out the underlying implementation in the SDK and review the audio classes **ofSoundBuffer**, **ofSoundStream** and **ofBaseSoundTypes**. How are these classes connected? Try to derive a software design diagram as best as you can. 

- Check out the third assignment sheet for further instructions. 
- You are encouraged to discuss all questions that come up in the group.


## Sound Generation and Synthesis

(Digital) sound synthesis describes the process of generating sound with a computer. This is usually done by creating different types of sound waves, combining them and modifying them following certain techniques and approaches (i.e., modulation, filtering, ...). The device or application that implements all of the above mentioned steps is usually referred to as a **software synthesizer**. 

The central element of a synthesizer and at the same time the first step in the synthesis process is the **oscillator**. An oscillator is responsible for creating a digital representation of a sound wave. It is important to note that one oscillator is only capable of playing back one sound at a time. Most synthesizers thus provide numerous oscillators that are either being combined automatically or provide an interface to adjust, combine and process the individual oscillators to generate exotic and complex sounds.

To generate a single sound wave, one approach would be to use a mathematical representation of a wave and feed it into the process. However, although this is mathematically interesting, it can become computationally expensive and is hardly implemented. Instead pre-recorded sound waves are used and played back at different rates to simulate changes in pitch. These approaches are, for example, **table lookup synthesis** or **wavetable synthesis**. Here, we will however stick with pure mathematical representations in order to understand the setup of a sound wave as well as play around with computational expenses.

A special sort of oscillator is an **LFO**, a low frequency oscillator. The frequency of an LFO is usually below 20Hz and often ranges between 0.25-5Hz. LFOs are central elements of sound synthesis. Since they are below human hearing capabilities, there frequency can only be felt and is often used to modulate, i.e., change certain parameters of audible sound waves. For example, this is done to create beat or pattern-like sounds.

Once the final output of the synthesis process has been computed, it is stored in an audio or sound buffer. This buffer can then be transferred (through the sound stream) to the soundcard's DAC (digital to audio converter) where it is converted into electrical voltage changes ready to be played back by the speakers.

- What are the central elements of an oscillator?

## Basic Oscillator Wave Types

Basic oscillators usually represent the following four fundamental types of sound waves:

- Sine wave
- Pulse wave
- Triangle wave
- Sawtooth wave

Following Fourier theorem, the sine wave can be used to create all of the other basic wave forms by combining different types of sine waves. The formulas will be given below per wave type. However, from a computational point of view, each basic wave type might as well be calculated following a simple algorithmic description. 


### Sine wave

The sine wave is the most fundamental sound wave.

Image

```
Sine wave = weight * Amplitude * sin ( frequency )

with "weight" being in the range of -1.0 ... 1.0
```


**Natural sounds** can be approached by combining sine waves. Therefore, define a fundamental frequency and add sine waves defined by multiple integers of the fundamental frequency. The resulting sounds will be perceived as **harmonic**. In contrast, **inharmonic** sounds can be generated by combining sine waves where the overtone of the fundamental frequency are defined by non-integer multiples.

#### Harmonic sounds

```
weight * Amplitude * sin ( frequency )
+ weight * Amplitude * sin ( 2 * frequency )
+ weight * Amplitude * sin ( 3 * frequency )
+ weight * Amplitude * sin ( 4 * frequency )
...
```

- Inharmonic sounds

```
weight * Amplitude * sin ( frequency )
+ weight * Amplitude * sin ( 2.56 * frequency )
+ weight * Amplitude * sin ( 1.324 * frequency )
+ weight * Amplitude * sin ( 6.3342 * frequency )
...
```

### Pulse wave

The pulse wave is often referred to as square wave when the duration of the positive and negative cycle is the same.

Image 

```
weight * Amplitude * sin ( frequency )
+ weight * Amplitude * sin ( 3 * frequency )
+ weight * Amplitude * sin ( 5 * frequency )
+ weight * Amplitude * sin ( 7 * frequency )
...
```

### Triangle wave

The triangle wave is similar to the sine wave but lacks the smooth changes. Instead, the triangle wave can be considered a linear adaptation of the sine wave cycle.

Image 

```
1.0 * Amplitude * sin ( frequency )
+ 1/9 * Amplitude * sin ( (3 * frequency) - 1 )
+ 1/25 * Amplitude * sin ( 5 * frequency )
+ 1/49 * Amplitude * sin ( (7 * frequency) - 1 )
...
```

### Sawtooth wave

The sawtooth wave is similar to the triangle wave but is defined by an aprubt fallback to the trough once the peak of the wave has been reached.

Image

```
weight * Amplitude * sin ( frequency )
+ weight * Amplitude * sin ( 1/2 * frequency )
+ weight * Amplitude * sin ( 1/3 * frequency )
+ weight * Amplitude * sin ( 1/4 * frequency )
...
```

## Practice

### Create a Software Synthesizer Prototype (A4) 

Reconsider the ofApp example. How could you turn the application into a synthesizer prototype? Add one or two dedicated oscillator objects to the synth. Conceive a first system diagram. Review the diagram in class and start refactoring the code accordingly. 

- Check out the fourth assignment sheet in the assignments folder for further instructions.
- You are encouraged to discuss the questions and answers in the group.


## Controlling An Oscillator with Another

One aspect of sound synthesis is the generation of complex sounds by combining different waves with each other as we have seen above. Another interesting aspect of sound synthesis is the generation of complex sounds by emplyoing one oscillator as control element. That is, one oscillator is used such that it controls certain parameters of another oscillator. For example, the LFO is often used to control another sound wave as we have already seen in the initial ofApp example. Here, we will explore three further techniques:

### Sound Synthesis Sync

With sound synthesis sync a **master oscillator** controls another **slave oscillator** as illustrated in the following Image. Whenever the Master oscillator has executed one cycle it forces the Slave to restart:

Image

### Amplitude Modulation (AM)

Amplitude modulation is a central and classical technique of sound synthesis. Here, a **modulator wave** is used to change the amplitude value of another **carrier wave** as illustrated in the following Image:

Image

The oscillator employed to create the carrier wave usually creates sound at a fixed frequency rate that is much higher than the frequency of the modulator wave. Musically, AM synthesis simulates the **tremolo** effect, i.e., the emulation of a vibration by quickly changing the loudness of a sound.

### Frequency Modulation (FM)

Frequency modulation is another classical technique of sound synthesis. Here, instead of modulating or changing the amplitude of the carrier wave, the **modulator wave** is used to change the frequency of the **carrier wave**, as illustrated in the following Image:

Image

As with Amplitude Modulation, the carrier wave is usually defined at a fixed frequency. Musically, FM synthesis simulates the **vibrato** effect, i.e., the emulation of a vibration by quickly changing the pitch of a sound.

## Practice 

### Extend the Software Synthesizer Prototype (A5) 

Extend the software synthesizer by one (or more) of the above techniques. 

- Check out the fifth assignment sheet in the assignments folder for further instructions.
- You are encouraged to discuss the questions and answers in the group.


## Further Thoughts on Expanding the ofApp 

To deepen your understanding of audio programming either in regards to software design or in regards to the implementation of sound generators, interaction with sound and sound modulation, check out the following ofxAddons:

- ofxATK
- ofxPDSP


The addons ofxATK and ofxPDSP provide deep inside into audio programming and come with a bunch of nice examples. Unfortunately, ofxATK has not been maintained recently; ofxPDSP is continuously being developed however some of the examples do not compile. Nonetheless, I recommend to look into both addons to get more and more familiar with the underlying concepts and / or to exploit some of the provided functionalities. 

The software synthesizer "Crystal" is used in the book "Refining sound". It can be downloaded freely at
http://www.greenoak.com/crystal/dnld2.html