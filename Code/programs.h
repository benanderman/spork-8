#ifndef PROGRAMS_H
#define PROGRAMS_H

#include <Arduino.h>

uint8_t getMovingDotByte(uint16_t address);
uint8_t getJumpToCartridgeByte(uint16_t address);
uint8_t getSnakeByte(uint16_t address);
uint8_t getSnake2PByte(uint16_t address);
uint8_t getMemEditByte(uint16_t address);

#endif
