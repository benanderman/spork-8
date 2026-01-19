#include "instructions.h"

#include "signals.h"

// #undef uint8_t
// #undef uint16_t
// #undef bool
// #include <iostream>

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))

#ifndef PROGMEM
#define PROGMEM 
#endif

#ifndef pgm_read_word
#define pgm_read_word(arg) (*arg)
#endif

Instruction::Instruction(Type type, uint8_t flags_mask, uint8_t data_bytes, uint8_t arg1, uint8_t arg2, uint8_t arg3) :
  type(type), data_bytes(data_bytes), flags_mask(flags_mask), arg1(arg1), arg2(arg2), arg3(arg3) {
  
}

uint16_t Instruction::microCodeForCycleFlags(uint8_t cycle, uint8_t flags) const {
  static const uint16_t base_microcode[] = {
    OUT(PMEM) | INST_IN,
    PCNT_COUNT // Has to be its own micro-instruction, because INST_IN happens on ~CLOCK.
  };
  static const uint8_t base_len = sizeof(base_microcode) / sizeof(*base_microcode);

  if (cycle < base_len) {
    if (type == Instruction::Type::Halt && cycle == 1) {
      // printf("Returning halt\n");
      return 0 | MI_RESET | INST_IN; // For halt, we want to not advance the program counter, so it's run over and over forever
    }
    // printf("Returning base inst %d\n", cycle);
    return base_microcode[cycle] ^ INST_IN;
  }

  uint16_t result = 0;
  if (flags & flags_mask) { // The instruction is active in these flag conditions
    result = getMicrocode(cycle - base_len);
    // printf("Returning microcode %d for type %d\n", cycle - base_len, (int)type);
  } else if (cycle - base_len < data_bytes) { // Skip past the data of the instruction if inactive
    // printf("Returning non-applying microcode for %d\n", (int)type);
    result = PCNT_COUNT;
  }
  return (result == 0 ? MI_RESET : result) ^ INST_IN;
}

#define MC_START(inst) case Instruction::Type::inst: { uint16_t mi[] = {
#define MC_END }; return cycle < ARRAY_LEN(mi) ? mi[cycle] : 0; }

// Use progmem, for instructions that don't use arguments
#define MC_START_PM(inst) case Instruction::Type::inst: { static const uint16_t mi_pm[] PROGMEM = {
#define MC_END_PM }; return cycle < ARRAY_LEN(mi_pm) ? pgm_read_word(&mi_pm[cycle]) : 0; }

uint16_t Instruction::getMicrocode(uint8_t cycle) const {
  switch (type) {
    MC_START(SetPageReg)
      static_cast<uint16_t>(OUT(arg1) | IN(MADR) | MADR_BSELECT)
    MC_END
    MC_START_PM(SetPageI)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT
    MC_END_PM
    MC_START(SetAddrReg)
      static_cast<uint16_t>(OUT(arg1) | IN(MADR))
    MC_END
    MC_START_PM(SetAddrI)
      OUT(PMEM) | IN(MADR) | PCNT_COUNT
    MC_END_PM
    
    MC_START(Load)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(SRAM) | IN(arg1))
    MC_END
    MC_START(LoadI)
      static_cast<uint16_t>(OUT(PMEM) | IN(arg1) | PCNT_COUNT)
    MC_END
    MC_START(LoadZP)
      IN(MADR) | MADR_BSELECT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(SRAM) | IN(arg1))
    MC_END
    MC_START(LoadP)
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(SRAM) | IN(arg1))
    MC_END
    MC_START(LoadInc)
      static_cast<uint16_t>(OUT(SRAM) | IN(arg1)),
      static_cast<uint16_t>(arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0)
    MC_END

    MC_START(Store)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(arg1) | IN(SRAM))
    MC_END
    MC_START_PM(StoreI)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(PMEM) | IN(SRAM) | PCNT_COUNT
    MC_END_PM
    MC_START(StoreZP)
      IN(MADR) | MADR_BSELECT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(arg1) | IN(SRAM))
    MC_END
    MC_START(StoreP)
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      static_cast<uint16_t>(OUT(arg1) | IN(SRAM))
    MC_END
    MC_START(StoreInc)
      static_cast<uint16_t>(OUT(arg1) | IN(SRAM)),
      static_cast<uint16_t>(arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0)
    MC_END
    
    MC_START(Read)
      IN(arg1)
    MC_END
    
    MC_START(Copy)
      static_cast<uint16_t>(OUT(arg1) | IN(arg2) | arg3)
    MC_END

    MC_START_PM(Jump)
      OUT(PMEM) | IN(SWAP) | PCNT_COUNT,
      OUT(PMEM) | IN(PCNT),
      OUT(SWAP) | IN(PCNT) + PCNT_BSELECT
    MC_END_PM

    MC_START_PM(Call) // Assumes a constant 1 after the instruction in PMEM
      OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT,                  // Copy 1 to SWAP
      OUT(SWAP)  | IN(MADR)  | MADR_BSELECT,                // Go to the stack at (high byte) 0x01
      OUT(STCK)  | IN(MADR),                                // Go to location within stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      OUT(PCNT)  | IN(SRAM)  | PCNT_BSELECT,                // Copy more significant byte of instruction counter
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 2, and write 0x01 to high byte to prevent overflow
      OUT(PCNT)  | IN(SRAM),                                // Copy less significant byte of instruction counter
      OUT(MADR)  | IN(STCK),                                // Copy stack address back to stack pointer after increments
      // Jump to function:
      OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT,
      OUT(PMEM)  | IN(PCNT),
      OUT(SWAP)  | IN(PCNT)  | PCNT_BSELECT
    MC_END_PM
    MC_START_PM(Return) // Assumes a constant 1 after the instruction in PMEM
      OUT(STCK)  | IN(REGA),                          // Copy stack to register A
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,             // Copy 1 to register B
      OUT(REGB)  | IN(MADR) | MADR_BSELECT,           // Go to stack, at high byte 0x01
      OUT(ALU)   | IN(MADR) | ALU_SUB,                // Go to stack - 1
      OUT(SRAM)  | IN(PCNT) | PCNT_BSELECT,           // Copy more significant byte to instruction counter
      OUT(STCK)  | IN(MADR),                          // Go to stack - 0
      OUT(SRAM)  | IN(PCNT),                          // Copy less significant byte to instruction counter
      OUT(ALU)   | IN(REGA) | ALU_SUB | PCNT_COUNT,   // Copy stack - 1 to A, to get stack - 2; skip past data byte 1 of Call*
      OUT(ALU)   | IN(STCK) | ALU_SUB | PCNT_COUNT    // Copy stack - 2 back to stack pointer after decrements (2 bytes were consumed); skip past data byte 2 of Call*
    MC_END_PM
    MC_START(Push) // Assumes a constant 1 after the instruction in PMEM
      OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT,                  // Copy 1 to SWAP
      OUT(SWAP)  | IN(MADR)  | MADR_BSELECT,                // Go to the stack at (high byte) 0x01
      OUT(STCK)  | IN(MADR),                                // Go to location within stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      static_cast<uint16_t>(OUT(arg1)  | IN(SRAM)),         // Write register to stack
      OUT(MADR)  | IN(STCK)                                 // Write new stack pointer back to STCK
    MC_END
    MC_START(Pop) // Assumes a constant 1 after the instruction in PMEM
      OUT(STCK)  | IN(REGA),                         // Copy stack to register A
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,            // Copy 1 to register B
      OUT(REGB)  | IN(MADR) | MADR_BSELECT,          // Go to stack, at high byte 0x01
      OUT(STCK)  | IN(MADR),                         // Go to stack pointer
      static_cast<uint16_t>(OUT(SRAM)  | IN(arg1)),  // Copy value to register
      OUT(ALU)   | IN(STCK) | ALU_SUB                // Copy stack - 1 back to stack pointer
    MC_END
    MC_START_PM(PushAll) // Assumes a constant 1 after the instruction in PMEM
      MADR_COUNT,                                           // Count to 1
      OUT(MADR)  | IN(SWAP),                                // Copy 1 to SWAP
      OUT(SWAP)  | IN(MADR)  | MADR_BSELECT,                // Go to the stack at (high byte) 0x01
      OUT(STCK)  | IN(MADR),                                // Go to location within stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      OUT(REGA)  | IN(SRAM),                                // Write register A to stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 2, and write 0x01 to high byte to prevent overflow
      OUT(REGB)  | IN(SRAM),                                // Write register B to stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 3, and write 0x01 to high byte to prevent overflow
      OUT(REGC)  | IN(SRAM),                                // Write register C to stack
      OUT(MADR)  | IN(STCK)                                 // Write new stack pointer back to STCK
    MC_END_PM
    MC_START_PM(PopAll) // Assumes a constant 1 after the instruction in PMEM
      OUT(STCK)  | IN(REGA) | MADR_COUNT,                   // Copy stack to register A, and count to 1
      OUT(MADR)  | IN(REGB),                                // Copy 1 to register B
      OUT(MADR)  | IN(SWAP),                                // Copy 1 to swap
      OUT(REGB)  | IN(MADR) | MADR_BSELECT,                 // Go to stack, at high byte 0x01
      OUT(ALU)   | IN(REGA) | ALU_SUB,                      // -1
      OUT(ALU)   | IN(MADR) | ALU_SUB,                      // Go to stack - 2
      OUT(ALU)   | IN(REGA) | ALU_SUB,                      // Put stack - 2 into REGA
      OUT(ALU)   | IN(STCK) | ALU_SUB,                      // Copy stack - 3 back to stack pointer
      OUT(SRAM)  | IN(REGA),                                // Copy value of stack - 2 to register A
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack - 1, and write 0x01 to high byte to prevent overflow
      OUT(SRAM)  | IN(REGB),                                // Copy value of stack - 1 to register B, go to stack - 0
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack - 0, and write 0x01 to high byte to prevent overflow
      OUT(SRAM)  | IN(REGC)                                 // Copy value of stack - 0 to register C
    MC_END_PM
    MC_START_PM(CmpI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_SUB     // Update flags
    MC_END_PM
    MC_START_PM(CmpAndI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_AND    // Update flags
    MC_END_PM
    MC_START_PM(Cmp)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_SUB                    // Update flags
    MC_END_PM
    MC_START_PM(CmpAnd)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_AND                    // Update flags
    MC_END_PM
    MC_START(CmpReg)
      static_cast<uint16_t>(OUT(arg1)  | IN(REGB)),
      IN(ALU)    | OUT(ALU) | ALU_SUB    // Update flags
    MC_END
    MC_START(CmpAndReg)
      static_cast<uint16_t>(OUT(arg1)  | IN(REGB)),
      IN(ALU)    | OUT(ALU) | ALU_AND    // Update flags
    MC_END
    MC_START(Mult)
      static_cast<uint16_t>(arg1 > 0 ? OUT(REGA)  | IN(REGB) : IN(REGA)), // Multiply by 0 = 0
      static_cast<uint16_t>(arg1 > 0 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 1 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 2 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 3 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 4 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 5 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 6 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 7 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 8 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 9 ? OUT(ALU)   | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 10 ? OUT(ALU)  | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 11 ? OUT(ALU)  | IN(REGA) : 0),
      static_cast<uint16_t>(arg1 > 12 ? OUT(ALU)  | IN(REGA) : 0)
    MC_END
    MC_START(ShiftL)
      static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | IN(REGB) : 0)
    MC_END
    MC_START(ShiftR)
      static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0)
    MC_END
    MC_START(RotateL)
      static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0)
    MC_END
    MC_START(RotateR)
      static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0),
      static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0)
    MC_END
    MC_START_PM(AddI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU),              // Update flags
      OUT(ALU)   | IN(REGA)
    MC_END_PM
    MC_START_PM(SubI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB
    MC_END_PM
    MC_START_PM(AndI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_AND,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_AND
    MC_END_PM
    MC_START_PM(AddINF)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      OUT(ALU)   | IN(REGA)
    MC_END_PM
    MC_START_PM(SubINF)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      OUT(ALU)   | IN(REGA) | ALU_SUB
    MC_END_PM
    MC_START_PM(AndINF)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      OUT(ALU)   | IN(REGA) | ALU_AND
    MC_END_PM
    MC_START_PM(AccumulateAdd)
      IN(ALU)    | OUT(ALU),              // Update flags
      OUT(ALU)   | IN(REGA)
    MC_END_PM
    MC_START_PM(AccumulateSub)
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB
    MC_END_PM
    MC_START_PM(AccumulateAnd)
      IN(ALU)    | OUT(ALU) | ALU_AND,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_AND
    MC_END_PM
    MC_START_PM(OrI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT, // Copy value to B
      OUT(ALU)   | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)   | IN(REGA),              // A + B -> A
      OUT(SWAP)  | IN(REGB),              // Swap -> B
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB     // (A + B) - (A & B) -> A
    MC_END_PM
    MC_START_PM(XorI)
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT, // Copy value to B
      OUT(ALU)   | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)   | IN(REGA),              // A + B -> A
      OUT(SWAP)  | IN(REGB),              // Swap -> B
      OUT(ALU)   | IN(REGA) | ALU_SUB,    // (A + B) - (A & B) -> A
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB     // (A | B) - (A & B) -> A
    MC_END_PM
    MC_START_PM(Not)
      IN(MADR),                              // 0 -> MADR
      OUT(REGA)  | IN(REGB),                 // A -> B
      IN(REGA)   | MADR_COUNT,               // 0 -> A, MADR count to 1
      OUT(ALU)   | IN(REGA)    | ALU_SUB,    // 0 - B -> A
      OUT(MADR)  | IN(REGB),                 // 1 -> B
      IN(ALU)    | OUT(ALU)    | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA)    | ALU_SUB     // (-A - 1) -> A
    MC_END_PM
    MC_START_PM(Add)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU),                             // Update flags
      OUT(ALU)  | IN(REGA)
    MC_END_PM
    MC_START_PM(Sub)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_SUB,                   // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB
    MC_END_PM
    MC_START_PM(And)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_AND,                   // Update flags
      OUT(ALU)  | IN(REGA) | ALU_AND
    MC_END_PM
    MC_START_PM(Or)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      OUT(ALU)  | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)  | IN(REGA),              // A + B -> A
      OUT(SWAP) | IN(REGB),              // Swap -> B
      IN(ALU)   | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB     // (A + B) - (A & B) -> A
    MC_END_PM
    MC_START_PM(Xor)
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      OUT(ALU)  | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)  | IN(REGA),              // A + B -> A
      OUT(SWAP) | IN(REGB),              // Swap -> B
      OUT(ALU)  | IN(REGA) | ALU_SUB,    // (A + B) - (A & B) -> A
      IN(ALU)   | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB     // (A | B) - (A & B) -> A
    MC_END_PM
    MC_START_PM(Nop)
      0
    MC_END_PM
    MC_START_PM(Nop1)
      IN(CLCK)
    MC_END_PM
    MC_START_PM(Nop2)
      IN(CLCK),
      IN(CLCK)
    MC_END_PM
    MC_START_PM(Halt)
      0 // Handled elsewhere
    MC_END_PM
  }
  return 0;
}
