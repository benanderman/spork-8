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
      MI static_cast<uint16_t>(OUT(arg1) | IN(MADR) | MADR_BSELECT);
    MC_END
    MC_START(SetPageI)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
    MC_END
    MC_START(SetAddrReg)
      MI static_cast<uint16_t>(OUT(arg1) | IN(MADR));
    MC_END
    MC_START(SetAddrI)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
    MC_END
    
    MC_START(Load)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(SRAM) | IN(arg1));
    MC_END
    MC_START(LoadI)
      MI static_cast<uint16_t>(OUT(PMEM) | IN(arg1) | PCNT_COUNT);
    MC_END
    MC_START(LoadZP)
      MI IN(MADR) | MADR_BSELECT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(SRAM) | IN(arg1));
    MC_END
    MC_START(LoadP)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(SRAM) | IN(arg1));
    MC_END
    MC_START(LoadInc)
      MI static_cast<uint16_t>(OUT(SRAM) | IN(arg1));
      MI static_cast<uint16_t>(arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0);
    MC_END

    MC_START(Store)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(arg1) | IN(SRAM));
    MC_END
    MC_START(StoreI)
      MI OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI OUT(PMEM) | IN(SRAM) | PCNT_COUNT;
    MC_END
    MC_START(StoreZP)
      MI IN(MADR) | MADR_BSELECT;
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(arg1) | IN(SRAM));
    MC_END
    MC_START(StoreP)
      MI OUT(PMEM) | IN(MADR) | PCNT_COUNT;
      MI static_cast<uint16_t>(OUT(arg1) | IN(SRAM));
    MC_END
    MC_START(StoreInc)
      MI static_cast<uint16_t>(OUT(arg1) | IN(SRAM));
      MI static_cast<uint16_t>(arg2 > 0 ? (uint16_t)(MADR_COUNT) : 0);
    MC_END
    
    MC_START(Read)
      MI IN(arg1);
    MC_END
    
    MC_START(Copy)
      MI static_cast<uint16_t>(OUT(arg1) | IN(arg2) | arg3);
    MC_END

    MC_START(Jump)
      MI OUT(PMEM) | IN(SWAP) | PCNT_COUNT;
      MI OUT(PMEM) | IN(PCNT);
      MI OUT(SWAP) | IN(PCNT) + PCNT_BSELECT;
    MC_END

    MC_START(Call) // Assumes a constant 1 after the instruction in PMEM
      MI OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT;                  // Copy 1 to SWAP
      MI OUT(SWAP)  | IN(MADR)  | MADR_BSELECT;                // Go to the stack at (high byte) 0x01
      MI OUT(STCK)  | IN(MADR);                                // Go to location within stack
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack + 1; and write 0x01 to high byte to prevent overflow
      MI OUT(PCNT)  | IN(SRAM)  | PCNT_BSELECT;                // Copy more significant byte of instruction counter
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack + 2; and write 0x01 to high byte to prevent overflow
      MI OUT(PCNT)  | IN(SRAM);                                // Copy less significant byte of instruction counter
      MI OUT(MADR)  | IN(STCK);                                // Copy stack address back to stack pointer after increments
      // Jump to function:
      MI OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT;
      MI OUT(PMEM)  | IN(PCNT);
      MI OUT(SWAP)  | IN(PCNT)  | PCNT_BSELECT;
    MC_END
    MC_START(Return) // Assumes a constant 1 after the instruction in PMEM
      MI OUT(STCK)  | IN(REGA);                          // Copy stack to register A
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;             // Copy 1 to register B
      MI OUT(REGB)  | IN(MADR) | MADR_BSELECT;           // Go to stack; at high byte 0x01
      MI OUT(ALU)   | IN(MADR) | ALU_SUB;                // Go to stack - 1
      MI OUT(SRAM)  | IN(PCNT) | PCNT_BSELECT;           // Copy more significant byte to instruction counter
      MI OUT(STCK)  | IN(MADR);                          // Go to stack - 0
      MI OUT(SRAM)  | IN(PCNT);                          // Copy less significant byte to instruction counter
      MI OUT(ALU)   | IN(REGA) | ALU_SUB | PCNT_COUNT;   // Copy stack - 1 to A, to get stack - 2; skip past data byte 1 of Call*
      MI OUT(ALU)   | IN(STCK) | ALU_SUB | PCNT_COUNT;   // Copy stack - 2 back to stack pointer after decrements (2 bytes were consumed); skip past data byte 2 of Call*
    MC_END
    MC_START(Push) // Assumes a constant 1 after the instruction in PMEM
      MI OUT(PMEM)  | IN(SWAP)  | PCNT_COUNT;                  // Copy 1 to SWAP
      MI OUT(SWAP)  | IN(MADR)  | MADR_BSELECT;                // Go to the stack at (high byte) 0x01
      MI OUT(STCK)  | IN(MADR);                                // Go to location within stack
      MI MADR_COUNT | OUT(SWAP) | IN(MADR) | MADR_BSELECT;     // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      MI static_cast<uint16_t>(OUT(arg1)   | IN(SRAM));        // Write register to stack
      MI OUT(MADR)  | IN(STCK);                                // Write new stack pointer back to STCK
    MC_END
    MC_START(Pop) // Assumes a constant 1 after the instruction in PMEM
      MI OUT(STCK)  | IN(REGA);                         // Copy stack to register A
      MI OUT(PMEM)  | IN(REGB) | PCNT_COUNT;            // Copy 1 to register B
      MI OUT(REGB)  | IN(MADR) | MADR_BSELECT;          // Go to stack, at high byte 0x01
      MI OUT(STCK)  | IN(MADR);                         // Go to stack pointer
      MI static_cast<uint16_t>(OUT(SRAM)  | IN(arg1));  // Copy value to register
      MI OUT(ALU)   | IN(STCK) | ALU_SUB;               // Copy stack - 1 back to stack pointer
    MC_END
    MC_START(PushAll) // Assumes a constant 1 after the instruction in PMEM
      MI MADR_COUNT;                                           // Count to 1
      MI OUT(MADR)  | IN(SWAP);                                // Copy 1 to SWAP
      MI OUT(SWAP)  | IN(MADR)  | MADR_BSELECT;                // Go to the stack at (high byte) 0x01
      MI OUT(STCK)  | IN(MADR);                                // Go to location within stack
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      MI OUT(REGA)  | IN(SRAM);                                // Write register A to stack
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack + 2, and write 0x01 to high byte to prevent overflow
      MI OUT(REGB)  | IN(SRAM);                                // Write register B to stack
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack + 3, and write 0x01 to high byte to prevent overflow
      MI OUT(REGC)  | IN(SRAM);                                // Write register C to stack
      MI OUT(MADR)  | IN(STCK);                                // Write new stack pointer back to STCK
    MC_END
    MC_START(PopAll) // Assumes a constant 1 after the instruction in PMEM
      MI OUT(STCK)  | IN(REGA) | MADR_COUNT;                   // Copy stack to register A, and count to 1
      MI OUT(MADR)  | IN(REGB);                                // Copy 1 to register B
      MI OUT(MADR)  | IN(SWAP);                                // Copy 1 to swap
      MI OUT(REGB)  | IN(MADR) | MADR_BSELECT;                 // Go to stack, at high byte 0x01
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;                      // -1
      MI OUT(ALU)   | IN(MADR) | ALU_SUB;                      // Go to stack - 2
      MI OUT(ALU)   | IN(REGA) | ALU_SUB;                      // Put stack - 2 into REGA
      MI OUT(ALU)   | IN(STCK) | ALU_SUB;                      // Copy stack - 3 back to stack pointer
      MI OUT(SRAM)  | IN(REGA);                                // Copy value of stack - 2 to register A
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack - 1, and write 0x01 to high byte to prevent overflow
      MI OUT(SRAM)  | IN(REGB);                                // Copy value of stack - 1 to register B, go to stack - 0
      MI MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT; // Go to stack - 0, and write 0x01 to high byte to prevent overflow
      MI OUT(SRAM)  | IN(REGC);                                // Copy value of stack - 0 to register C
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
      MI static_cast<uint16_t>(OUT(arg1)  | IN(REGB));
      MI IN(ALU)    | OUT(ALU) | ALU_SUB;    // Update flags
    MC_END
    MC_START(CmpAndReg)
      MI static_cast<uint16_t>(OUT(arg1)  | IN(REGB));
      MI IN(ALU)    | OUT(ALU) | ALU_AND;    // Update flags
    MC_END
    MC_START(ShiftL)
      MI static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | IN(REGB) : 0);
    MC_END
    MC_START(ShiftR)
      MI static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_RIGHT  | IN(REGB) : 0);
    MC_END
    MC_START(RotateL)
      MI static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | IN(REGB) : 0);
    MC_END
    MC_START(RotateR)
      MI static_cast<uint16_t>(arg1 > 0 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 1 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 2 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 3 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 4 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 5 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
      MI static_cast<uint16_t>(arg1 > 6 ? OUT(SHFT)  | SHIFT_ROTATE | SHIFT_RIGHT | IN(REGB) : 0);
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
