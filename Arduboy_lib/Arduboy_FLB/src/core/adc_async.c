
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

#define ADC_ASYNC_N_CHAN  6  // Channels to sample, starting with channel 0

static volatile struct {
    unsigned initialized : 1;
    unsigned valid       : 1;
    unsigned chan        : 4;
} adc_async_state;

static volatile uint8_t adc_async_valid = 0;
static volatile uint16_t adc_async_res[ADC_ASYNC_N_CHAN];

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
  if (!adc_async_state.valid)  return 0;
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
  // Note: The adc interrupt flag is cleared automatically by hardware when
  // executing the interrupt
  
  if (    adc_async_state.initialized == 0  
      ||  adc_async_state.chan >= ADC_ASYNC_N_CHAN )    // should not happen normally
    return;

  uint16_t res = ADCL;  // NOTE: Read ADCL first!
  res |= ADCH << 8;
  adc_async_res[adc_async_state.chan] = res;
  if( ++adc_async_state.chan >= ADC_ASYNC_N_CHAN)  {
    adc_async_state.chan = 0;
    adc_async_state.valid = 1;
  }
  ADMUX = (ADMUX & 0b11110000) | adc_async_state.chan;  // select next adc channel
  ADCSRA |= 1<<ADSC;         // start next conversion
}

//============================================================================================================
