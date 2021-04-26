#include "instructions.h"


static uint16_t BASE[] = {
  OUT(PMEM) + INST_IN,
  PCNT_COUNT
};

static byte BASE_LEN = sizeof(BASE) / sizeof(*BASE);

static uint16_t LDAI[] = {
  OUT(PMEM) + IN(REGA),
  PCNT_COUNT
};

static uint16_t LDBI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT
};

static uint16_t LDCI[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT
};

static uint16_t ADDI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT,
  OUT(ALU) + IN(REGA)
};

static uint16_t SUBI[] = {
  OUT(PMEM) + IN(REGB),
  PCNT_COUNT,
  OUT(ALU) + IN(REGA) + ALU_SUB
};

static uint16_t ANDI[] = {
  OUT(PMEM) + IN(REGB) + PCNT_COUNT,
  OUT(ALU) + IN(REGA) + ALU_AND
};

static uint16_t JUMP[] = {
  OUT(PMEM) + IN(REGC),
  PCNT_COUNT,
  OUT(PMEM) + IN(PCNT) + PCNT_BSELECT,
  OUT(REGC) + IN(PCNT)
};

static uint16_t CALL[] = {
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

static uint16_t RET[] = {
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

static uint16_t *INSTRUCTIONS[] = {
  LDAI,
  LDBI,
  LDCI,
  ADDI,
  SUBI,
  ANDI,
  JUMP,
  CALL,
  RET
};

static byte INSTRUCTION_LENGTHS[] = {
  sizeof(LDAI) / sizeof(*LDAI),
  sizeof(LDBI) / sizeof(*LDBI),
  sizeof(LDCI) / sizeof(*LDCI),
  sizeof(ADDI) / sizeof(*ADDI),
  sizeof(SUBI) / sizeof(*SUBI),
  sizeof(ANDI) / sizeof(*ANDI),
  sizeof(JUMP) / sizeof(*JUMP),
  sizeof(CALL) / sizeof(*CALL),
  sizeof(RET) / sizeof(*RET)
};

uint16_t getMicrocode(uint16_t address) {
  byte mi = address & 0b001111;
  bool zf = address & 0b010000;
  bool cf = address & 0b100000;
  byte inst = address >> 6;

  if (mi < BASE_LEN) {
    return BASE[mi];
  }
  if (inst < sizeof(INSTRUCTIONS) / sizeof(*INSTRUCTIONS)) {
    if (mi - BASE_LEN < INSTRUCTION_LENGTHS[inst]) {
      return INSTRUCTIONS[inst][mi - BASE_LEN];
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
    0, 1, // LDAI 1
    1, 33, // LDBI 33
    2, 65, // LDCI 65
    3, 2, // ADDI 2
    3, 4, // ADDI 4
    3, 8, // ADDI 8
    3, 16, // ADDI 16
    3, 32, // ADDI 32
    3, 64, // ADDI 64
    3, 128, // ADDI 128
    5, 0b10000001, // ANDI
    5, 0b01000010, // ANDI
    5, 0b00100100, // ANDI
    5, 0b00011000, // ANDI
    5, 0b00000000, // ANDI
    3, 2, // ADDI 2
    3, 4, // ADDI 4
    3, 8, // ADDI 8
    3, 16, // ADDI 16
    3, 32, // ADDI 32
    3, 64, // ADDI 64
    3, 128, // ADDI 128
    4, 2, // SUBI 2
    4, 4, // SUBI 4
    4, 8, // SUBI 8
    4, 16, // SUBI 16
    4, 32, // SUBI 32
    4, 64, // SUBI 64
    4, 128, // SUBI 128
    6, 0, 4, // JUMP 3
  };
  int len = sizeof(program) / sizeof(*program);
  return program[address % len];
}
