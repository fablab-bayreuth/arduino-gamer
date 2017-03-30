/*

  OLED/ArdWinVaders
  An Arduino & OLED version of a classic.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/ArdWinVaders

 */

// SM: drop dependecy of FLexiTimer2
//#include "FlexiTimer2.h"

// SM: Gamer Joystick shield:
#define BUTTON_A  2
#define BUTTON_B  3
#define BUTTON_C  4
#define BUTTON_D  5
#define BUTTON_ACTIVE_LOW

//** control pins
#define FIRE_PIN BUTTON_A
#define FIRE_INTERRUPT 0
#define LEFT_PIN  BUTTON_D
#define RIGHT_PIN BUTTON_B

volatile int fireStatus = 0;
volatile int moveLeft = 0;
volatile int moveRight = 0;

//** pin connections
#define SPEAKER_PIN 6
#define MOSI_PIN 12
#define CLK_PIN 13
#define DC_PIN 10
#define CS_PIN 9
#define RST_PIN 11

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

  readButtons();
  
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

void sampleMovement() {
  moveLeft = digitalRead(LEFT_PIN);
  moveRight = digitalRead(RIGHT_PIN);
}

void readButtons(void)
{
  static uint8_t  button_left_old, button_right_old;    // previous button states
  static uint32_t button_left_time, button_right_time;  // last button change times
  uint8_t button_left = digitalRead(LEFT_PIN),
          button_right = digitalRead(RIGHT_PIN);
  uint32_t now = millis();

  if (button_left != button_left_old  && now - button_left_time > 20)  {
    button_left_old = button_left;
    button_left_time = now;
    #ifdef BUTTON_ACTIVE_LOW
      moveLeft = !button_left;
    #else
      moveLeft = button_left;
    #endif
  }

  if (button_right != button_right_old  && now - button_right_time > 20)  {
    button_right_old = button_right;
    button_right_time = now;
    #ifdef BUTTON_ACTIVE_LOW
      moveRight = !button_right;
    #else
      moveRight = button_right;
    #endif
  }

}

void handleFireButtonPress() {
  fireStatus = 1;
}
