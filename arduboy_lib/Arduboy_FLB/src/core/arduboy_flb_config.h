//=================================================================================================
// Hardware profile for the Fablab Bayreuth Arduino Gamer clone
// To be used with the Arduboy library.
//=================================================================================================

#ifndef ARDUBOY_FLB_CONFIG_H
#define ARDUBOY_FLB_CONFIG_H

//=================================================================================================

// Display control lines
#define CS 9
#define DC 10
#define RST 12

// Not present on this hardware
//#define RED_LED 10
//#define GREEN_LED 11
//#define BLUE_LED 9
//#define TX_LED 30
//#define RX_LED 17

// Right keypad on Arduino-Gamer
#define PIN_GAMER_A  2       // PD2
#define PIN_GAMER_B  3       // PD3
#define PIN_GAMER_C  4       // PD4
#define PIN_GAMER_D  5       // PD5
#define PIN_GAMER_STICK  8   // PB0

#define PIN_LEFT_BUTTON   PIN_GAMER_D
#define PIN_RIGHT_BUTTON  PIN_GAMER_B
#define PIN_UP_BUTTON     PIN_GAMER_A
#define PIN_DOWN_BUTTON   PIN_GAMER_C
#define PIN_A_BUTTON      PIN_GAMER_STICK   
#define PIN_B_BUTTON      PIN_GAMER_A

// These bits are used by the API to denote button states
// NOTE: If these are changed, the corresponding evaluation procedure in 
//       ArduboyCore::buttonsState() needs to be changed accordingly!

#define LEFT_BUTTON  _BV(0)   // Directions are mapped to the analog stick
#define RIGHT_BUTTON _BV(1)  
#define UP_BUTTON    _BV(6)     
#define DOWN_BUTTON  _BV(7)   

#define A_BUTTON _BV(2)
#define B_BUTTON _BV(3)
#define C_BUTTON _BV(4)
#define D_BUTTON _BV(5)

#define STICK_BUTTON _BV(2)    // Use as A_BUTTON

#define DPAD_LEFT_BUTTON   D_BUTTON  // Directions on digital pad
#define DPAD_RIGHT_BUTTON  B_BUTTON
#define DPAD_UP_BUTTON     A_BUTTON
#define DPAD_DOWN_BUTTON   C_BUTTON

// Speaker output
#define PIN_SPEAKER_1 6
#define PIN_SPEAKER_2 7

#define PIN_SPEAKER_1_PORT &PORTD    // Port/bit are not used as it seems
#define PIN_SPEAKER_2_PORT &PORTD
#define PIN_SPEAKER_1_BITMASK _BV(6)
#define PIN_SPEAKER_2_BITMASK _BV(7)

// Analog stick
#define ANALOG_STICK_X_CHAN  0     // x-axis analog channel
#define ANALOG_STICK_Y_CHAN  1     // y-axis 
#define ANALOG_STICK_ZERO    512   // adc reading at center position
#define ANALOG_STICK_THRES    24   // threshold for direction evaluation


// Various settings
//#define HAVE_HWSERIAL1  // Leave UART1 on (is switched off by default to save power)

//=================================================================================================

#endif  // ARDUBOY_FLB_CONFIG_H