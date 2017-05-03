
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
                        
  while (!adc_async_state.valid)
      ;  // wait for first valid measurement
}

//============================================================================================================

// Query if results are available for all channels
uint8_t adc_async_available(void)
{
  return adc_async_state.valid;
}

//============================================================================================================

// Wait for next measurement
void adc_async_wait_next(void)
{
    adc_async_state.valid = 0;
     while (!adc_async_state.valid)
      ;  
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

void analog_stick_eval(void);


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
// Analog stick evaluation

#include "arduboy2_flb_config.h"  // for channel/buttons bits definitions

#define STICK_ZERO    512   // Uncalibrated  center position 
#define STICK_THRES    24   // Threshold for direction evaluation

// stick_state saves the direction flags in the same bits as 
// the direction button flags (see core.h).
static volatile uint8_t  stick_state;

// Zero positions for stick x/y-axes
//static 
        uint16_t  stick_zero_x = STICK_ZERO,
                 stick_zero_y = STICK_ZERO;

//============================================================================================================

uint8_t analog_stick_get_state(void)
{
    return stick_state;
}

//============================================================================================================

#define STICK_THRES_LEFT   (-STICK_THRES + STICK_ZERO)
#define STICK_THRES_RIGHT  (+STICK_THRES + STICK_ZERO)


void analog_stick_eval(void)
{
    register uint8_t state = 0;
    
    register uint16_t adc_res = adc_async_get_last_res(ANALOG_STICK_X_CHAN);
    if (adc_res > stick_zero_x + STICK_THRES)
        state |= RIGHT_BUTTON;
    else if (adc_res < stick_zero_x - STICK_THRES)
        state |= LEFT_BUTTON;
    
    adc_res = adc_async_get_last_res(ANALOG_STICK_Y_CHAN);
    if (adc_res > stick_zero_y + STICK_THRES)
        state |= UP_BUTTON;
    else if (adc_res < stick_zero_y - STICK_THRES)
        state |= DOWN_BUTTON;

    stick_state = state;
}

//============================================================================================================

// Analog stick zero position calibration

#define CALIB_N_SAMP  10         // Number of samples to evaluate
#define CALIB_VALID_RANGE   50   // Valid deviation from nominal zero to accept as center position
#define CALIB_VALID_CHANGE  4    // Valid change during measurement to accept as standing still

void analog_stick_calib(void)
{
    uint16_t  x_max, x_min, x_avg,
              y_max, y_min, y_avg;
              
    // Collect 10 sucessive samples, calculate min/max/average
    while (1)  {
        x_max = x_min = x_avg = adc_async_get_last_res( ANALOG_STICK_X_CHAN );
        y_max = y_min = y_avg = adc_async_get_last_res( ANALOG_STICK_Y_CHAN );
        for (uint8_t i=1; i<CALIB_N_SAMP; i++)  {
            adc_async_wait_next();
            uint16_t x = adc_async_get_last_res( ANALOG_STICK_X_CHAN );
            uint16_t y = adc_async_get_last_res( ANALOG_STICK_Y_CHAN );
            x_avg += x;  y_avg += y;
            if (x > x_max)  x_max = x;
            else if (x < x_min)  x_min = x;
            if (y > y_max)  y_max = y;
            else if (y < y_min)  y_min = y;
        }
        x_avg /= CALIB_N_SAMP;
        y_avg /= CALIB_N_SAMP;
    
        // Repeat until all break conditions are fulfilled:
        if ( abs(x_max - x_min) <= CALIB_VALID_CHANGE  && 
             abs(y_max - y_min) <= CALIB_VALID_CHANGE  &&
             abs(x_avg - STICK_ZERO) <= CALIB_VALID_RANGE  &&
             abs(y_avg - STICK_ZERO) <= CALIB_VALID_RANGE )
             break;
    } 
    
    stick_zero_x = x_avg;
    stick_zero_y = y_avg;

}
































