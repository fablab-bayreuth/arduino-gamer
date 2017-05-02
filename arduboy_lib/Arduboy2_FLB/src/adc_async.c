
//============================================================================================================
// Asynchronous ADC acquisition (ADC interrupt driven)
// Switches through ADC channels 0 to ADC_ASYNC_N_CHAN-1 and stores
// the results in the background.
//============================================================================================================

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc_async.h"

//============================================================================================================

#define ADC_ASYNC_N_CHAN  4  // Channels to sample, starting with channel 0

static volatile struct {
    unsigned initialized : 1;
    unsigned valid       : 1;
    unsigned chan        : 4;
} adc_async_state;

static volatile uint8_t adc_async_valid = 0;
static volatile uint16_t adc_async_res[ADC_ASYNC_N_CHAN];

//============================================================================================================
// Analog stick evaluation
// TODO: Add a zero position calibration

#include "arduboy2_flb_config.h"

// stick_state saves the direction flags in the same bits as 
// the direction button flags (see core.h).
static volatile uint8_t  stick_state;

uint8_t analog_stick_get_state(void)
{
    return stick_state;
}

#define STICK_THRES_LEFT   (-ANALOG_STICK_THRES + ANALOG_STICK_ZERO)
#define STICK_THRES_RIGHT  (+ANALOG_STICK_THRES + ANALOG_STICK_ZERO)

void analog_stick_eval(void)
{
    register uint8_t state = 0;
    
    register uint16_t adc_res = adc_async_res[ANALOG_STICK_X_CHAN];
    if (adc_res > STICK_THRES_RIGHT)
        state |= RIGHT_BUTTON;
    else if (adc_res < STICK_THRES_LEFT)
        state |= LEFT_BUTTON;
    
    adc_res = adc_async_res[ANALOG_STICK_Y_CHAN];
    if (adc_res > STICK_THRES_RIGHT)
        state |= UP_BUTTON;
    else if (adc_res < STICK_THRES_LEFT)
        state |= DOWN_BUTTON;

    stick_state = state;
}

//============================================================================================================

// Initialize and start background acquisition
void adc_async_init(void)
{
  ADCSRA = 0;  // adc off
  
  for (uint8_t i=0; i<ADC_ASYNC_N_CHAN; i++)
    adc_async_res[i] = 0;

  adc_async_state.chan = 0;
  adc_async_state.valid = 0;
  adc_async_state.initialized = 1;
  
  ADMUX = 0b01000000;  // select adc channel 0 (A0 on the Uno)
                      // result right justified
                      // reference to Vcc
                      
  ADCSRA = 0b11001111;  // adc enable, 
                        // PS=128 (--> 125kHz adc clock, approx. 9600 conversions per sec.)
                        // adc interrupt enable
                        // start conversion
}

//============================================================================================================

// Query if results are available for all channels
uint8_t adc_async_available(void)
{
  return adc_async_state.valid;
}

//============================================================================================================

// Read last stored result for channel <chan>
uint16_t adc_async_get_last_res( uint8_t chan )
{
  if (chan >= ADC_ASYNC_N_CHAN)  return 0;
  uint8_t sreg_bak = SREG;
  cli();
  uint16_t res = adc_async_res[chan];
  sei();
  return res;
}

//============================================================================================================

// ADC interrupt service
ISR(ADC_vect)
{
  if (adc_async_state.initialized == 0)  return;

  register uint16_t res = ADCL;  // NOTE: Read ADCL first!
  res |= ADCH << 8;
  adc_async_res[adc_async_state.chan] = res;
  if( ++adc_async_state.chan >= ADC_ASYNC_N_CHAN)  {
    adc_async_state.chan = 0;
    adc_async_state.valid = 1;
    analog_stick_eval();   // --> analog stick evaluation 
  }
  ADMUX = (ADMUX & 0b11110000) | adc_async_state.chan;  // select next adc channel
  ADCSRA |= 1<<ADSC;         // start next conversion
}

//============================================================================================================
