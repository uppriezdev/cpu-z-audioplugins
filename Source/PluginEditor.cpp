#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <windows.h>
#include <pdh.h>
#include <vector>

//==============================================================================

CPUZAudioProcessorEditor::CPUZAudioProcessorEditor(CPUZAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(732, 358);

    // You can set up a Timer to update the CPU information periodically
   
}

CPUZAudioProcessorEditor::~CPUZAudioProcessorEditor()
{
  
}

//==============================================================================

void CPUZAudioProcessorEditor::paint(juce::Graphics& g)
{

    juce::Image backgroundImage = juce::ImageCache::getFromMemory(BinaryData::uibase4_png, BinaryData::uibase4_pngSize);
    g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), 0, 0, backgroundImage.getWidth(), backgroundImage.getHeight());


    // Set Segoe UI font
    g.setFont(juce::Font("Segoe UI", 24.0f, juce::Font::plain));

    {
        int x = 13, y = 50, width = 600, height = 30;
        juce::String text(TRANS(("CPU Name: " + juce::SystemStats::getCpuModel())));
        juce::Colour fillColour = juce::Colours::black;
        g.setColour(fillColour);
        g.setFont(juce::Font("Segoe UI", 20.0f, juce::Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            juce::Justification::left, false);
    }

   

    {
        // Display RAM usage using Win32 API
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);

        // Assuming total physical memory is in gigabytes
        double totalMemoryGB = static_cast<double>(memInfo.ullTotalPhys) / (1024 * 1024 * 1024);
        double usedMemoryGB = totalMemoryGB * (static_cast<double>(memInfo.dwMemoryLoad) / 100.0);

        int x = 13, y = 80, width = 600, height = 30;
        juce::String text(TRANS(("RAM Used: " + juce::String(usedMemoryGB, 2) + " GB" + " of 128 GB")));
        juce::Colour fillColour = juce::Colours::black;
        g.setColour(fillColour);
        g.setFont(juce::Font("Segoe UI", 20.0f, juce::Font::plain).withTypefaceStyle("Bold"));
        g.drawText(text, x, y, width, height,
            juce::Justification::left, false);
    }
    {
        // Display GPU name using Win32 API
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);

        std::vector<juce::String> gpuNames;

        for (DWORD deviceIndex = 0; EnumDisplayDevices(nullptr, deviceIndex, &displayDevice, 0); ++deviceIndex)
        {
            if (displayDevice.StateFlags & DISPLAY_DEVICE_ACTIVE)
            {
                juce::String gpuName(displayDevice.DeviceString);
                gpuNames.push_back(gpuName);
            }
        }

        if (!gpuNames.empty())
        {
            int x = 13, y = 110, width = 600, height = 30;
            juce::String text(TRANS(("GPU Name: " + gpuNames[0])));
            juce::Colour fillColour = juce::Colours::black;
            g.setColour(fillColour);
            g.setFont(juce::Font("Segoe UI", 20.0f, juce::Font::plain).withTypefaceStyle("Bold"));
            g.drawText(text, x, y, width, height,
                juce::Justification::left, false);
        }
    }

    {
        int x = 537, y = 13, width = 117, height = 32;
        
    }


}

void CPUZAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor.
}

