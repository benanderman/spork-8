#include "instructions.h"

struct Instruction {
  uint16_t *microcode;
  byte len;
  byte flags_mask;
  byte data_bytes;
};

static uint16_t BASE[] = {
  OUT(PMEM) + INST_IN,
  PCNT_COUNT
};

static byte BASE_LEN = sizeof(BASE) / sizeof(*BASE);

static uint16_t LDAI[] = {
  OUT(PMEM) + IN(REGA) + PCNT_COUNT
};

static uint16_t LDBI[] = {
  OUT(PMEM) + IN(REGB) + PCNT_COUNT
};

static uint16_t LDCI[] = {
  OUT(PMEM) + IN(REGC) + PCNT_COUNT
};

static uint16_t LDA[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(SRAM) + IN(REGA)
};

static uint16_t LDB[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(SRAM) + IN(REGB)
};

static uint16_t LDC[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(SRAM) + IN(REGC)
};

static uint16_t STA[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(REGA) + IN(SRAM)
};

static uint16_t STB[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(REGB) + IN(SRAM)
};

static uint16_t STC[] = {
  OUT(PMEM) + IN(MADR) + MADR_BSELECT + PCNT_COUNT,
  OUT(PMEM) + IN(MADR) + PCNT_COUNT,
  OUT(REGC) + IN(SRAM)
};

static uint16_t RDIA[] = { // Read input B
  IN(INPA),
};

static uint16_t RDIB[] = { // Read input B
  IN(INPB),
};

static uint16_t TIAA[] = { // Transfer input A -> A
  OUT(INPA) + IN(REGA),
};

static uint16_t TIBA[] = { // Transfer input B -> A
  OUT(INPB) + IN(REGA),
};

static uint16_t ADDI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT + IN(ALU) + OUT(ALU), // Move past data, and update flags
  OUT(ALU) + IN(REGA)
};

static uint16_t SUBI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT + IN(ALU) + OUT(ALU) + ALU_SUB, // Move past data, and update flags
  OUT(ALU) + IN(REGA) + ALU_SUB
};

static uint16_t CMPI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT + IN(ALU) + OUT(ALU) + ALU_SUB // Move past data, and update flags
};

static uint16_t ANDI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT + IN(ALU) + OUT(ALU) + ALU_AND, // Move past data, and update flags
  OUT(ALU) + IN(REGA) + ALU_AND
};

static uint16_t ANDIA[] = { // INPA & A -> A
  OUT(INPA) + IN(REGB),
  IN(ALU) + OUT(ALU) + ALU_AND, // Update flags
  OUT(ALU) + IN(REGA) + ALU_AND
};

static uint16_t ANDIB[] = { // INPB & A -> A
  OUT(INPB) + IN(REGB),
  IN(ALU) + OUT(ALU) + ALU_AND, // Update flags
  OUT(ALU) + IN(REGA) + ALU_AND
};

static uint16_t JUMP[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

static uint16_t CALL[] = {
  IN(MADR) + MADR_BSELECT, // The stack is at (high byte) address 0x00, and the bus defaults to 0
  OUT(STCK) + IN(MADR),
  MADR_COUNT + IN(MADR) + MADR_BSELECT, // Make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(PCNT) + PCNT_BSELECT + IN(SRAM), // Copy more significant byte of instruction counter
  MADR_COUNT + IN(MADR) + MADR_BSELECT, // Make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(PCNT) + IN(SRAM), // Copy less significant byte of instruction counter
  OUT(MADR) + IN(STCK), // Copy stack address back to stack pointer after increments
  // Jump to function:
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

static uint16_t RET[] = {
  IN(MADR) + MADR_BSELECT, // Go to stack, at 0x00
  IN(MADR), // Start at 0, count to 1
  OUT(STCK) + IN(REGA) + MADR_COUNT, // Copy stack to register A, and count 1 at the same time
  OUT(MADR) + IN(REGB), // Copy 1 to REGB
  OUT(ALU) + ALU_SUB + IN(MADR), // Go to stack - 1
  OUT(SRAM) + IN(PCNT) + PCNT_BSELECT, // Copy more significant byte to instruction counter
  MADR_COUNT + IN(MADR) + MADR_BSELECT, // Go to stack - 0, and make sure that if we wrap around to 0, we don't end up at (high byte) 0x01
  OUT(SRAM) + IN(PCNT), // Copy less significant byte to instruction counter
  OUT(ALU) + IN(REGA), // Copy stack - 1 to A, to get stack - 2
  OUT(ALU) + IN(STCK) // Copy stack - 2 back to stack pointer after decrements (2 bytes were consumed)
};

static uint16_t JMPZ[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

static uint16_t JMPC[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

static uint16_t JMPNZ[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

static uint16_t JMPNC[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT),
  OUT(REGC) + IN(PCNT) + PCNT_BSELECT
};

// Temporary while REGC is actually a counter and there's no MADR
static uint16_t LDSI[] = {
  OUT(PMEM) + IN(REGC) + MADR_BSELECT + PCNT_COUNT
};

static uint16_t TAS[] = {
  OUT(REGA) + IN(REGC) + MADR_BSELECT
};

#define INSTRUCTION(inst, mask, data) {.microcode = inst, .len = sizeof(inst) / sizeof(*inst), .flags_mask = mask, .data_bytes = data}
#define UNCONDITIONAL 0b1111
#define NO_FLAGS      0b0001
#define CF            0b0010
#define ZF            0b0100
#define ZF_CF         0b1000

Instruction instructions[] = {
  INSTRUCTION(LDAI,  UNCONDITIONAL, 1),
  INSTRUCTION(LDBI,  UNCONDITIONAL, 1),
  INSTRUCTION(LDCI,  UNCONDITIONAL, 1),
  INSTRUCTION(LDA,   UNCONDITIONAL, 2),
  INSTRUCTION(LDB,   UNCONDITIONAL, 2),
  INSTRUCTION(LDC,   UNCONDITIONAL, 2),
  INSTRUCTION(STA,   UNCONDITIONAL, 2),
  INSTRUCTION(STB,   UNCONDITIONAL, 2),
  INSTRUCTION(STC,   UNCONDITIONAL, 2),
  INSTRUCTION(RDIA,  UNCONDITIONAL, 0),
  INSTRUCTION(RDIB,  UNCONDITIONAL, 0),
  INSTRUCTION(TIAA,  UNCONDITIONAL, 0),
  INSTRUCTION(TIBA,  UNCONDITIONAL, 0),
  INSTRUCTION(ADDI,  UNCONDITIONAL, 1),
  INSTRUCTION(SUBI,  UNCONDITIONAL, 1),
  INSTRUCTION(CMPI,  UNCONDITIONAL, 1),
  INSTRUCTION(ANDI,  UNCONDITIONAL, 1),
  INSTRUCTION(ANDIA, UNCONDITIONAL, 0),
  INSTRUCTION(ANDIB, UNCONDITIONAL, 0),
  INSTRUCTION(JUMP,  UNCONDITIONAL, 2),
  INSTRUCTION(CALL,  UNCONDITIONAL, 2),
  INSTRUCTION(RET,   UNCONDITIONAL, 0),
  INSTRUCTION(JMPZ,  ZF | ZF_CF,    2),
  INSTRUCTION(JMPC,  CF | ZF_CF,    2),
  INSTRUCTION(JMPNZ, CF | NO_FLAGS, 2),
  INSTRUCTION(JMPNC, ZF | NO_FLAGS, 2),
  INSTRUCTION(LDSI,  UNCONDITIONAL, 1),
  INSTRUCTION(TAS,   UNCONDITIONAL, 0)
};

uint16_t getMicrocode(uint16_t address) {
  byte mi = address & 0b001111;
  byte flags = 1 << ((address & 0b110000) >> 4);
  byte inst = address >> 6;

  if (mi < BASE_LEN) {
    return BASE[mi];
  }
  if (inst < sizeof(instructions) / sizeof(*instructions)) { // The instruction exists
    if (flags & instructions[inst].flags_mask) { // The instruction is active in these flag conditions
      if (mi - BASE_LEN < instructions[inst].len) { // We haven't gotten to the end of the instruction yet
        return instructions[inst].microcode[mi - BASE_LEN];
      }
    } else if (mi - BASE_LEN < instructions[inst].data_bytes) { // Skip past the data of the instruction if inactive
      return PCNT_COUNT; 
    }
  }
  return 0;
}

byte getMicrocodeHighByte(uint16_t address) {
  return getMicrocode(address) >> 8;
}

byte getMicrocodeLowByte(uint16_t address) {
  return getMicrocode(address) & 0xFF;
}

byte getTestProgramByte(uint16_t address) {
  byte program[] = {
    0,  1, // LDAI 1
    1,  33, // LDBI 33
    2,  65, // LDCI 65
    13, 2, // ADDI 2
    13, 4, // ADDI 4
    13, 8, // ADDI 8
    13, 16, // ADDI 16
    13, 32, // ADDI 32
    13, 64, // ADDI 64
    13, 128, // ADDI 128
    16, 0b10000001, // ANDI
    16, 0b01000010, // ANDI
    16, 0b00100100, // ANDI
    16, 0b00011000, // ANDI
    16, 0b00000000, // ANDI
    13, 2, // ADDI 2
    13, 4, // ADDI 4
    13, 8, // ADDI 8
    13, 16, // ADDI 16
    13, 32, // ADDI 32
    13, 64, // ADDI 64
    13, 128, // ADDI 128
    14, 2, // SUBI 2
    14, 4, // SUBI 4
    14, 8, // SUBI 8
    14, 16, // SUBI 16
    14, 32, // SUBI 32
    14, 64, // SUBI 64
    14, 128, // SUBI 128  ---- 29 * 2 = 58
    9,  // RDIA
    0,  0b10000000, // LDAI 128
    17, // ANDIA
    22, 0, 0, // JMPZ
    0,  64, // LDAI 64
    26, 0b00000000, // LDSI ---- 58 + 9 = 67
    26, 0b10000000, // LDSI
    26, 0b01000000, // LDSI
    26, 0b11000000, // LDSI
    14, 1, // SUBI 1
    24, 0, 67, // JMPNZ
    26, 0b00100000, // LDSI
    26, 0b00000000, // LDSI
    19, 0, 0, // JUMP 0
  };
  int len = sizeof(program) / sizeof(*program);
  return program[address % len];
}
