#ifndef SIGNALS_H
#define SIGNALS_H
// Modules

/* Module layout, with extra signals
 
 | Outer top left (8, 9)       | Outer bus | Outer top right (8, 9)       |
 | Outer bottom left (10, 11)  |           | Outer bottom right (10, 11)  |
 | Inner top left (8, 9)       | Inner bus | Inner top right (8, 9)       |
 | Inner bottom left (10, 11)  |           | Inner bottom right (10, 11)  |
                               |-----------|
                               | Control   |
                               | Module    |
                               |-----------|
 | Inner top left (12, 13)     | Inner bus | Inner top right (12, 13)     |
 | Inner bottom left (14, 15)  |           | Inner bottom right (14, 15)  |
 | Outer top left (12, 13)     | Outer bus | Outer top right (12, 13)     |
 | Outer bottom left (14, 15)  |           | Outer bottom right (14, 15)  |

*/

// Bottom
#define ZERO (uint16_t)0b0000 // Inner top left
#define STCK (uint16_t)0b1000 // Inner bottom left
#define OUTA (uint16_t)0b0100 // Inner top right
#define SRAM (uint16_t)0b1100 // Inner bottom right
#define SWAP (uint16_t)0b0010 // Outer top left
#define IOA  (uint16_t)0b1010 // Outer bottom left
#define MADR (uint16_t)0b0110 // Outer top right
#define IOB  (uint16_t)0b1110 // Outer bottom right

// Top
#define CLCK (uint16_t)0b0001 // Inner top left
#define REGC (uint16_t)0b1001 // Inner bottom left
#define REGB (uint16_t)0b0101 // Inner top right
#define SHFT (uint16_t)0b1101 // Inner bottom right
#define PCNT (uint16_t)0b0011 // Outer top left
#define PMEM (uint16_t)0b1011 // Outer bottom left
#define REGA (uint16_t)0b0111 // Outer top right
#define ALU  (uint16_t)0b1111 // Outer bottom right

// Other signals; these are signals 8-15, which are least significant, so they start at 8 and go in reverse order
#define PCNT_COUNT   (uint16_t)0b00000001 // 8
#define PCNT_BSELECT (uint16_t)0b00000010 // 9
#define ALU_SUB      (uint16_t)0b00000100 // 10
#define ALU_AND      (uint16_t)0b00001000 // 11
#define SHIFT_RIGHT  (uint16_t)0b00000100 // 10
#define SHIFT_ROTATE (uint16_t)0b00001000 // 11
#define MADR_COUNT   (uint16_t)0b00010000 // 12
#define MADR_BSELECT (uint16_t)0b00100000 // 13
#define MI_RESET     (uint16_t)0b01000000 // 14
#define INST_IN      (uint16_t)0b10000000 // 15

// Utils
// A micro-instruction can be made up of: IN(register) + OUT(register) + [other signals]
#define OUT(reg)       (uint16_t)((uint16_t)reg << 12)
#define IN(reg)        (uint16_t)((uint16_t)reg <<  8)
#define FLAGS_OUT(reg) IN(reg) // Only for ALU

#endif
