#include "bitmaps.h"

PROGMEM const unsigned char star [] = {
  0x00, 0x10, 0x10, 0x28, 0xC6, 0x28, 0x10, 0x10, 0x00, 0x00,
};

PROGMEM const unsigned char sajaxAlta [] = {
0x1C, 0xF7, 0x1C, 0xC0, 0x40, 0x40, 0xC0, 0x1C, 0xF7, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

PROGMEM const unsigned char bomb [] = {
0x00, 0x00, 0x10, 0x38, 0x38, 0x10, 0x00, 0x00, 
};

PROGMEM const unsigned char ship [] = {
0x00, 0x10, 0x10, 0x28, 0x26, 0x28, 0x10, 0x10, 0x00, 0x00, 
};

PROGMEM
const unsigned char mreData [] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x1F, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xE0, 0x80, 0xE0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x01,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x81, 0xF1, 0xF3, 0x07, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
  0x07, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x06, 0x07,
  0xFF, 0xFF, 0xFD, 0xFD, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0x00, 0x03, 0x07, 0x1F, 0x1F, 0x80, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0C, 0x0F, 0x0F, 0x0E,
  0x0C, 0x00, 0x01, 0x0F, 0x07, 0x00, 0x00, 0x08, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
  0x0C, 0x08, 0x00, 0x00, 0x08, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0C, 0x08, 0x00,
  0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x03, 0x00, 0x08, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F,
  0x0F, 0x0F, 0x0F, 0x00, 0x0C, 0x0C, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
  0x00, 0x18, 0x18, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF8, 0xF8, 0x38, 0x18, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x18, 0x38, 0xF8,
  0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
  0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  0xFC, 0x0F, 0x00, 0x03, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xC0, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFC, 0x0F, 0x00, 0x03, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFC, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x00, 0xC0, 0xC0, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F, 0x0F, 0x01, 0x00, 0xC0, 0xC0, 0xE0, 0xFC, 0xCF,
  0xC0, 0x04, 0x06, 0x06, 0x06, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xC0, 0x80, 0x00,
  0x00, 0x00, 0x00, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0x00, 0x00,
  0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xFC, 0xCF, 0xC0, 0x04, 0x06, 0x06, 0x06, 0xC7, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xF8, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const byte PROGMEM score [] = {
// Debussy: Childrens Corner 4
// The snow is dancing
0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,8, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 
0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 0x91,56, 
0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,192, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,65, 0x91,41, 0x92,56, 
0x93,60, 0x94,63, 0x95,77, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,8, 0x90,43, 0x91,58, 0x92,62, 
0x93,65, 0x94,67, 0x95,79, 0,104, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,65, 0x91,43, 0x92,58, 0x93,62, 
0x94,67, 0x95,79, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 
0x94,65, 0x95,77, 0,8, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 
0x95,77, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 
0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,65, 0x91,41, 0x92,56, 0x93,60, 0x94,63, 0x95,77, 
0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,43, 0x91,58, 0x92,62, 0x93,65, 0x94,67, 0x95,79, 
0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,43, 0x91,58, 0x92,62, 0x93,65, 0x94,67, 0x95,79, 0,96, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,43, 0x91,58, 0x92,62, 0x93,65, 0x94,67, 0x95,79, 0,96, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,43, 0x91,58, 0x92,62, 0x93,65, 0x94,67, 0x95,79, 0,96, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,65, 0x91,43, 0x92,58, 0x93,62, 0x94,67, 0x95,79, 0,96, 0x80, 
0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,8, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,96, 0x80, 
0x81, 0x82, 0x83, 0x84, 0x85, 0x90,41, 0x91,56, 0x92,60, 0x93,63, 0x94,65, 0x95,77, 0,192, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0x90,65, 0x91,41, 0x92,56, 0x93,60, 0x94,63, 0x95,77, 0,96, 0x80, 0x81, 0x82, 
0x83, 0x84, 0x85, 0,8, 0x90,43, 0x91,58, 0x92,62, 0x93,65, 0x94,67, 0x95,79, 0,104, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0x90,65, 0x91,43, 0x92,58, 0x93,62, 0x94,67, 0x95,79, 0,96, 0x80, 0x81, 0x82, 
0x83, 0x84, 0x85, 0,96, 0x90,65, 0x91,60, 0x92,63, 0x93,41, 0x94,56, 0x95,77, 0,96, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0,201, 0x90,58, 0x91,43, 0x92,62, 0x93,67, 0x94,65, 0x95,79, 0,122, 0x80, 
0x81, 0x82, 0x83, 0x84, 0x85, 0x90,39, 0x91,55, 0x92,58, 0x93,60, 0x94,63, 0x95,75, 0,96, 0x81, 0x82, 
0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,39, 0,192, 0x80, 0x90,55, 0x91,58, 0x92,46, 
0x93,60, 0x94,63, 0,96, 0x80, 0x81, 0x83, 0x84, 0,96, 0x82, 0,192, 0x90,41, 0,192, 0x80, 0x90,39, 
0x91,72, 0,96, 0x81, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0x91,53, 0x92,55, 0x93,58, 
0x94,62, 0x95,70, 0,96, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,43, 
0,192, 0x80, 0x90,53, 0x91,55, 0x92,58, 0x93,62, 0x94,46, 0,96, 0x80, 0x81, 0x82, 0x83, 0,96, 
0x84, 0,192, 0x90,55, 0x91,58, 0x92,53, 0x93,62, 0,96, 0x80, 0x81, 0x82, 0x83, 0,96, 0x90,67, 
0,96, 0x80, 0,8, 0x90,39, 0x91,55, 0x92,58, 0x93,60, 0x94,63, 0x95,72, 0,96, 0x81, 0x82, 
0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,70, 0x91,39, 0,96, 0x80, 0,96, 0x81, 
0x90,55, 0x91,58, 0x92,46, 0x93,60, 0x94,63, 0,96, 0x80, 0x81, 0x83, 0x84, 0,96, 0x82, 0x90,43, 
0x91,67, 0,96, 0x81, 0,96, 0x80, 0x90,41, 0x91,70, 0,96, 0x81, 0,96, 0x80, 0x90,39, 0,192, 
0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0x91,53, 0x92,55, 0x93,58, 0x94,62, 0x95,65, 0,96, 0x81, 
0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0,192, 0x80, 0x90,53, 0x91,55, 
0x92,58, 0x93,62, 0x94,67, 0x95,46, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0,96, 0x85, 0,192, 0x90,53, 
0x91,58, 0x92,62, 0x93,55, 0,96, 0x80, 0x81, 0x82, 0x83, 0,201, 0x90,53, 0x91,65, 0x92,60, 0x93,41, 
0x94,56, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,43, 0x91,53, 0x92,58, 0x93,62, 0x94,67, 0,60, 
0x84, 0,35, 0x81, 0x82, 0x83, 0,96, 0x80, 0x90,70, 0,96, 0x80, 0,96, 0x90,58, 0x91,62, 0x92,53, 
0x93,43, 0,17, 0x80, 0x81, 0x82, 0x83, 0x90,65, 0x91,55, 0x92,58, 0x93,62, 0x94,39, 0,8, 0x80, 
0,96, 0x90,65, 0,62, 0x80, 0,129, 0x81, 0x82, 0x83, 0x84, 0x90,60, 0x91,55, 0x92,63, 0x93,63, 
0x94,48, 0,59, 0x82, 0x83, 0,36, 0x80, 0x81, 0,96, 0x84, 0x90,60, 0,192, 0x91,60, 0x92,55, 
0x93,63, 0x94,36, 0,96, 0x80, 0x81, 0,201, 0x82, 0x83, 0x84, 0x90,56, 0x91,60, 0x92,65, 0x93,41, 
0x94,53, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,43, 0x91,55, 0x92,58, 0x93,62, 0x94,67, 0,48, 
0x84, 0,48, 0x81, 0x82, 0x83, 0,96, 0x80, 0x90,70, 0,96, 0x80, 0,96, 0x90,58, 0x91,62, 0x92,55, 
0x93,43, 0,17, 0x80, 0x81, 0x82, 0x83, 0x90,60, 0x91,63, 0x92,72, 0x93,56, 0x94,44, 0,8, 0x82, 
0,96, 0x92,70, 0,48, 0x82, 0,144, 0x80, 0x81, 0x83, 0x84, 0x90,58, 0x91,62, 0x92,65, 0x93,46, 
0x94,67, 0,96, 0x80, 0x81, 0x82, 0x84, 0,96, 0x83, 0,192, 0x90,58, 0x91,62, 0x92,70, 0x93,65, 
0x94,34, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,39, 0x91,55, 0x92,58, 0x93,60, 0x94,63, 0x95,75, 
0,96, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,39, 0,192, 0x80, 0x90,55, 
0x91,58, 0x92,46, 0x93,60, 0x94,63, 0,96, 0x80, 0x81, 0x83, 0x84, 0,96, 0x82, 0,192, 0x90,41, 
0,192, 0x80, 0x90,39, 0x91,72, 0,96, 0x81, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0x91,53, 
0x92,55, 0x93,58, 0x94,62, 0x95,70, 0,96, 0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 
0x80, 0x90,43, 0,192, 0x80, 0x90,53, 0x91,55, 0x92,58, 0x93,62, 0x94,46, 0,96, 0x80, 0x81, 0x82, 
0x83, 0,96, 0x84, 0,192, 0x90,55, 0x91,58, 0x92,53, 0x93,62, 0,96, 0x80, 0x81, 0x82, 0x83, 0,96, 
0x90,67, 0,96, 0x80, 0,8, 0x90,39, 0x91,55, 0x92,58, 0x93,60, 0x94,63, 0x95,72, 0,96, 
0x81, 0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,70, 0x91,39, 0,96, 0x80, 0,96, 
0x81, 0x90,55, 0x91,58, 0x92,46, 0x93,60, 0x94,63, 0,96, 0x80, 0x81, 0x83, 0x84, 0,96, 0x82, 0x90,43, 
0x91,67, 0,96, 0x81, 0,96, 0x80, 0x90,41, 0x91,70, 0,96, 0x81, 0,96, 0x80, 0x90,39, 0,192, 
0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0x91,53, 0x92,55, 0x93,58, 0x94,62, 0x95,65, 0,96, 0x81, 
0x82, 0x83, 0x84, 0x85, 0,96, 0x80, 0x90,41, 0,192, 0x80, 0x90,43, 0,192, 0x80, 0x90,53, 0x91,55, 
0x92,58, 0x93,62, 0x94,46, 0x95,67, 0,96, 0x80, 0x81, 0x82, 0x83, 0x85, 0,96, 0x84, 0,192, 0x90,53, 
0x91,58, 0x92,62, 0x93,55, 0,96, 0x80, 0x81, 0x82, 0x83, 0,201, 0x90,53, 0x91,65, 0x92,60, 0x93,41, 
0x94,56, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,53, 0x91,58, 0x92,62, 0x93,67, 0x94,46, 0,60, 
0x83, 0,35, 0x80, 0x81, 0x82, 0,96, 0x90,70, 0,90, 0x80, 0,102, 0x90,58, 0x91,62, 0x92,53, 
0,192, 0x93,67, 0,90, 0x83, 0,14, 0x80, 0x81, 0x82, 0x84, 0x90,65, 0x91,55, 0x92,58, 0x93,62, 
0x94,39, 0,79, 0x80, 0,112, 0x90,67, 0,58, 0x80, 0,134, 0x90,65, 0,62, 0x80, 0,129, 
0x81, 0x82, 0x83, 0x84, 0x90,60, 0x91,55, 0x92,63, 0x93,63, 0x94,48, 0,59, 0x82, 0x83, 0,36, 0x80, 
0x81, 0,96, 0x84, 0x90,60, 0,192, 0x80, 0x90,60, 0x91,55, 0x92,63, 0x93,36, 0,17, 0x80, 0x81, 
0x82, 0x83, 0x90,56, 0x91,60, 0x92,65, 0x93,41, 0x94,53, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,43, 
0x91,55, 0x92,58, 0x93,62, 0x94,67, 0,96, 0x81, 0x82, 0x83, 0x84, 0,96, 0x80, 0x90,70, 0,96, 
0x80, 0,95, 0x90,58, 0x91,62, 0x92,55, 0x93,43, 0,192, 0x94,67, 0,68, 0x84, 0,36, 0x80, 
0x81, 0x82, 0x83, 0x90,70, 0x91,60, 0x92,63, 0x93,56, 0x94,44, 0,87, 0x80, 0,104, 0x90,72, 0,58, 
0x80, 0,133, 0x90,70, 0,71, 0x80, 0,120, 0x81, 0x82, 0x83, 0x84, 0x90,46, 0x91,58, 0x92,62, 0x93,65, 
0x94,67, 0,46, 0x84, 0,49, 0x81, 0x82, 0x83, 0,96, 0x80, 0x90,70, 0,192, 0x91,65, 0x92,46, 
0x93,58, 0x94,62, 0,69, 0x80, 0,227, 0x81, 0x82, 0x83, 0x84, 0x90,48, 0x91,55, 0x92,60, 0x93,63, 
0x94,79, 0,192, 0x80, 0x81, 0x82, 0x83, 0,192, 0x84, 0x90,48, 0x91,77, 0,192, 0x80, 0x81, 0x90,55, 
0x91,60, 0x92,63, 0x93,75, 0x94,48, 0,96, 0x83, 0,96, 0x84, 0,192, 0x80, 0x81, 0x82, 0x90,60, 
0x91,63, 0x92,72, 0x93,55, 0x94,36, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,41, 0x91,75, 0x92,53, 
0x93,56, 0x94,60, 0x95,65, 0,96, 0x81, 0,96, 0x80, 0x82, 0x83, 0x84, 0x85, 0,192, 0x90,41, 0x91,75, 
0,192, 0x80, 0x81, 0x90,41, 0x91,53, 0x92,56, 0x93,60, 0x94,65, 0x95,77, 0,192, 0x80, 0,192, 
0x81, 0x82, 0x83, 0x84, 0x90,53, 0x91,56, 0x92,60, 0x93,65, 0x94,41, 0,96, 0x80, 0x81, 0x82, 0x83, 0x90,53, 
0x91,56, 0x92,60, 0x93,65, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,53, 0x91,56, 0x92,60, 0x93,65, 
0x94,44, 0,192, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,53, 0x91,60, 0x92,41, 0x93,56, 0x94,65, 0,192, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x90,46, 0x91,53, 0x92,58, 0x93,63, 0x94,77, 0,192, 0x80, 0x81, 0x82, 0x83, 
0,192, 0x84, 0x90,46, 0x91,75, 0,192, 0x80, 0x81, 0x90,53, 0x91,58, 0x92,63, 0x93,46, 0x94,72, 
0,96, 0x84, 0,96, 0x80, 0x81, 0x82, 0x83, 0x90,53, 0x91,58, 0x92,63, 0,192, 0x80, 0x81, 0x82, 0x90,58, 
0x91,63, 0x92,75, 0x93,53, 0x94,34, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,39, 0x91,77, 0x92,55, 
0x93,58, 0x94,63, 0,96, 0x81, 0,96, 0x80, 0x82, 0x83, 0x84, 0,192, 0x90,39, 0x91,77, 0,192, 
0x80, 0x81, 0x90,39, 0x91,55, 0x92,58, 0x93,63, 0x94,75, 0,192, 0x80, 0,192, 0x81, 0x82, 0x83, 0x90,55, 
0x91,58, 0x92,63, 0x93,39, 0,96, 0x80, 0x81, 0x82, 0x90,55, 0x91,58, 0x92,63, 0,96, 0x80, 0x81, 
0x82, 0x84, 0x83, 0x90,55, 0x91,58, 0x92,63, 0x93,43, 0,192, 0x80, 0x81, 0x82, 0x83, 0x90,55, 0x91,63, 
0x92,46, 0x93,58, 0,192, 0x80, 0x81, 0x82, 0x83, 0x90,48, 0x91,55, 0x92,60, 0x93,63, 0x94,79, 0,192, 
0x80, 0x81, 0x82, 0x83, 0,192, 0x84, 0x90,48, 0x91,77, 0,192, 0x80, 0x81, 0x90,55, 0x91,60, 0x92,63, 
0x93,75, 0x94,48, 0,96, 0x83, 0,96, 0x84, 0,192, 0x80, 0x81, 0x82, 0x90,60, 0x91,55, 0x92,63, 
0x93,72, 0x94,36, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,41, 0x91,41, 0x92,75, 0x93,56, 0x94,60, 
0x95,65, 0,96, 0x82, 0,96, 0x80, 0x81, 0x83, 0x84, 0x85, 0,192, 0x90,41, 0x91,75, 0,192, 0x80, 
0x81, 0x90,41, 0x91,53, 0x92,56, 0x93,60, 0x94,65, 0x95,77, 0,192, 0x80, 0,192, 0x81, 0x82, 0x83, 
0x84, 0x90,53, 0x91,56, 0x92,60, 0x93,65, 0x94,41, 0,96, 0x80, 0x81, 0x82, 0x83, 0x90,53, 0x91,56, 
0x92,60, 0x93,65, 0,96, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,53, 0x91,56, 0x92,60, 0x93,65, 0x94,44, 
0,192, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,60, 0x91,56, 0x92,65, 0x93,41, 0x94,53, 0,192, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x90,45, 0x91,55, 0x92,60, 0x93,63, 0x94,77, 0,192, 0x80, 0x81, 0x82, 0x83, 0,192, 
0x84, 0x90,45, 0x91,75, 0,192, 0x80, 0x81, 0x90,55, 0x91,60, 0x92,63, 0x93,45, 0x94,72, 0,96, 
0x84, 0,96, 0x80, 0x81, 0x82, 0x83, 0x90,55, 0x91,60, 0x92,63, 0,192, 0x80, 0x81, 0x82, 0x90,60, 0x91,63, 
0x92,75, 0x93,55, 0x94,45, 0,17, 0x80, 0x81, 0x82, 0x83, 0x84, 0x90,44, 0x91,56, 0x92,60, 0x93,63, 
0x94,77, 0,96, 0x84, 0,96, 0x80, 0x81, 0x82, 0x83, 0,192, 0x90,44, 0x91,75, 0,192, 0x80, 0x81, 
0x90,44, 0x91,56, 0x92,60, 0x93,63, 0x94,72, 0,192, 0x80, 0,192, 0x81, 0x82, 0x83, 0x90,56, 0x91,60, 
0x92,63, 0x93,44, 0,96, 0x80, 0x81, 0x82, 0x90,56, 0x91,60, 0x92,63, 0,96, 0x80, 0x81, 0x82, 0x84, 
0x90,56, 0x91,60, 0x92,63, 0,192, 0x80, 0x81, 0x82, 0x90,56, 0x91,60, 0x92,63, 0,192, 0x83, 0x80, 
0x81, 0x82, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,43, 0x95,74, 0,192, 0x84, 0x94,38, 0,96, 
0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,71, 0,96, 0x80, 0x81, 0x82, 
0x83, 0x84, 0,192, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,67, 0x95,38, 0,96, 0x80, 0x81, 0x82, 
0x83, 0x84, 0,96, 0x85, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,43, 0x95,67, 0,96, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,65, 0x95,38, 0,96, 0x80, 0x81, 0x82, 
0x83, 0x84, 0x85, 0,96, 0x90,43, 0x91,55, 0x92,59, 0x93,62, 0x94,65, 0x95,67, 0,96, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0,96, 0x90,55, 0x91,59, 0x92,62, 0x93,65, 0x94,43, 0x95,71, 0,96, 0x80, 
0x81, 0x82, 0x83, 0x84, 0x85, 0x90,38, 0x91,55, 0x92,59, 0x93,62, 0x94,65, 0x95,74, 0,96, 0x80, 0x81, 
0x82, 0x83, 0x84, 0x85, 0xf0 };
// This score contains 1598 bytes, and 6 tone generators are used.
// 6 notes had to be skipped.

// Playtune bytestream for file "tielaser.mid" created by MIDITONES V1.7 on Mon Feb 01 15:17:17 2016
// command line: miditones tielaser 
const byte PROGMEM laser [] = {
0x90,58, 0x91,59, 0x92,60, 0x93,64, 0x94,65, 0x95,67, 0,100, 0x80, 0x81, 0xf0};
// This score contains 28 bytes, and 6 tone generators are used.
// 18 notes had to be skipped.

