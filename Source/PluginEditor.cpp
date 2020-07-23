/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Gaintutorial1AudioProcessorEditor::Gaintutorial1AudioProcessorEditor (Gaintutorial1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(0.0, 1.0);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
}

Gaintutorial1AudioProcessorEditor::~Gaintutorial1AudioProcessorEditor()
{
}

//==============================================================================
void Gaintutorial1AudioProcessorEditor::paint (juce::Graphics& g)
{

}

void Gaintutorial1AudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void Gaintutorial1AudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &gainSlider) {
        audioProcessor.setRawVolume(gainSlider.getValue());
    }
}
