/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <algorithm>

static const int WIDTH = 666;
static const int HEIGHT = 666;


//==============================================================================
MyFirstGainPluginAudioProcessorEditor::MyFirstGainPluginAudioProcessorEditor (
    MyFirstGainPluginAudioProcessor& p
) : AudioProcessorEditor (&p),
    audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (WIDTH, HEIGHT);
    setResizable(true, true);

    // Set up slider
    slider_.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    slider_.setRange(-11.0f, 11.0f, 1.0f);
    slider_.setValue(0.0f);
    slider_.setTextBoxStyle(
        juce::Slider::TextBoxBelow,
        true,
        69,
        69
    );
    slider_.addListener(this);

    // Add slider to plugin
    addAndMakeVisible(slider_);
}

MyFirstGainPluginAudioProcessorEditor::~MyFirstGainPluginAudioProcessorEditor()
{
}

//==============================================================================

void MyFirstGainPluginAudioProcessorEditor::sliderValueChanged(
    juce::Slider* slider
) {
    if (slider == &slider_) {
        audioProcessor.gain_ = slider_.getValue();
    }
}

//==============================================================================
void MyFirstGainPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Pseudo irn bru colours
    g.fillAll(juce::Colour(0xffffa600));
    g.setColour(juce::Colour(0xff001eff));

    // Make font stretch or compress if window gets resized
    const float x_ratio = ((float)getWidth() / WIDTH);
    const float y_ratio = ((float)getHeight() / HEIGHT);
    const float min_ratio = std::min(x_ratio, y_ratio);

    const auto font_size = 69.0f * min_ratio;
    g.setFont (font_size);
    g.drawFittedText("max 666 gainz!", getLocalBounds(), juce::Justification::centredTop, 1);
    g.drawFittedText("FREEDUM", getLocalBounds(), juce::Justification::centredBottom, 1);
}

void MyFirstGainPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    const int centre_x = getWidth() / 2.0;
    const int centre_y = getHeight() / 2.0;
    const int width = getWidth() / 4.0;
    const int height = getWidth() / 4.0;

    slider_.setBounds(
        centre_x - (width / 2),
        centre_y - (height / 2),
        width,
        height
    );
}
