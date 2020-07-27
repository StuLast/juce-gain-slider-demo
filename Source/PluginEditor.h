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
class Gaintutorial1AudioProcessorEditor  : public juce::AudioProcessorEditor, juce::Slider::Listener
{
public:
    Gaintutorial1AudioProcessorEditor (Gaintutorial1AudioProcessor&);
    ~Gaintutorial1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sliderValue;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Gaintutorial1AudioProcessor& audioProcessor;
    juce::Slider gainSlider;
    juce::Label gainLabel;

    void sliderValueChanged(juce::Slider* slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gaintutorial1AudioProcessorEditor)
};
