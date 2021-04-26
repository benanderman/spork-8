#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "signals.h"

#include <Arduino.h>

uint16_t getMicrocode(uint16_t address);
byte getMicrocodeHighByte(uint16_t address);
byte getMicrocodeLowByte(uint16_t address);

#endif
