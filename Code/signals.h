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
 | Outer top left (12, 13)     | Outer bus | Outer top right (12, 13)     |
 | Outer bottom left (14, 15)  |           | Outer bottom right (14, 15)  |
 | Inner top left (12, 13)     | Inner bus | Inner top right (12, 13)     |
 | Inner bottom left (14, 15)  |           | Inner bottom right (14, 15)  |

*/

// Bottom
#define ZERO 0b0000 // Inner top left
#define INDX 0b0001 // Inner bottom left
#define STCK 0b0010 // Inner top right
#define SRAM 0b0011 // Inner bottom right
#define REGE 0b0100 // Outer top left
#define INPA 0b0101 // Outer bottom left
#define MADR 0b0110 // Outer top right
#define INPB 0b0111 // Outer bottom right

// Top
#define CLCK 0b1000 // Inner top left
#define REGD 0b1001 // Inner bottom left
#define REGB 0b1010 // Inner top right
#define REGC 0b1011 // Inner bottom right
#define PCNT 0b1100 // Outer top left
#define PMEM 0b1101 // Outer bottom left
#define REGA 0b1110 // Outer top right
#define ALU  0b1111 // Outer bottom right

// Other signals; these are signals 8-15, which are least significant, so they start at 8 and go in reverse order
#define PCNT_COUNT   0b10000000 // 8
#define PCNT_BSELECT 0b01000000 // 9
#define ALU_SUB      0b00100000 // 10
#define ALU_AND      0b00010000 // 11
#define MADR_COUNT   0b00001000 // 12
#define MADR_BSELECT 0b00000100 // 13
// #define UNUSED    0b00000010 // 14
#define INST_IN      0b00000001 // 15

// Utils
// A micro-instruction can be made up of: IN(register) + OUT(register) + [other signals]
#define IN(reg)        (reg << 12)
#define OUT(reg)       (reg <<  8)
#define FLAGS_OUT(reg) IN(reg) // Only for ALU

#endif
