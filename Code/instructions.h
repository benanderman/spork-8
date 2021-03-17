#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "signals.h"

int BASE[] = {
  OUT(PMEM) + INST_IN,
  PCNT_COUNT
};

int JUMP[] = {
  OUT(PMEM) + IN(REGD),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT) + PCNT_BSELECT,
  OUT(REGD) + IN(PCNT)
};

int CALL[] = {
  IN(MADR), // The stack is at (high byte) address 0x00, and the bus defaults to 0
  OUT(STCK) + IN(MADR) + MADR_BSELECT,
  MADR_COUNT,
  IN(MADR), // Make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(PCNT) + IN(SRAM), // Copy more significant byte of instruction counter
  MADR_COUNT,
  IN(MADR), // Make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(PCNT) + IN(SRAM) + PCNT_BSELECT, // Copy less significant byte of instruction counter
  OUT(MADR) + IN(STCK) + MADR_BSELECT // Copy stack address back to stack pointer after increments
};

int RET[] = {
  IN(MADR), // Go to stack, at 0x00
  IN(MADR) + MADR_BSELECT, // Start at 0, count to 2
  OUT(STCK) + IN(REGA) + MADR_COUNT, // Copy stack to register A, and count 1 of the 2 at the same time
  MADR_COUNT,
  OUT(MADR) + IN(REGB) + MADR_BSELECT, // Copy 2 to REGB
  OUT(ALU) + IN(MADR) + MADR_BSELECT, // Go to stack - 2
  OUT(SRAM) + IN(PCNT), // Copy more significant byte to instruction counter
  MADR_COUNT, // Go to stack - 1
  IN(MADR), // Make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(SRAM) + IN(PCNT) + PCNT_BSELECT, // Copy less significant byte to instruction counter
  OUT(ALU) + IN(STCK) // Copy stack address back to stack pointer after decrements
};

#endif
