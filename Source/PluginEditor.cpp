/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    newButton.addListener(this);
    addAndMakeVisible(newButton);
    setSize (700, 500);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    newButton.setBounds(getLocalBounds().reduced(100));
}

void NewProjectAudioProcessorEditor::buttonClicked(juce::Button*)
{
    DBG("Clicked");
    increaseClickCount();
    if(int x = getClickCount(); x%3 == 1 )
    {
        setSize(1003, 763);
    }
    else if (x%3 == 2)
    {
        setSize(1255, 948);
    }
    else
    {
        setSize (700, 500);
    }
        
}

void NewProjectAudioProcessorEditor::increaseClickCount()
{
    clickCount++;
}

int NewProjectAudioProcessorEditor::getClickCount()
{
    return clickCount;
}
