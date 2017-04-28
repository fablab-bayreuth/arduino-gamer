/*

  OLED/ArdWinVaders
  An Arduino & OLED version of a classic.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/ArdWinVaders

 */

// SM: drop dependecy of FLexiTimer2. Use a cooperative task handler instead.
//#include "FlexiTimer2.h"

// SM: Arduino Gamer Joystick shield:
#define BUTTON_ACTIVE_LOW
#define PIN_BUTTON_A  2
#define PIN_BUTTON_B  3
#define PIN_BUTTON_C  4
#define PIN_BUTTON_D  5
#define PIN_STICK_X   A0
#define PIN_STICK_Y   A1
#define STICK_XY_THRES  5  

int16_t stick_x_center, stick_y_center;


//** control pins
#define FIRE_PIN   PIN_BUTTON_A
#define FIRE_INTERRUPT  0    // INT0 is connected to Pin 2 (BUTTON A)
#define LEFT_PIN   PIN_BUTTON_D
#define RIGHT_PIN  PIN_BUTTON_B

volatile int fireStatus = 0;
volatile int moveLeft = 0;
volatile int moveRight = 0;

// pin connections, SM: Adapted to Arduino-Gamer
#define SPEAKER_PIN 6
#define MOSI_PIN 11
#define CLK_PIN 13
#define DC_PIN 10
#define CS_PIN 9
#define RST_PIN 12

#include "oled_driver.h"
#include "buffered_display.h"
#include "game_board.h"
#include "sound_system.h"

SoundSystem soundSystem(SPEAKER_PIN);
OledDriver displayDriver(MOSI_PIN,CLK_PIN,DC_PIN,CS_PIN,RST_PIN);
BufferedDisplay gameDisplay(&displayDriver);
GameBoard gameBoard(&gameDisplay, &soundSystem);

void setup() {

  soundSystem.init();
  gameBoard.init();

  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);

  // SM: sample joystick center positions
  stick_x_center = analogRead(PIN_STICK_X);
  stick_y_center = analogRead(PIN_STICK_Y);
  
//  FlexiTimer2::set(20, sampleMovement);
//  FlexiTimer2::start();

  pinMode(FIRE_PIN, INPUT);
  // SM: Button active low option
  #ifdef BUTTON_ACTIVE_LOW
      attachInterrupt(FIRE_INTERRUPT, handleFireButtonPress, FALLING);
  #else
      attachInterrupt(FIRE_INTERRUPT, handleFireButtonPress, RISING);
  #endif

}

void loop() {

  handle_buttons();
  //readButtons();
  
  if(gameBoard.beginRecalc()) {
    if(moveLeft) gameBoard.moveLeft();
    if(moveRight) gameBoard.moveRight();
    if(fireStatus) {
      gameBoard.fire();
      fireStatus = 0;
    }
    gameBoard.finishRecalc();
  } else {
    if(fireStatus) {
      gameBoard.startGame();
      fireStatus = 0;
    }
  }
  gameDisplay.redraw();
  soundSystem.next();
}


//void sampleMovement() {
//  moveLeft = digitalRead(LEFT_PIN);
//  moveRight = digitalRead(RIGHT_PIN);
//}


//SM: cooperative task to sample direction buttons
void handle_buttons(void)
{
  static uint32_t last_time;
  uint32_t now = millis();
  if (now - last_time < 20)  return;
  last_time = now;
  
  #ifdef BUTTON_ACTIVE_LOW
    moveLeft = !digitalRead(LEFT_PIN);
    moveRight = !digitalRead(RIGHT_PIN);
  #else
    moveLeft = digitalRead(LEFT_PIN);
    moveRight = digitalRead(RIGHT_PIN);
  #endif

  int16_t stick_x = analogRead(PIN_STICK_X);
  if (abs(stick_x - stick_x_center) >= STICK_XY_THRES)  {
    if (stick_x < stick_x_center)  moveLeft |= 1;
    if (stick_x > stick_x_center)  moveRight |= 1;
  }
    
}


void handleFireButtonPress() {
  fireStatus = 1;
}
