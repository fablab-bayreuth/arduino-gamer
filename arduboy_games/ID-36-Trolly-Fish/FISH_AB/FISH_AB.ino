/*
  Trolly Fish: http://www.team-arg.org/fish-manual.html

  Arduboy version 1.1:  http://www.team-arg.org/fish-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2016 - GAVENO - JO3RI - JUSTIN CRY

  License: MIT : https://opensource.org/licenses/MIT

*/

//determine the game
#define GAME_ID 36

#include "globals.h"
#include "player.h"
#include "enemies.h"
#include "powerups.h"
#include "stage.h"
#include "inputs.h"
#include "menu.h"
#include "game.h"


typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateGameInitLevel,
  stateGamePlaying,
  stateGamePause,
  stateGameOver,
};

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.initRandomSeed();
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  if (arduboy.everyXFrames(6))bubblesFrame++;
  if (bubblesFrame > 12) bubblesFrame = 0;
  arduboy.clear();
  ((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
  arduboy.display();
}
