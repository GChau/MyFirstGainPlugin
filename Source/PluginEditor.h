/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyFirstGainPluginAudioProcessorEditor
  : public juce::AudioProcessorEditor,
    public juce::Slider::Listener
{
public:
    MyFirstGainPluginAudioProcessorEditor (MyFirstGainPluginAudioProcessor&);
    ~MyFirstGainPluginAudioProcessorEditor() override;

    //==============================================================================
    void sliderValueChanged(juce::Slider*) override;
    //void sliderDragStarted(juce::Slider*) override;
    //void sliderDragEnded(juce::Slider*) override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyFirstGainPluginAudioProcessor& audioProcessor;

    juce::Slider slider_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyFirstGainPluginAudioProcessorEditor)
};
