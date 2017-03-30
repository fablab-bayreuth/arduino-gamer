#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "fablablogo.h"

#define OLED_CLK   13
#define OLED_MOSI  12
#define OLED_RESET 11
#define OLED_DC    10
#define OLED_CS     9

#define FONT_SIZE 1
#define SCREEN_WIDTH 127  //real size minus 1, because coordinate system starts with 0
#define SCREEN_HEIGHT 63  //real size minus 1, because coordinate system starts with 0

#define PIN_BUTTON_A 2
#define PIN_BUTTON_B 3
#define PIN_BUTTON_C 4
#define PIN_BUTTON_D 5
#define PIN_BUTTON_E 6
#define PIN_BUTTON_F 7
#define PIN_BUTTON_STICK 8

#define PIN_STICK_X A0
#define PIN_STICK_Y A1
#define PIN_POTI_L A2
#define PIN_POTI_R A3

#define PIN_BEEPER 6
#define PIN_BEEPER_GND 7

int state_button_a = LOW;
int state_button_b = LOW;
int state_button_c = LOW;
int state_button_d = LOW;
int state_button_e = LOW;
int state_button_f = LOW;
int state_button_stick = LOW;

int position_stick_x = 0;
int position_stick_y = 0;
int position_poti_l = 0;
int position_poti_r = 0;

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC);
  display.ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV); // Set maximum diplay clock
  display.ssd1306_command(0xF0);                       
  
  display.setTextColor(WHITE);
  display.setTextSize(FONT_SIZE);

  display.clearDisplay();
  display.display();

  splash();
  soundStart();
}

void loop() {
  readInputs();
  draw();
  sound();
}

void soundStart() 
{
  pinMode(PIN_BEEPER_GND, OUTPUT);
  pinMode(PIN_BEEPER, OUTPUT);
  
  tone(PIN_BEEPER, 500);
  delay(80);
  noTone(PIN_BEEPER);
  delay(100);
  tone(PIN_BEEPER, 500);
  delay(80);
  noTone(PIN_BEEPER);
  delay(100);
  tone(PIN_BEEPER, 500);
  delay(80);
  noTone(PIN_BEEPER);
  delay(100);
  tone(PIN_BEEPER, 1000);
  delay(500);
  noTone(PIN_BEEPER);

//  pinMode(PIN_BEEPER_GND, INPUT);
//  pinMode(PIN_BEEPER, INPUT);

  delay(500);
}

void splash() {
  display.clearDisplay(); 
  
  // Das Bild wurde konvertiert mit http://javl.github.io/image2cpp/
  display.drawBitmap(0, 0, logo, 40, 40, WHITE);

  display.setCursor(8, 56);
  display.print("V1.0");
  
  const int column_2 = 48;

  display.setCursor(column_2, 0);
  display.print("Arduino Gamer");

  display.drawFastHLine(column_2, 10, SCREEN_WIDTH-column_2, WHITE);

  display.setCursor(column_2, 14);
  display.print("Testanwendung");
  display.setCursor(column_2, 14+9);
  display.print(" by thirsch");

  display.display();
}

void readInputs() {
  state_button_a = digitalRead(PIN_BUTTON_A);
  state_button_b = digitalRead(PIN_BUTTON_B);
  state_button_c = digitalRead(PIN_BUTTON_C);
  state_button_d = digitalRead(PIN_BUTTON_D);
  state_button_e = digitalRead(PIN_BUTTON_E);
  state_button_f = digitalRead(PIN_BUTTON_F);
  state_button_stick = digitalRead(PIN_BUTTON_STICK);

  position_stick_x = analogRead(PIN_STICK_X);
  position_stick_y = analogRead(PIN_STICK_Y);
  position_poti_l = analogRead(PIN_POTI_L);
  position_poti_r = analogRead(PIN_POTI_R);
}

void sound(void)
{
    if (state_button_c == 0)
        tone(PIN_BEEPER, position_poti_l);
    else
        noTone(PIN_BEEPER);
}

void draw() {
  display.clearDisplay(); 
  
  // Das Bild wurde konvertiert mit http://javl.github.io/image2cpp/
  display.drawBitmap(0, 0, logo, 40, 40, WHITE);

  display.setCursor(8, 56);
  display.print("V1.0");
  
  const int column_2 = 48;

  display.setCursor(column_2, 0);
  display.print("Arduino Gamer");

  display.drawFastHLine(column_2, 10, SCREEN_WIDTH-column_2, WHITE);

  const int row_offset = 9;
  int row = 14;
  display.setCursor(column_2, row);
  display.print("A:");
  display.print(state_button_a);
  display.print(" B:");
  display.print(state_button_b);
  display.print(" C:");
  display.print(state_button_c);

  row += row_offset;

  display.setCursor(column_2, row);
  display.print("D:");
  display.print(state_button_d);
  display.print(" E:");
  display.print(state_button_e);
  display.print(" F:");
  display.print(state_button_f);

  row += row_offset;

  display.setCursor(column_2, row);
  display.print("Joystick:");
  display.print(state_button_stick);

  row += row_offset;

  display.setCursor(column_2, row);
  display.print("X:");
  display.print(position_stick_x);
  display.print(" Y:");
  display.print(position_stick_y);

  row += row_offset;
  
  display.setCursor(column_2, row);
  display.print("L:");
  display.print(position_poti_l);
  display.print(" R:");
  display.print(position_poti_r);
  
  display.display();
}


