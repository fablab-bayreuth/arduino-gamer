arduino-gamer/Arduboy_lib
=========================

A fork of the Arduboy game libraries, modified to be compatible to the Fablab Bayreuth 
Arduino Gamer hardware. Since the Arduino Gamer uses an ATmega328 processor, which has
a little less RAM than the Arduboy (ATmega 32u4), some Games may not be portable.

To use Arduboy games with our hardware, install the modified Arduboy libraries 
(ending with <i>_FLB</i>) into your Arduino library folder. The modified libraries
can not be isntalled along the original ones, since they both contain header files
with identical names (the Arduino IDE will complain about this). 
The modified library try to detect automatically, which hardware is currently used:
When compiling for an Ardunino Uno (ATmega328), it uses the Gamer hardware, otherwise
it uses the original Arduboy hardware.

Libraries ported so far:
  * Arduboy
  * Arduboy2
  * ArduboyTones
  * ArduboyPlaytunes

Libraries to be ported in the future:
  * ArdVoice
  * ATMlib
  
Please contact us, if you find a Game that does not run as it should with the
modified libraries.


Arduboy hompage: https://arduboy.com/

Original Arduboy library: https://github.com/Arduboy/Arduboy

