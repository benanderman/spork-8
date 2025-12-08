#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include "instructions.h"

uint8_t getMicrocodeHighByte(uint16_t address);
uint8_t getMicrocodeLowByte(uint16_t address);

uint16_t getMicrocode(uint16_t address);
Instruction getInstruction(uint8_t index);

#endif
