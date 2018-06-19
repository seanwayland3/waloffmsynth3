/*
  ==============================================================================

    SynthVoice.h
    Created: 29 Oct 2017 10:18:29am
    Author:  Joshua Hodge

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"
#include "SynthVoice.h"  


class SynthVoice : public SynthesiserVoice
{    
public:
    
    bool canPlaySound (SynthesiserSound* sound)
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //=======================================================
    
    // PARAM's are for the GUI commented out
    
   /* void getParam (float* attack, float* decay, float* sustain, float* release)
    {
        env1.setAttack(double(*attack));
        env1.setDecay(double(*decay));
        env1.setSustain(double(*sustain));
        env1.setRelease(double(*release));
    }
   */
    
    //=======================================================
    
   // void getWaveType (int* oscId)
   // {
    //    theWave = *oscId;
   // }
    
    
    
    //=======================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
        
    }
    
    //=======================================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        
        allowTailOff = true;
        
        if (velocity == 0)
            clearCurrentNote();
    }
    
    //=======================================================
    
    void renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples)
    {
        
        env1.setAttack(10);
        env1.setDecay(500);
        env1.setSustain(0.8);
        env1.setRelease(25);
        for (int sample = 0; sample < numSamples; ++sample)
        {
            if (theWave == 1)
            {
                oscWaveType = osc1.sinewave(frequency);
            }
            
            if (theWave == 2)
            {
                oscWaveType = osc1.saw(frequency);
            }
            
            if (theWave == 3)
            
            {
                oscWaveType = osc1.pulse(frequency, 85);
            }
            
            double theSound = env1.adsr(oscWaveType, env1.trigger) * level;
            double filteredSound = filter.lores(theSound, 800, 0.8);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, filteredSound);
            }
            ++startSample;
        }
    }
    
    void pitchWheelMoved (int newPitchWheelValue)
    {
    
    }
    
    //=======================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    //=======================================================
    
    
    
private:
    double level;
    double frequency;
    double oscWaveType;
    
    int theWave = 2;
    
   
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter;
    
    
    
};
