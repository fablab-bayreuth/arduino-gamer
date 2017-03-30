/*

  OLED/ArdWinVaders
  An Arduino & OLED version of a classic.

  For info and circuit diagrams see https://github.com/tardate/LittleArduinoProjects/tree/master/playground/OLED/ArdWinVaders

 */

// SM: drop dependecy of FLexiTimer2. Use a cooperative task handler instead.
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
}


void handleFireButtonPress() {
  fireStatus = 1;
}
