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
- [Day 3: Driving Sound with Images](#day-3-driving-sound-with-images)
  - [Inspirations & Backgrounds](#inspirations--backgrounds)
  - [OpenCV](#opencv)
  - [openFrameworks and OpenCV](#openframeworks-and-opencv)
  - [Sonification and Music](#sonification-and-music)
  - [Further Thoughts on Expanding the ofApp](#further-thoughts-on-expanding-the-ofapp)


# Day 3: Driving Sound with Images

The third day of the workshop will be dedicated to finalizing the implementation of the syntheszier. Moreover, we will aim for connecting visuals to the sound engine. We will start with a classical "bouncing balls" example and explore image data as an input source for driving the sound generators. 


## Inspirations & Backgrounds

- [Auditory display for the blind](https://www.seeingwithsound.com)
  - [Image to sound mapping](https://www.seeingwithsound.com/im2sound.htm)
  - [Technical concept](https://www.seeingwithsound.com/paper0.gif) 
- [Artistic motion to sound and body movement](http://www.davidrokeby.com/body.html)
  - [Challenges in the Intermodal Challenges of the Art](http://www.davidrokeby.com/Culturall2/0_introduction.html)
- [Pixelsynth](https://ojack.github.io/PIXELSYNTH/)

## OpenCV

[OpenCV](http://opencv.org/) is an open source library that provides an enormous corpus of computer vision algorithms. The library has a modular structure; main components comprise algorithms for

- Core features including basic calculations and matrix operations, setting up of data structures etc.
- Image processing including image filtering and transformation methods
- Video analysis including motion estimation and object detection
- Object detection including specfic pre-defined objects to be detected 
- Video I/O
- GUI features
- and many more 

Since OpenCV works with image and video data primarily, large amounts of data can be aggregated and processed. OpenCV supports automatic memory allocation so if you start working with Matrix and Image data the underlying classes will allocate and release the memory required automatically.

Templates are used only to a very limited extent in OpenCV as they require certain computational overhead. Instead, OpenCV provides a fixed set of data structures and types that can be worked with. 

When working with objects and in particular motion detection between objects, different algorithms exist, primarily

- Farneback 
- Lucas-Kanade

Farneback is a two frame motion estimation that uses a polynomial expansion, approximating the neighborhood of each pixel with a polynomial to detect displacement of pixels. Farneback belongs to global/dense methods that process all of the images' pixels.

Lucas-Kanade is also a two frame motion estimation method that uses, however, minimization and calculates differences in displacement only for few selected points of the image. LK hence belongs to the local/sparse methods that are not as accurate but computationally more efficient.

Both methods require an understanding of the [image gradients](https://docs.opencv.org/master/d5/d0f/tutorial_py_gradients.html).


## openFrameworks and OpenCV

openFrameworks provides access to OpenCV functionality per default with the addons [ofxOpenCV](https://openframeworks.cc/documentation/ofxOpenCv/) that is part of the general SDK. Additionally, another addon called [ofxCv](https://github.com/kylemcdonald/ofxCv) has been developed that provides multiple different example projects and aims for a straightforward and lightweight implementation of OpenCV features. Also, ofxCv wraps is actively maintained and wraps the latest features of OpenCV.

## Sonification and Music

- How to harmonize sonified data?
- Mapping from specific image data to musical scales as a first step!


## Further Thoughts on Expanding the ofApp

- Check out non-photorealistic rendering
- Check out further openCV related concepts and approaches
  - [OpenCV core functionality](https://docs.opencv.org/3.4/de/d7a/tutorial_table_of_content_core.html)
  - [OpenCV Image Processing](https://docs.opencv.org/3.4/d7/da8/tutorial_table_of_content_imgproc.html)