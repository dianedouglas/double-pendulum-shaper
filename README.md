# _Double Pendulum Waveshaper_

#### _An audio distortion plugin controlled by the motion of a double pendulum_

#### By Diane Douglas

## Description

#### [Double Pendulum Visualizer](https://dianedouglas.github.io/double-pendulum)
#### [JavaScript](https://github.com/dianedouglas/double-pendulum)

This plugin allows the musician to control the speed and length of a double pendulum. It displays two circles, and the width of each circle is the distance from the tip of the pendulum to each circle. This distance, and the size of each circle defines how much of each harmonic you hear in the audio distortion.

There are also wet / dry controls, and the user can control the amount of distance between the two circles. All controls can be mapped to MIDI.

## Run the Plugin

Download the plugin [here](http://melodiccode.com/system/files_force/Pendulum%20Shaper.zip?download=1). 
Read more about it [here](http://melodiccode.com/projects/24). 
You will receive a zip folder with this readme as well as a folder labelled 'Mac'.

Inside of the Mac folder you will see the three plugin formats available: VST, AU and AAX.

Ableton Live VST Plugin Installation (Mac):

* Inside of the downloaded folder in 'Pendulum Shaper/Mac/VST', select the file PendulumShaper_VST.vst3. 
* Move it into your Ableton Live custom VST plugins folder. 
* Open Ableton Live preferences and click the "File / Folder" tab.
* Make sure "Use VST Plug-In Custom Folder" is on. 
* To change the location of your custom VST plugins folder, choose "Browse" here. 
* Click the 'Rescan' button and you should be able to find the Pendulum Shaper VST under Plugins / Custom in Ableton. 

Now you should be able to drag the VST plugin onto an audio track, enable the input, and map parameters to midi as normal.

## Setup the Code

The [code here on github](https://github.com/dianedouglas/double-pendulum-shaper) can be run within the RackAFX IDE with Visual Studio on a Windows environment. I use: 

* Mac Book Pro, Sierra, 10.12.3
* Virtual Box (VirtualBox-5.2.7-120866-OSX)
* Windows 10 installed on it (Windows10_InsiderPreview_Enterprise_x64_en-us_17025.iso).
* RackAFX 6.9.1.0 with Visual Studio Community 2015 (RackAFX installation instructions at www.willpirkle.com)

## Known Bugs

I have only tested the VST version so far, with Ableton Live 10 on Mac. I can't imagine that there aren't any other issues between other formats and on Windows, but in theory this is cross platform. Future versions...

## Support and contact details

Please feel free to fork this repository and submit pull requests back. You can also contact me here:

* Email: diane@melodiccode.com
* My Website: [www.MelodicCode.com](http://www.melodiccode.com)

## Technologies Used

* C++, including Steinberg VST SDK
* RackAFX with Visual Studio (Audio Plugin IDE)
* P5.js, Processing (Visual interface prototype)

Copyright (c) 2018 **Diane Douglas**