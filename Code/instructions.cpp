#include "instructions.h"

#include "signals.h"

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

#define MC_START(inst) case Instruction::Type::inst: {
#define MI if (cycle-- == 0) return 
#define MC_END return 0; }

uint16_t Instruction::getMicrocode(uint8_t cycle) const {
  switch (type) {
    MC_START(SetPageReg)
      MI OUT(arg1) | IN(MADR) | MADR_BSELECT;
    MC_END
    MC_START(SetPageI)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
    MC_END
    MC_START(SetAddrReg)
      MI OUT(arg1) | IN(MADR);
    MC_END
    MC_START(SetAddrI)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
    MC_END
    
    MC_START(Load)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(arg1);
    MC_END
    MC_START(LoadI)
      MI OUT(PMEM) | IN(arg1) | PCNT_COUNT;
    MC_END
    MC_START(LoadP)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(arg1);
    MC_END
    MC_START(LoadInc)
      MI OUT(SRAM) | IN(arg1);
      MI arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0;
    MC_END
    MC_START(LoadStck)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;    // Set offset within stack frame.
      MI OUT(STCK) | IN(MADR) | MADR_BSELECT;  // Go to current stack frame.
      MI OUT(SRAM) | IN(arg1);                 // Copy value to register.
    MC_END

    MC_START(Store)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(arg1) | IN(SRAM);
    MC_END
    MC_START(StoreI)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(PMEM) | IN(SRAM) | PCNT_COUNT;
    MC_END
    MC_START(StoreP)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(arg1) | IN(SRAM);
    MC_END
    MC_START(StoreInc)
      MI OUT(arg1) | IN(SRAM);
      MI arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0;
    MC_END

    MC_START(StoreStck)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;        // Set offset within stack frame.
      MI OUT(STCK) | IN(MADR) | MADR_BSELECT;      // Go to current stack frame.
      MI OUT(arg1) | IN(SRAM);                     // Copy value to ram from register.
    MC_END
    MC_START(StoreNStck)
      MI OUT(STCK)  | IN(MADR);                    // Copy stack to memory address low byte.
      MI MADR_COUNT;                               // Increment stack.
      MI OUT(MADR)  | IN(SWAP);                    // Copy incremented stack to swap register.
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;      // Set offset within stack frame.
      MI OUT(SWAP)  | IN(MADR)  | MADR_BSELECT;    // Go to next stack frame.
      MI OUT(arg1)  | IN(SRAM);                    // Copy value to ram from register.
    MC_END
    MC_START(StorePStck)
      MI OUT(STCK)  | IN(REGA);                           // Copy stack to register A.
      MI OUT(PMEM)  | IN(REGB)  | PCNT_COUNT;             // Copy constant 1 to register B, and count.
      MI OUT(ALU)   | IN(MADR)  | ALU_SUB | MADR_BSELECT; // Go to previous stack frame.
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;             // Set offset within stack frame.
      MI OUT(arg1)  | IN(SRAM);                           // Copy value to ram from register.
    MC_END
    MC_START(StoreStckI)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;        // Set offset within stack frame.
      MI OUT(STCK) | IN(MADR) | MADR_BSELECT;      // Go to current stack frame.
      MI OUT(PMEM) | IN(SRAM) | PCNT_COUNT;        // Copy value to ram.
    MC_END
    MC_START(StoreNStckI)
      MI OUT(STCK)  | IN(MADR);                    // Copy stack to memory address low byte.
      MI MADR_COUNT;                               // Increment stack.
      MI OUT(MADR)  | IN(SWAP);                    // Copy incremented stack to swap register.
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;      // Set offset within stack frame.
      MI OUT(SWAP)  | IN(MADR)  | MADR_BSELECT;    // Go to next stack frame.
      MI OUT(PMEM)  | IN(SRAM)  | PCNT_COUNT;      // Copy value to ram.
    MC_END
    MC_START(StorePStckI)
      MI OUT(STCK)  | IN(REGA);                    // Copy stack to register A.
      MI OUT(PMEM)  | IN(REGB)  | PCNT_COUNT;      // Copy constant 1 to register B, and count.
      MI OUT(ALU)   | IN(MADR)  | MADR_BSELECT;    // Go to previous stack frame.
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;      // Set offset within stack frame.
      MI OUT(PMEM)  | IN(SRAM)  | PCNT_COUNT;      // Copy value to ram.
    MC_END
    
    MC_START(Copy)
      MI OUT(arg1) | IN(arg2) | arg3;
    MC_END

    MC_START(Jump)
      MI OUT(PMEM) | IN(SWAP) | PCNT_COUNT;
      MI OUT(PMEM) | IN(PCNT);
      MI OUT(SWAP) | IN(PCNT) | PCNT_BSELECT;
    MC_END

    MC_START(JumpReg)
      MI OUT(REGB) | IN(PCNT);
      MI OUT(REGA) | IN(PCNT) | PCNT_BSELECT;
    MC_END

    MC_START(JumpMem)
      MI OUT(SRAM) | IN(PCNT) | MADR_COUNT | PCNT_BSELECT;
      MI OUT(SRAM) | IN(PCNT);
    MC_END

    MC_START(Call) // Assumes a constant 0, and address to return to after the instruction in PMEM
      MI OUT(STCK)  | IN(MADR);                                // Copy stack to memory address low byte
      MI MADR_COUNT;                                           // Increment stack
      MI OUT(MADR)  | IN(STCK);                                // Copy incremented stack back to stack register
      MI OUT(STCK)  | IN(MADR)  | MADR_BSELECT;                // Go to new stack frame
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;                  // Go to 0 within stack, increment past 0 in progmem
      MI OUT(PMEM)  | IN(SRAM)  | PCNT_COUNT;                  // Write high byte to 0 within stack
      MI MADR_COUNT;                                           // Increment address within stack to 1
      MI OUT(PMEM)  | IN(SRAM)  | PCNT_COUNT;                  // Write low byte to 1 within stack
      // Jump to function:
      MI OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT;
      MI OUT(PMEM)  | IN(PCNT);
      MI OUT(SWAP)  | IN(PCNT)  | PCNT_BSELECT;
    MC_END
    MC_START(Return) // Assumes a constant 0 after the instruction in PMEM
      MI OUT(STCK)  | IN(MADR)  | MADR_BSELECT;              // Go to stack frame
      MI OUT(PMEM)  | IN(MADR)  | PCNT_COUNT;                // Go to 0 within stack frame
      MI OUT(SRAM)  | IN(PCNT)  | PCNT_BSELECT | MADR_COUNT; // Copy return address high byte, and count memory address to 1
      MI OUT(STCK)  | IN(REGA);                              // Copy stack into A
      MI OUT(MADR)  | IN(REGB);                              // Copy 1 to register B
      MI OUT(SRAM)  | IN(PCNT);                              // Go to return address low byte
      MI OUT(ALU)   | IN(STCK) | ALU_SUB;                    // Copy stack - 1 to stack register
    MC_END

    MC_START(CmpI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;     // Update flags
    MC_END
    MC_START(CmpAndI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI IN(ALU)    | OUT(ALU) | ALU_AND;    // Update flags
    MC_END
    MC_START(Cmp)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI IN(ALU)   | OUT(ALU) | ALU_SUB;                    // Update flags
    MC_END
    MC_START(CmpAnd)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI IN(ALU)   | OUT(ALU) | ALU_AND;                    // Update flags
    MC_END
    MC_START(CmpReg)
      MI OUT(arg1)  | IN(REGB);
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
    MC_END
    MC_START(CmpAndReg)
      MI OUT(arg1)  | IN(REGB);
      MI IN(ALU)    | OUT(ALU) | ALU_AND;    // Update flags
    MC_END
    MC_START(ShiftL)
      MI arg1 > 0 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 1 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 2 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 3 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 4 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 5 ? OUT(SHFT)  | IN(REGB) : 0;
      MI arg1 > 6 ? OUT(SHFT)  | IN(REGB) : 0;
    MC_END
    MC_START(ShiftR)
      MI arg1 > 0 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 1 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 2 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 3 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 4 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 5 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
      MI arg1 > 6 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0;
    MC_END
    MC_START(RotateL)
      MI arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
      MI arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0;
    MC_END
    MC_START(RotateR)
      MI arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
      MI arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0;
    MC_END
    MC_START(AddI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI IN(ALU)    | OUT(ALU);              // Update flags
      MI OUT(ALU)   | IN(REGA);
    MC_END
    MC_START(SubI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;
    MC_END
    MC_START(AndI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI IN(ALU)    | OUT(ALU) | ALU_AND;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_AND;
    MC_END
    MC_START(AddINF)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI OUT(ALU)   | IN(REGA);
    MC_END
    MC_START(SubINF)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;
    MC_END
    MC_START(AndINF)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;
      MI OUT(ALU)   | IN(REGA) | ALU_AND;
    MC_END
    MC_START(AccumulateAdd)
      MI IN(ALU)    | OUT(ALU);              // Update flags
      MI OUT(ALU)   | IN(REGA);
    MC_END
    MC_START(AccumulateSub)
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;
    MC_END
    MC_START(AccumulateAnd)
      MI IN(ALU)    | OUT(ALU) | ALU_AND;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_AND;
    MC_END
    MC_START(OrI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT; // Copy value to B
      MI OUT(ALU)   | IN(SWAP) | ALU_AND;    // A & B -> Swap
      MI OUT(ALU)   | IN(REGA);              // A + B -> A
      MI OUT(SWAP)  | IN(REGB);              // Swap -> B
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;    // (A + B) - (A & B) -> A
    MC_END
    MC_START(XorI)
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT; // Copy value to B
      MI OUT(ALU)   | IN(SWAP) | ALU_AND;    // A & B -> Swap
      MI OUT(ALU)   | IN(REGA);              // A + B -> A
      MI OUT(SWAP)  | IN(REGB);              // Swap -> B
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;    // (A + B) - (A & B) -> A
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;    // (A | B) - (A & B) -> A
    MC_END
    MC_START(Not)
      MI IN(MADR);                              // 0 -> MADR
      MI OUT(REGA)  | IN(REGB);                 // A -> B
      MI IN(REGA)   | MADR_COUNT;               // 0 -> A, MADR count to 1
      MI OUT(ALU)   | IN(REGA)    | ALU_SUB;    // 0 - B -> A
      MI OUT(MADR)  | IN(REGB);                 // 1 -> B
      MI IN(ALU)    | OUT(ALU)    | ALU_SUB;    // Update flags
      MI OUT(ALU)   | IN(REGA)    | ALU_SUB;    // (-A - 1) -> A
    MC_END
    MC_START(Add)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI IN(ALU)   | OUT(ALU);                             // Update flags
      MI OUT(ALU)  | IN(REGA);
    MC_END
    MC_START(Sub)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI IN(ALU)   | OUT(ALU) | ALU_SUB;                   // Update flags
      MI OUT(ALU)  | IN(REGA) | ALU_SUB;
    MC_END
    MC_START(And)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI IN(ALU)   | OUT(ALU) | ALU_AND;                   // Update flags
      MI OUT(ALU)  | IN(REGA) | ALU_AND;
    MC_END
    MC_START(Or)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI OUT(ALU)  | IN(SWAP) | ALU_AND;    // A & B -> Swap
      MI OUT(ALU)  | IN(REGA);              // A + B -> A
      MI OUT(SWAP) | IN(REGB);              // Swap -> B
      MI IN(ALU)   | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)  | IN(REGA) | ALU_SUB;     // (A + B) - (A & B) -> A
    MC_END
    MC_START(Xor)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(SRAM) | IN(REGB);
      MI OUT(ALU)  | IN(SWAP) | ALU_AND;    // A & B -> Swap
      MI OUT(ALU)  | IN(REGA);              // A + B -> A
      MI OUT(SWAP) | IN(REGB);              // Swap -> B
      MI OUT(ALU)  | IN(REGA) | ALU_SUB;    // (A + B) - (A & B) -> A
      MI IN(ALU)   | OUT(ALU) | ALU_SUB;    // Update flags
      MI OUT(ALU)  | IN(REGA) | ALU_SUB;     // (A | B) - (A & B) -> A
    MC_END
    MC_START(Nop)
      MI 0;
    MC_END
    MC_START(Nop1)
      MI IN(CLCK);
    MC_END
    MC_START(Nop2)
      MI IN(CLCK);
      MI IN(CLCK);
    MC_END
    MC_START(Halt)
      MI 0; // Handled elsewhere
    MC_END
  }
  return 0;
}
