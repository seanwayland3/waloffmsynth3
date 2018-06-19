# wayloffmsynth3-

created with 
https://github.com/theaudioprogrammer/juceSynthFramework
SynthSound.h
SynthVoice.h

4 juce classes and headers created in juceSynthFramWork

PluginEditor.cpp
PluginProcessor.cpp
USES JUCE.COM 

https://github.com/micknoise/Maximilian


A basic  build of the synth created in this youtube video 

https://www.youtube.com/watch?v=kxKEFTQRZPI

These classes have most of the GUI code commented out .. 
It is meant as a base to start testing synthesizers .. 

synth has one oscillator an ADSR and a filter 

Create a new JUCE audio plugin and check "is a synth, accepts midi in , accepts midi out " 

Delete the created editor and processor classes created by JUCE in the PROJUCER 
Copy these files into the folder created by JUCE
"Add existing files" in the Projucer and select the files you just copied into the JUCE folder. 
Build and load the VST in your favorite plugin .
