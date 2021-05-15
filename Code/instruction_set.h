#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include <Arduino.h>

byte getMicrocodeHighByte(uint16_t address);
byte getMicrocodeLowByte(uint16_t address);

uint16_t getMicrocode(uint16_t address);

#endif
