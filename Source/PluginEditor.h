/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "FileContainerManagerUI.h"

//==============================================================================
/**
*/
class ChuckPluginTest4AudioProcessorEditor  : public AudioProcessorEditor, public ButtonListener, public Timer, Slider::Listener 
{
public:
    ChuckPluginTest4AudioProcessorEditor (ChuckPluginTest4AudioProcessor* ownerFilter);
    ~ChuckPluginTest4AudioProcessorEditor();

    //==============================================================================
    // This is just a standard Juce paint method...
    void paint (Graphics& g) override;
    void resized() override;
    
    ChuckPluginTest4AudioProcessor * getProcessor() const
    {
        return static_cast<ChuckPluginTest4AudioProcessor *>(getAudioProcessor());
        
    }
    
    //ScopedPointer<TextButton> addAllShredsButton;
    ScopedPointer<TextButton> browseCodeButton;
    //ScopedPointer<TextButton> removeShredButton;
    //ScopedPointer<TextButton> addFileContainerButton;
    
    ScopedPointer<FileContainerManagerUI> managerUI;
    
    void buttonClicked(Button* buttonThatWasPressed);
    String lastFileLoaded;
    
    void timerCallback();
    void sliderValueChanged (Slider* slider);
    
    
private:
    ScopedPointer<DrawableButton> addAllShredsButton;
    ScopedPointer<DrawableButton> removeAllShredsButton;
    ScopedPointer<DrawableButton> addNewFileContainerButton;
};


#endif  // PLUGINEDITOR_H_INCLUDED
