# Audio Plugin Design With Faust and JUCE

5:00 - 7:00pm (GMT+2): Audio Plugin Design With Faust and JUCE
Hangout Link: https://meet.google.com/wux-mkqu-sds
Join by Phone: ‪+33 1 87 40 04 51‬ PIN: ‪684 892 915‬#

For this workshop, we will get our hands dirty and use the Faust compiler to generate C++ DSP objects to integrate them in a JUCE audio plug-in. We expect participants of this workshop to have a basic understanding of C++ and to be able to use a terminal. In preparation for the workshop, we need you to install the following elements on your system:

- JUCE: <https://juce.com/>
- (Optional) The Faust compiler: https://github.com/grame-cncm/faust/tree/master-dev
- (Optional) Any relevant SDK depending in the kind of plug-in you want to generate with JUCE during the workshop (e.g., VST, etc.)

## Appunti

[Workshop stuff](https://faustdoc.grame.fr/workshops/2020-04-10-faust-juce/)

- Simple monophonic synth made with Faust e Juce

- Simple polyphonic synth made with Faust e Juce

____________

sawtooth oscillator

sawtooth oscillator > to low pass filter

stero plugin `<:` split operator

if we want to make a plugin that doesn't click> interpolated values > we utilise the _si.smoo_ function

 we change the values of the parameters, we don't want the clicks  

 ```
import ("stdfaust.lib");

f = hslider("freq", 200, 50, 100, 0.01): si.smoo;
g = hslider("gain", 0.1,0,1,0.01): si.smoo;
t = button("gate"): si.smoo;
ct = hslider("cutoff",10000,50,10000,0.01): si.smoo;
process  =os.sawtooth(f)*t*g :fi.lowpass(3,ct)<:_,_;
```

use the export function of the IDE to download the dsp

build a user interface from scratch

use Faust to build parts of applications

export to C++ code from the web IDE > export function > source > architecture > C++

Projucer > audio plugin >name

plugin processor > dsp

plugin editor > gui

Standalone is easier to debug

VST3 > sdk for it

AU > using a mac > parts of toolchain if you have xcode installed

macos > xcode > steps to make the plugins are different
