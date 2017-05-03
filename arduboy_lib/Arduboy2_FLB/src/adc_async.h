
//============================================================================================================
// Asynchronous ADC acquisition (ADC interrupt driven)
// Switches through ADC channels 0 to ADC_ASYNC_N_CHAN-1 and stores
// the results in the background.
//============================================================================================================

#ifndef ADC_ASYNC_H
#define ADC_ASYNC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

//============================================================================================================

// Initialize and start background acquisition
void adc_async_init(void);

// Query if results are available for all channels
uint8_t adc_async_available(void);

// Read last stored result for channel <chan>
uint16_t adc_async_get_last_res( uint8_t chan );

// Get analog stick direction state flags
uint8_t analog_stick_get_state(void);

// Calibrate analog stick center position
void analog_stick_calib(void);

//============================================================================================================

#ifdef __cplusplus
}
#endif

#endif  // ADC_ASYNC_H

