# Faust 101

3:00 - 4:30pm (GMT+2): Faust 101
Hangout Link: https://meet.google.com/ecc-kgou-nrb
Join by Phone: +33 1 87 40 24 82‬ PIN: ‪739 954 242‬#

Most of this workshop will happen in the Faust Online IDE: https://faustide.grame.fr/. For the best experience, we recommend you to use Firefox Nightly. If you wish to have MIDI support, we recommend you to use Google Chrome. The handout of the workshop can be found here: https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/

# Introduction to FAUST

[esempi Workshop](https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/)

[Faust IDE](https://faust.grame.fr/ide/)

[FAUST editor](https://fausteditor.grame.fr)

Domain specific language for real-time digital signal processing

Faust textural language with visual representation

Building kind of audio circuit

split operation `<:`
mergiing operation `:>`
parallel compositio `,`
recursive composition operation `~`

Faust IDE is web assembly

Faust compiler can compile code written handwritten, trying to compete with C++ and Plugin

Simple Faust programme `process = _;`

Faust is a collection of definition > process = main in _C language_

`_` transport the signal without any transformation

[example 1](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust0/exfaust0.dsp)

use a different primitive from `_`

different function `+` audio file  multiplied by 2

different function `*` > upper half of the signal > positive half of the signal

`_ + *` are primitives in Faust

To build a Faust programme you need to combine (compose) primitives

`process = _, _;` stereo cable [example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust3/exfaust3.dsp)

`process = _,_,_,_;` quadriphonic cable

how to control the volume??

`process = (_, 0.9) : *; // try to replace 0.1 by other values between 0 and 1`
[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust4/exfaust4.dsp)

how to control the volume with a slider??

using an horizontal slider named _hslider_

slider: preset value, init val, end val, step

[example with slider](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust5/exfaust5.dsp)

How to organize the code?

additional operation

Mono amplifier
[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust6/exfaust6.dsp)

Stereo amplifier
`monoamp = _, hslider("volume", 0.1, 0, 1, 0.01) : *;
process = monoamp,monoamp;`

cleaner code of stereo amplifier

`monoamp = _, vslider("volume", 0.1, 0, 1, 0.01) : *;
stereoamp = monoamp,monoamp;
process= stereoamp;`

Objects GUI > groups, sub groups, buttons, sliders

Sliders can have styles > sliders have metadatas> metadatas are extracted from the faust compiler

`monoamp = _, vslider("volume[style:knob]", 0.1, 0, 1, 0.01) : *;
stereoamp = monoamp,monoamp;
process= stereoamp;`

Faust architecture are ways to architect to build > architecture to make different types of files (max,caqt, etc...)

`// monoamp = _, vslider("volume[style:knob]", 0.1, 0, 1, 0.01) : *;
// monoamp =_,0.1:*; //core syntax
//monoamp = _*0.1; //infix notation
monoamp = *(0.1); //prefix notation
process= monoamp;`

how to mute the signal

[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust10/exfaust10.dsp)

`mute = *(1-checkbox("mute"));
monoamp = *(vslider("volume[style:knob]", 0.1, 0, 1, 0.01)):mute;

stereoamp = monoamp,monoamp;

process = stereoamp;
`
basic layout

`mute = *(1-checkbox("mute"));
monoamp = *(vslider("volume[style:knob]", 0.1, 0, 1, 0.01)):mute;

stereoamp = hgroup("Marshall",monoamp,monoamp);

process = stereoamp;
`

We want to add a parameter to _monoamp_
 we want many monoamp parameters > so we use _par_
`mute = *(1-checkbox("mute"));

monoamp(c) = *(vslider("volume %c[style:knob]", 0.1, 0, 1, 0.01)) : mute;

stereoamp = hgroup("Marshall", monoamp(0),monoamp(1));

process = stereoamp;
`
so we want to use delay [example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust15/exfaust15.dsp)

with 44100 we have a 1 second delay

so if we want to create an echo
[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust17/exfaust17.dsp)

_~_ connect the output of the + to bounce, tilde compose faust operation creating a loop

`bounce =@(4410):*(0.75);
echo = + ~ bounce;

process = echo,echo;
`
if we want to use parameters in our echo??

`bounce(d,f) =@(d):*(f);
echo(d,f) = + ~ bounce(d,f);
stereoecho(d,f) = echo(d,f),echo(d,f);
process = stereoecho(4410, 0.75);
`
we want a smarter feedback so as soon [example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust22/exfaust22.dsp)

`bounce(d,f) = @(d) : *(f);

monoecho(d,f) = *(g) : +~bounce(d,f) with { g = 1 - max(0, f-l)/(1-l); l = 0.95;};

stereoecho(d,f) = monoecho(d,f),monoecho(d,f);

process = stereoecho(44100/4, hslider("feedback", 0, 0, 1, 0.01));
`
from now on we can navigate inside the diagram in the ide

## Basic Oscillators in Faust

- create an infinite ramp of value > loop using `+~_` > which can be defined as an operator

decimal part of the value subtracted to the integer part of the value

`decimalpart(x) = x-int(x);
phase = 0.125 : (+ : decimalpart) ~ _;
process = phase;`

### Sawtooth signal generator

using the sampling rate frequency we can
[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust25/exfaust25.dsp)

`import("stdfaust.lib");

decimalpart(x) = x-int(x);
phase(f) = f/ma.SR : (+ : decimalpart) ~ _;

sawtooth(f) = phase(f) * 2 - 1;

process = sawtooth(hslider("freq",440,20,8000,1))*hslider("volume",0.1,0,1,0.01);
`

So how to do a square wave?


`import("stdfaust.lib");

decimalpart(x) = x-int(x);
phase(f) = f/ma.SR : (+ : decimalpart) ~ _;

squarewave(f) = (phase(f) > 0.5) * 2 - 1;

process = squarewave(440);
`
comparision of 2 signals > boolean signal > so we create a square signal but with aliasing problems

### Additive Synthesis

aliasing fenomenon is easly visibile at high frequency > passing half sample rate > so how to avoid aliasing??

band limited osccilator is the answer

[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust32/exfaust32.dsp)

an additive synhtesis oscillator with n number of partials

`import("stdfaust.lib");

// Approximation of a sawtooth wave using additive synthesis

sawtooth(f) = 2/ma.PI*sum(k, n, (-1)^k * os.osc((k+1)*f)/(k+1));

process = sawtooth(55);
`
we can approximate with precise numbers of partials, but we can also use band limited oscillators

[band limited oscillators example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust35/exfaust35.dsp)

#### Karplus strong generator

[example](https://faustide.grame.fr/?code=https://faustdoc.grame.fr/workshops/2020-04-10-faust-101/exfaust45/exfaust45.dsp)

## FM Synthesis


`import("stdfaust.lib");

// FM: Frequency modulation

FM(fc,fm,amp) = fm : os.osc : *(amp) : +(1) : *(fc) : os.osc;

process = FM(
            hslider("freq carrier", 880, 40, 8000, 1),
            hslider("freq modulation", 200, 10, 1000, 1),
            hslider("amp modulation", 0, 0, 1, 0.01)
            )
        <: _,_;
`
[more information for libraries](https://faustlibraries.grame.fr/)
