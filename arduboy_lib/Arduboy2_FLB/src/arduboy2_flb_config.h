//=================================================================================================
// Hardware profile for the Fablab Bayreuth Arduino Gamer clone
// To be used with the Arduboy2 library.
//=================================================================================================

#ifndef ARDUBOY_FLB_CONFIG_H
#define ARDUBOY_FLB_CONFIG_H

//=================================================================================================

// Display lines
#define PIN_CS 9       // Display CS pin
#define CS_PORT PORTB   
#define CS_BIT PORTB1   

#define PIN_DC 10        // Display D/C pin
#define DC_PORT PORTB   
#define DC_BIT PORTD2   

#define PIN_RST 12       // Display reset pin
#define RST_PORT PORTB  
#define RST_BIT PORTD4  

#define SPI_MOSI_PORT PORTB   // SPI MOSI
#define SPI_MOSI_BIT PORTB3

#define SPI_SCK_PORT PORTB    // SPI SCK
#define SPI_SCK_BIT PORTB5


// RGB LED not present on this hardware, map to PORTC5 (unused) 
// so we do not need to change all the code that uses these defs.
#define RED_LED   19
#define GREEN_LED 19 
#define BLUE_LED  19    

#define RED_LED_PORT PORTC
#define RED_LED_BIT PORTC5

#define GREEN_LED_PORT PORTC
#define GREEN_LED_BIT PORTC5

#define BLUE_LED_PORT PORTC
#define BLUE_LED_BIT PORTC5


// bit values for button states
// these are determined by the buttonsState() function

// NOTE: If these are changed, the corresponding evaluation procedure in 
//       ArduboyCore::buttonsState() needs to be changed accordingly!

#define LEFT_BUTTON  _BV(0)    // Mapped to analog stick
#define RIGHT_BUTTON _BV(1) 
#define UP_BUTTON    _BV(6)    
#define DOWN_BUTTON  _BV(7)  

#define A_BUTTON     _BV(2)    // Right keypad on arduino gamer 
#define B_BUTTON     _BV(3)    // (2 buttons more than on the original Arduboy) 
#define C_BUTTON     _BV(4)     
#define D_BUTTON     _BV(5)     

#define STICK_BUTTON _BV(2)    // Use as A_BUTTON

#define DPAD_LEFT_BUTTON   D_BUTTON  // Directions on digital pad
#define DPAD_RIGHT_BUTTON  B_BUTTON
#define DPAD_UP_BUTTON     A_BUTTON
#define DPAD_DOWN_BUTTON   C_BUTTON

// Input button pins

//#define PIN_LEFT_BUTTON A2       // Direction buttons not present on this hardware
//#define LEFT_BUTTON_PORT PORTF
//#define LEFT_BUTTON_BIT PORTF5

//#define PIN_RIGHT_BUTTON A1
//#define RIGHT_BUTTON_PORT PORTF
//#define RIGHT_BUTTON_BIT PORTF6

//#define PIN_UP_BUTTON A0
//#define UP_BUTTON_PORT PORTF
//#define UP_BUTTON_BIT PORTF7

//#define PIN_DOWN_BUTTON A3
//#define DOWN_BUTTON_PORT PORTF
//#define DOWN_BUTTON_BIT PORTF4
    
#define PIN_A_BUTTON 2             // Right keypad on arduino gamer 
#define A_BUTTON_PORT PORTD        // (2 buttons more than on the original Arduboy)
#define A_BUTTON_BIT PORTE2

#define PIN_B_BUTTON 3
#define B_BUTTON_PORT PORTD
#define B_BUTTON_BIT PORTB3

#define PIN_C_BUTTON 4
#define A_BUTTON_PORT PORTD
#define A_BUTTON_BIT PORTE4

#define PIN_D_BUTTON 5
#define B_BUTTON_PORT PORTD
#define B_BUTTON_BIT PORTB5

#define PIN_STICK_BUTTON 8         // Analog stick push
#define STICK_BUTTON_PORT PORTB
#define STICK_BUTTON_BIT PORTB0

// Audio speaker

#define PIN_SPEAKER_1 6
#define PIN_SPEAKER_2 7

#define SPEAKER_1_PORT PORTD
#define SPEAKER_1_DDR DDRD
#define SPEAKER_1_BIT PORTD6

#define SPEAKER_2_PORT PORTD
#define SPEAKER_2_DDR DDRD
#define SPEAKER_2_BIT PORTD7

// Random number generator

#define RAND_SEED_IN A4     // Open analog input used for noise by initRandomSeed()
#define RAND_SEED_IN_PORTC
#define RAND_SEED_IN_BIT PORTC4
// Value for ADMUX to read the random seed pin: 1.1V reference, ADC4 on the ATmega328
#define RAND_SEED_IN_ADMUX (_BV(REFS0) | _BV(REFS1) | _BV(MUX1))

// Analog stick

#define ANALOG_STICK_X_CHAN  0     // x-axis analog channel
#define ANALOG_STICK_Y_CHAN  1     // y-axis 

// Analog pots

#define ANALOG_POT_LEFT_CHAN    2
#define ANALOG_POT_RIGHT_CHAN   3

// Various

#ifndef TXLED1    // Defined for some Ardunino boards, but not for the Uno, 
  #define TXLED1  //    used in Arduboy2Base::nextFrameDEV()
  #define TXLED0
#endif


//=================================================================================================

#endif  // ARDUBOY_FLB_CONFIG_H
