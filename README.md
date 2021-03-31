# MyFirstGainPlugin
My first JUCE audio plugin. 

![The Meanest Plugin](https://raw.githubusercontent.com/GChau/MyFirstGainPlugin/main/res/reaper_azDnEEYsyt.png)

This is a silly plugin that is a gain rotary slider that goes from 0 to 11. Why go to 10... when you can go to 11?!

This actually converts a decibel input (from 0 to 11) to gain which is then multiplied by the input sample. In order to learn how to use JUCE, I'm just playing around with this.

I used Reaper to pick up my VST3 plugin.

# Build Environment
* Visual Studio 2019
* Reaper

# Build Steps
1. Download JUCE (see below for link).
2. Run Projucer.
3. Set path to JUCE modules.
4. Set target plugin format.
5. Create project.
6. Compile in Release mode.
7. Use an IDE to scan your build directory.
8. Have fun.

Source: 
* Tutorial - https://youtu.be/Bw_OkHNpj1M
* Download - https://juce.com/get-juce/download