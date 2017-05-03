/**
 * @file ArduboyPlaytune.cpp
 * \brief An Arduino library that plays a one or two part musical score and
 * generates tones. Intended for the Arduboy game system.
 */

/*****************************************************************************
* ArduboyPlaytune
*
* Plays a one or two part musical score and generates tones.
*
* Derived from:
* Playtune: An Arduino tune player library
* https://github.com/LenShustek/arduino-playtune
*
* Modified to work well with the Arduboy game system
* https://www.arduboy.com/
*
* SM: Modified to work on Arduino Uno by expanding Timer 2 to 8-bit,
*   to be usable with the Fablab Bayreuth Arduino Gamer hardware.
*
*
* The MIT License (MIT)
*
* (C) Copyright 2016, Chris J. Martinez, Kevin Bates, Josh Goebel, Scott Allen
* Based on work (C) Copyright 2011, 2015, Len Shustek
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* This was inspired by and adapted from "A Tone Generator Library",
* written by Brett Hagman, http://www.roguerobotics.com/
*
*****************************************************************************/

#include "ArduboyPlaytune.h"
#include <avr/power.h>


// SM: On the Uno, we use the 8-bit timer 2 to emulate a 16-bit timer period
#if (__AVR_ATmega328P__)
    static volatile struct {
      uint8_t high;     // period upper 8 bit
      uint8_t adj_low;  // adjustment for 8 bit timer value (= 256 - period_low + TMR2_WRITE_ADJ)
      uint8_t cnt_high = 0;  // Counter (down) for the upper 8 bits
    } tmr2_ext;

    #define TMR2_WRITE_ADJ  6   // Cycles delay when adding to timer 2 register
#endif


static const byte tune_pin_to_timer[] = { 3, 1 };
static volatile byte *_tunes_timer1_pin_port;
static volatile byte _tunes_timer1_pin_mask;
static volatile int32_t timer1_toggle_count;
static volatile byte *_tunes_timer3_pin_port;
static volatile byte _tunes_timer3_pin_mask;
static byte _tune_pins[AVAILABLE_TIMERS];
static byte _tune_num_chans = 0;
static volatile boolean tune_playing = false; // is the score still playing?
static volatile unsigned wait_timer_frequency2;       /* its current frequency */
static volatile boolean wait_timer_playing = false;   /* is it currently playing a note? */
static volatile unsigned long wait_toggle_count;      /* countdown score waits */
static volatile boolean all_muted = false; // indicates all sound is muted
static volatile boolean tone_playing = false;
static volatile boolean tone_mutes_score = false;
static volatile boolean tone_only = false; // indicates don't play score on tone channel
static volatile boolean mute_score = false; // indicates tone playing so mute other channels

// pointer to a function that indicates if sound is enabled
static boolean (*outputEnabled)();

// pointers to your musical score and your position in said score
static volatile const byte *score_start = 0;
static volatile const byte *score_cursor = 0;

// Table of midi note frequencies * 2
//   They are times 2 for greater accuracy, yet still fits in a word.
//   Generated from Excel by =ROUND(2*440/32*(2^((x-9)/12)),0) for 0<x<128
// The lowest notes might not work, depending on the Arduino clock frequency
// Ref: http://www.phy.mtu.edu/~suits/notefreqs.html
const uint8_t _midi_byte_note_frequencies[48] PROGMEM = {
16,17,18,19,21,22,23,24,26,28,29,31,33,35,37,39,41,44,46,49,52,55,58,62,65,
69,73,78,82,87,92,98,104,110,117,123,131,139,147,156,165,175,185,196,208,220,
233,247
};
const unsigned int _midi_word_note_frequencies[80] PROGMEM = {
262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,
698,740,784,831,880,932,988,1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,
1865,1976,2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951,4186,
4435,4699,4978,5274,5588,5920,6272,6645,7040,7459,7902,8372,8870,9397,9956,
10548,11175,11840,12544,13290,14080,14917,15804,16744,17740,18795,19912,21096,
22351,23680,25088
};

ArduboyPlaytune::ArduboyPlaytune(boolean (*outEn)())
{
  outputEnabled = outEn;
}

void ArduboyPlaytune::initChannel(byte pin)
{
  byte timer_num;
  byte pin_port;
  byte pin_mask;
  volatile byte *out_reg;

  // we are all out of timers
  if (_tune_num_chans == AVAILABLE_TIMERS)
    return;

  timer_num = tune_pin_to_timer[_tune_num_chans];
  _tune_pins[_tune_num_chans] = pin;
  if ((_tune_num_chans == 1) && (_tune_pins[0] == pin)) { // if channels 0 and 1 use the same pin
    tone_only = true; // don't play the score on channel 1
  }
  _tune_num_chans++;

  pin_port = digitalPinToPort(pin);
  pin_mask = digitalPinToBitMask(pin);
  out_reg = portOutputRegister(pin_port);

  *portModeRegister(pin_port) |= pin_mask; // set pin to output mode

  switch (timer_num) {
    case 1: // 16 bit timer
      power_timer1_enable();
      TCCR1A = 0;
      TCCR1B = 0;
      bitWrite(TCCR1B, WGM12, 1);
      bitWrite(TCCR1B, CS10, 1);
      _tunes_timer1_pin_port = out_reg;
      _tunes_timer1_pin_mask = pin_mask;
      break;
      
    case 3: 
        // SM: Use Timer 3 on 32u4, Timer 2 Uno  
        #if (__AVR_ATmega32U4__)  // Use timer 3, 16-bit
            power_timer3_enable();
            TCCR3A = 0;
            TCCR3B = 0;
            bitWrite(TCCR3B, WGM32, 1);
            bitWrite(TCCR3B, CS30, 1);
            
        #elif (__AVR_ATmega328P__)  // Use timer 2, 8-bit, with emulated 16-bit period
            power_timer2_enable();
            // Disable timer-interrupts:
            uint8_t sreg_bak = SREG;  // Backup global interrupt flag
            cli();                    // Disable global interrupt flag
            TIMSK2 = 0;               // All timer 2 interrupt off
            SREG = sreg_bak;          // Restore global interrupt flag 
            // Configure timer 2: normal operation, prescaler 1/1
            TCCR2A = 0b00000000;
            TCCR2B = 0b00000001;
            OCR2A = 0xFF;      // Output compare at 0xFF, same as overflow
        #endif
        
      _tunes_timer3_pin_port = out_reg;
      _tunes_timer3_pin_mask = pin_mask;
      playNote(0, 60);  /* start and stop channel 0 (timer 3) on middle C so wait/delay works */
      stopNote(0);
      break;
  }
}

void ArduboyPlaytune::playNote(byte chan, byte note)
{
  byte timer_num;
  byte prescalar_bits;
  unsigned int frequency2; /* frequency times 2 */
  unsigned long ocr;

  // we can't play on a channel that does not exist
  if (chan >= _tune_num_chans) {
    return;
  }

  // if channel 1 is for tones only
  if ((chan == 1) && tone_only) {
    return;
  }

  // we only have frequencies for 128 notes
  if (note > 127) {
    return;
  }

  timer_num = tune_pin_to_timer[chan];
  if (note < 48) {
    frequency2 = pgm_read_byte(_midi_byte_note_frequencies + note);
  } else {
    frequency2 = pgm_read_word(_midi_word_note_frequencies + note - 48);
  }

  //******  16-bit timer  *********
  // two choices for the 16 bit timers: ck/1 or ck/64
  ocr = F_CPU / frequency2 - 1;
  prescalar_bits = 0b001;
  if (ocr > 0xffff) {
    ocr = F_CPU / frequency2 / 64 - 1;
    prescalar_bits = 0b011;
  }
  // Set the OCR for the given timer, then turn on the interrupts
  switch (timer_num) {
    case 1:
      if (!tone_playing) {
        TCCR1B = (TCCR1B & 0b11111000) | prescalar_bits;
        OCR1A = ocr;
        bitWrite(TIMSK1, OCIE1A, 1);
      }
      break;
      
    case 3:
        // SM: Use Timer 3 on 32u4, Timer 2 Uno  
        #if __AVR_ATmega32U4__
            TCCR3B = (TCCR3B & 0b11111000) | prescalar_bits;
            OCR3A = ocr;
            wait_timer_frequency2 = frequency2;  // for "tune_delay" function
            wait_timer_playing = true;
            bitWrite(TIMSK3, OCIE3A, 1);
            
        #elif (__AVR_ATmega328P__)
            if (prescalar_bits == 0b011)  prescalar_bits = 0b100;   // timer 2, CS2=0b100: 1/64
            TCCR2B = (TCCR2B & 0b11111000) | prescalar_bits;
            
            // Set new period
            // Disable interrupts during period change (accesses by timer isrs)
            uint8_t sreg_bak = SREG;  // Backup global interrupt flag
            cli();                    // Disable global inerrupt flag
            ocr -= TMR2_WRITE_ADJ;
            tmr2_ext.adj_low = -(uint8_t)(ocr);
            tmr2_ext.high = ocr >> 8;
            SREG = sreg_bak;      // Restore global interrupt flag
            
            // as above
            wait_timer_frequency2 = frequency2;  // for "tune_delay" function
            wait_timer_playing = true;
            
            if (TIMSK2 == 0)  { // Not running
                // Load period for first cycle
                tmr2_ext.cnt_high = tmr2_ext.high;   
                TCNT2 = tmr2_ext.adj_low;            
                TIFR2 = 0b11;    // clear interrupt flags
                TIMSK2 = 0b01;   // start with OVR interrupt
            }
            // Else leave timer running. Period will be updated on next execution of COMPA ISR.
        #endif
        break;
      
  }
}

void ArduboyPlaytune::stopNote(byte chan)
{
  byte timer_num;
  timer_num = tune_pin_to_timer[chan];
  switch (timer_num) {
    case 1:
      if (!tone_playing) {
        TIMSK1 &= ~(1 << OCIE1A);                 // disable the interrupt
        *_tunes_timer1_pin_port &= ~(_tunes_timer1_pin_mask);   // keep pin low after stop
      }
      break;
    case 3:
      // SM: Nothing special to do here for timer 2.  Interrupt is kept on.
      wait_timer_playing = false;
      if (!mute_score) {
        *_tunes_timer3_pin_port &= ~(_tunes_timer3_pin_mask);   // keep pin low after stop
      }
      break;
  }
}

void ArduboyPlaytune::playScore(const byte *score)
{
  score_start = score;
  score_cursor = score_start;
  step();  /* execute initial commands */
  tune_playing = true;  /* release the interrupt routine */
}

void ArduboyPlaytune::stopScore()
{
  for (uint8_t i = 0; i < _tune_num_chans; i++)
    stopNote(i);
  tune_playing = false;
}

boolean ArduboyPlaytune::playing()
{
  return tune_playing;
}

/* Do score commands until a "wait" is found, or the score is stopped.
This is called initially from playScore(), but then is called
from the interrupt routine when waits expire.

If CMD < 0x80, then the other 7 bits and the next byte are a
15-bit big-endian number of msec to wait
*/
void ArduboyPlaytune::step()
{
  byte command, opcode, chan;
  unsigned duration;

  while (1) {
    command = pgm_read_byte(score_cursor++);
    opcode = command & 0xf0;
    chan = command & 0x0f;
    if (opcode == TUNE_OP_STOPNOTE) { /* stop note */
      stopNote(chan);
    }
    else if (opcode == TUNE_OP_PLAYNOTE) { /* play note */
      all_muted = !outputEnabled();
      playNote(chan, pgm_read_byte(score_cursor++));
    }
    else if (opcode < 0x80) { /* wait count in msec. */
      duration = ((unsigned)command << 8) | (pgm_read_byte(score_cursor++));
      wait_toggle_count = ((unsigned long) wait_timer_frequency2 * duration + 500) / 1000;
      if (wait_toggle_count == 0) wait_toggle_count = 1;
      break;
    }
    else if (opcode == TUNE_OP_RESTART) { /* restart score */
      score_cursor = score_start;
    }
    else if (opcode == TUNE_OP_STOP) { /* stop score */
      tune_playing = false;
      break;
    }
  }
}

void ArduboyPlaytune::closeChannels()
{
  byte timer_num;
  for (uint8_t chan=0; chan < _tune_num_chans; chan++) {
    timer_num = tune_pin_to_timer[chan];
    switch (timer_num) {
      case 1:
        TIMSK1 &= ~(1 << OCIE1A);
        *_tunes_timer1_pin_port &= ~(_tunes_timer1_pin_mask); // set pin low
        break;
      
      case 3:
          // SM: Use Timer 3 on 32u4, Timer 2 Uno  
          #if __AVR_ATmega32U4__
              TIMSK3 &= ~(1 << OCIE3A);
          #elif (__AVR_ATmega328P__)
              TIMSK2 = 0;  // all timer 2 interrupts off
          #endif
          *_tunes_timer3_pin_port &= ~(_tunes_timer3_pin_mask); // set pin low
          break;
    }
  }
  _tune_num_chans = 0;
  tune_playing = tone_playing = tone_only = mute_score = false;
}

void ArduboyPlaytune::tone(unsigned int frequency, unsigned long duration)
{
  // don't output the tone if sound is muted or
  // the tone channel isn't initialised
  if (!outputEnabled() || _tune_num_chans < 2) {
    return;
  }

  tone_playing = true;
  mute_score = tone_mutes_score;

  uint8_t prescalarbits = 0b001;
  int32_t toggle_count = 0;
  uint32_t ocr = 0;

  // two choices for the 16 bit timers: ck/1 or ck/64
  ocr = F_CPU / frequency / 2 - 1;
  prescalarbits = 0b001;
  if (ocr > 0xffff) {
    ocr = F_CPU / frequency / 2 / 64 - 1;
    prescalarbits = 0b011;
  }
  TCCR1B = (TCCR1B & 0b11111000) | prescalarbits;

  // Calculate the toggle count
  if (duration > 0) {
    toggle_count = 2 * frequency * duration / 1000;
  }
  else {
    toggle_count = -1;
  }
  // Set the OCR for the given timer,
  // set the toggle count,
  // then turn on the interrupts
  OCR1A = ocr;
  timer1_toggle_count = toggle_count;
  bitWrite(TIMSK1, OCIE1A, 1);
}

void ArduboyPlaytune::toneMutesScore(boolean mute)
{
  tone_mutes_score = mute;
}

// ===== Interrupt service routines =====

// TIMER 1
ISR(TIMER1_COMPA_vect)
{
  if (tone_playing) {
    if (timer1_toggle_count != 0) {
      // toggle the pin
      *_tunes_timer1_pin_port ^= _tunes_timer1_pin_mask;
      if (timer1_toggle_count > 0) timer1_toggle_count--;
    }
    else {
      tone_playing = mute_score = false;
      TIMSK1 &= ~(1 << OCIE1A);                 // disable the interrupt
      *_tunes_timer1_pin_port &= ~(_tunes_timer1_pin_mask);   // keep pin low after stop
    }
  }
  else {
    if (!all_muted) {
      *_tunes_timer1_pin_port ^= _tunes_timer1_pin_mask;  // toggle the pin
    }
  }
}


// SM: Use Timer 3 on 32u4, Timer 2 on Uno  
#if __AVR_ATmega32U4__

    // TIMER 3
    ISR(TIMER3_COMPA_vect)
    {
      // Timer 3 is the one assigned first, so we keep it running always
      // and use it to time score waits, whether or not it is playing a note.

      // toggle the pin if we're sounding a note
      if (wait_timer_playing && !mute_score && !all_muted) {
        *_tunes_timer3_pin_port ^= _tunes_timer3_pin_mask;
      }

      if (tune_playing && wait_toggle_count && --wait_toggle_count == 0) {
        // end of a score wait, so execute more score commands
        ArduboyPlaytune::step();  // execute commands
      }
    }

    
#elif (__AVR_ATmega328P__)

    //============================================================================================================
    // SM: On the Uno, Timer 2 is only 8-bit wide. To expand the tiemr period, we emulate a 16-bit timer
    // by manually counting the upper 8 bit in the overflow ISR. Before the last period, we switch over
    // from the OVR ISR to the COMPA isr, which reloads the timer register, and executes the audio function.
    //============================================================================================================

    // Timer 2 overflow interrupt

    #if 0     // C implementation: 23/28 cycles + jumps
    ISR(TIMER2_OVF_vect)
    {  
        if (--tmr2_ext.cnt_high == 0)  {  // If cnt_high was 1 before decrementation, this is the last 8-bit cycle
          TIFR2 |= 0b10;        // clear timer 2 COMPA interrupt flag
          TIMSK2 = 0b10;        // disable timer 2 OVR interrupt, enable COMPA interrupt          
        }
    }
       
    #else    // Assembly implementation: 15/18 cycles + jumps
    ISR(TIMER2_OVF_vect, ISR_NAKED)
    {  
        asm volatile(            
            // preamble: Save modified registers to stack
            "push  r16           \n"
            "in    r16, 0x3f     \n"   // SREG
            "push  r16           \n"

            "lds  r16, %0      \n"   // r = tmr2_ext.cnt_high
            "dec  r16          \n"   // r --
            "sts  %0, r16      \n"   // tmr2_ext.cnt_high = r
            "brne  1f          \n"   // if (result != 0)  goto skip
              "sbi 0x17, 1     \n"   //   Set bit TIFR2, 1 --> clear COMPA interrupt flag
              "ldi r16, 0b10   \n"   //   TIMSK2 = 0b10
              "sts 0x70, r16   \n"   //   --> Enable COMPA interrupt, disable OVF interrupt
            "1:                \n"

            // postamble: Restore modified registers from stack
            "pop  r16           \n"
            "out  0x3f, r16     \n"   // SREG
            "pop  r16           \n"

            "reti               \n"

            // Operands
            :                          // no output operands
            : "i" (&tmr2_ext.cnt_high) // input operands. Note: we load cnt_high manually, so we need its address as operand
            : "r16" );                         // clobbered registers  
    }

    #endif

    //============================================================================================================

    // Timer 2 compare match A interrupt
    
    ISR(TIMER2_COMPA_vect)
    {
      // Timer 2 overflow and compare match happend at the same time.
      // The compare match interrupt has higher priority, so the overflow flag is still pending.
      // We assume, that timer 2 did not overflow once more up to now, and would not overflow until the end of this isr.

      // Start a new 16-bit timer cycle
      tmr2_ext.cnt_high = tmr2_ext.high;
      
      // Adjust the timer value for the first 8-bit period:
      // (asm implementation onyl spares 2 instruction, doesn't pay off here)
      register uint8_t t = TCNT2;
      register uint8_t t_new = t + tmr2_ext.adj_low;
      TCNT2 = t_new;
      if (t_new >= t)          // if adjusted 8-bit timer cycle did not overflow:
        asm("sbi 0x17, 0");    //   TIFR |= 1;  // clear the pending interrupt flag
                               //   else leave it on, so the overflow interrupt is served immediately after we return from here
      
      // Switch to overfow interrupt
      TIMSK2 = 0b01;   // Disable COMPA interrupt, enable OVF interrupt

      // Original ISR code follwing...
      
      // Timer 3 is the one assigned first, so we keep it running always
      // and use it to time score waits, whether or not it is playing a note.

      // toggle the pin if we're sounding a note
      if (wait_timer_playing && !mute_score && !all_muted) {
        *_tunes_timer3_pin_port ^= _tunes_timer3_pin_mask;
      }

      if (tune_playing && wait_toggle_count && --wait_toggle_count == 0) {
        // end of a score wait, so execute more score commands
        ArduboyPlaytune::step();  // execute commands
      }
    }

    //============================================================================================================

#endif