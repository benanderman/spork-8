#include "instructions.h"

#include "signals.h"

#define ARRAY_LEN(arr) (sizeof(arr) / sizeof(*arr))

Instruction::Instruction(Type type, byte flags_mask, byte data_bytes, uint16_t arg1, uint16_t arg2, uint16_t arg3) :
  type(type), data_bytes(data_bytes), flags_mask(flags_mask), arg1(arg1), arg2(arg2), arg3(arg3) {
  
}

uint16_t Instruction::microCodeForCycleFlags(byte cycle, byte flags) {
  static const uint16_t base_microcode[] = {
    OUT(PMEM) + INST_IN,
    PCNT_COUNT
  };
  static const byte base_len = sizeof(base_microcode) / sizeof(*base_microcode);

  if (cycle < base_len) {
    if (type == Instruction::Type::Halt && cycle == 1) {
      return 0; // For halt, we want to not advance the program counter, so it's run over and over forever
    }
    return base_microcode[cycle];
  }
  if (flags & flags_mask) { // The instruction is active in these flag conditions
    return getMicrocode(cycle - base_len);
  } else if (cycle - base_len < data_bytes) { // Skip past the data of the instruction if inactive
    return PCNT_COUNT; 
  }
  return 0;
}

#define MICROCODE_CASE(inst, microcode) case inst: { static uint16_t mi[] = {microcode}; return cycle < ARRAY_LEN(mi) ? mi[cycle] : 0; }

uint16_t Instruction::getMicrocode(byte cycle) {
  switch (type) {
    MICROCODE_CASE(Instruction::Type::Load, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(arg1)
    ));
    MICROCODE_CASE(Instruction::Type::LoadI, (
      OUT(PMEM) | IN(arg1) | PCNT_COUNT
    ));
    MICROCODE_CASE(Instruction::Type::LoadZP, (
      IN(MADR) | MADR_BSELECT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(arg1)
    ));
    MICROCODE_CASE(Instruction::Type::LoadN, (
      MADR_COUNT,
      OUT(SRAM) | IN(arg1)
    ));

    MICROCODE_CASE(Instruction::Type::Store, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(arg1) | IN(SRAM)
    ));
    MICROCODE_CASE(Instruction::Type::StoreI, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(PMEM) | IN(SRAM) | PCNT_COUNT
    ));
    MICROCODE_CASE(Instruction::Type::StoreZP, (
      IN(MADR) | MADR_BSELECT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(arg1) | IN(SRAM)
    ));
    MICROCODE_CASE(Instruction::Type::StoreN, (
      MADR_COUNT,
      OUT(arg1) | IN(SRAM)
    ));
    
    MICROCODE_CASE(Instruction::Type::Read, (
      IN(arg1)
    ));
    
    MICROCODE_CASE(Instruction::Type::Copy, (
      OUT(arg1) | IN(arg2) | arg3
    ));

    MICROCODE_CASE(Instruction::Type::Jump, (
      OUT(PMEM) | IN(SWAP) | PCNT_COUNT,
      OUT(PMEM) | IN(PCNT),
      OUT(SWAP) | IN(PCNT) + PCNT_BSELECT
    ));

    MICROCODE_CASE(Instruction::Type::Call, (
      IN(MADR),                                             // Start at 0
      MADR_COUNT,                                           // Count to 1
      OUT(MADR)  | IN(SWAP),                                // Copy 1 to SWAP
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
    ));
    MICROCODE_CASE(Instruction::Type::Return, (
      IN(MADR),                             // Start at 0
      OUT(STCK)  | IN(REGA) | MADR_COUNT,   // Copy stack to register A, and count to 1
      OUT(MADR)  | IN(REGB),                // Copy 1 to register B
      OUT(REGB)  | IN(MADR) | MADR_BSELECT, // Go to stack, at high byte 0x01
      OUT(ALU)   | IN(MADR) | ALU_SUB,      // Go to stack - 1
      OUT(SRAM)  | IN(PCNT) | PCNT_BSELECT, // Copy more significant byte to instruction counter
      OUT(STCK)  | IN(MADR),                // Go to stack - 0
      OUT(SRAM)  | IN(PCNT),                // Copy less significant byte to instruction counter
      OUT(ALU)   | IN(REGA),                // Copy stack - 1 to A, to get stack - 2
      OUT(ALU)   | IN(STCK)                 // Copy stack - 2 back to stack pointer after decrements (2 bytes were consumed)
    ));
    MICROCODE_CASE(Instruction::Type::Push, (
      IN(MADR),                                             // Start at 0
      MADR_COUNT,                                           // Count to 1
      OUT(MADR)  | IN(SWAP),                                // Copy 1 to SWAP
      OUT(SWAP)  | IN(MADR)  | MADR_BSELECT,                // Go to the stack at (high byte) 0x01
      OUT(STCK)  | IN(MADR),                                // Go to location within stack
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack + 1, and write 0x01 to high byte to prevent overflow
      OUT(arg1)  | IN(SRAM),                                // Write register to stack
      OUT(MADR)  | IN(STCK)                                 // Write new stack pointer back to STCK
    ));
    MICROCODE_CASE(Instruction::Type::Pop, (
      IN(MADR),                             // Start at 0
      OUT(STCK)  | IN(REGA) | MADR_COUNT,   // Copy stack to register A, and count to 1
      OUT(MADR)  | IN(REGB),                // Copy 1 to register B
      OUT(REGB)  | IN(MADR) | MADR_BSELECT, // Go to stack, at high byte 0x01
      OUT(STCK)  | IN(MADR),                // Go to stack pointer
      OUT(SRAM)  | IN(arg1),                // Copy value to register
      OUT(ALU)   | IN(STCK) | ALU_SUB       // Copy stack - 1 back to stack pointer
    ));
    MICROCODE_CASE(Instruction::Type::PushAll, (
      IN(MADR),                                             // Start at 0
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
    ));
    MICROCODE_CASE(Instruction::Type::PopAll, (
      IN(MADR),                                             // Start at 0
      OUT(STCK)  | IN(REGA) | MADR_COUNT,                   // Copy stack to register A, and count to 1
      OUT(MADR)  | IN(REGB),                                // Copy 1 to register B
      OUT(MADR)  | IN(SWAP),                                // Copy 1 to swap
      OUT(REGB)  | IN(MADR) | MADR_BSELECT,                 // Go to stack, at high byte 0x01
      OUT(ALU)   | IN(REGA) | ALU_SUB,                      // -1
      OUT(ALU)   | IN(MADR) | ALU_SUB,                      // Go to stack - 2
      OUT(ALU)   | IN(REGA) | ALU_SUB,                      // Put stack - 2 into REGA
      OUT(MADR)  | IN(STCK) | ALU_SUB,                      // Copy stack - 3 back to stack pointer
      OUT(SRAM)  | IN(REGA),                                // Copy value of stack - 2 to register A
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack - 1, and write 0x01 to high byte to prevent overflow
      OUT(SRAM)  | IN(REGB),                                // Copy value of stack - 1 to register B, go to stack - 0
      MADR_COUNT | OUT(SWAP) | IN(MADR)     | MADR_BSELECT, // Go to stack - 0, and write 0x01 to high byte to prevent overflow
      OUT(SRAM)  | IN(REGC)                                 // Copy value of stack - 0 to register C
    ));
    MICROCODE_CASE(Instruction::Type::CmpI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_SUB     // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::CmpAndI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_AND    // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::Cmp, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_SUB                    // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::CmpAnd, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_AND                    // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::CmpReg, (
      OUT(arg1)  | IN(REGB),
      IN(ALU)    | OUT(ALU) | ALU_SUB    // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::CmpAndReg, (
      OUT(arg1)  | IN(REGB),
      IN(ALU)    | OUT(ALU) | ALU_AND    // Update flags
    ));
    MICROCODE_CASE(Instruction::Type::AddI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU),              // Update flags
      OUT(ALU)   | IN(REGA)
    ));
    MICROCODE_CASE(Instruction::Type::SubI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA)
    ));
    MICROCODE_CASE(Instruction::Type::AndI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT,
      IN(ALU)    | OUT(ALU) | ALU_AND,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_AND
    ));
    MICROCODE_CASE(Instruction::Type::OrI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT, // Copy value to B
      OUT(ALU)   | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)   | IN(REGA),              // A + B -> A
      OUT(SWAP)  | IN(REGB),              // Swap -> B
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB     // (A + B) - (A & B) -> A
    ));
    MICROCODE_CASE(Instruction::Type::XorI, (
      OUT(PMEM)  | IN(REGB) | PCNT_COUNT, // Copy value to B
      OUT(ALU)   | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)   | IN(REGA),              // A + B -> A
      OUT(SWAP)  | IN(REGB),              // Swap -> B
      OUT(ALU)   | IN(REGA) | ALU_SUB,    // (A + B) - (A & B) -> A
      IN(ALU)    | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA) | ALU_SUB     // (A | B) - (A & B) -> A
    ));
    MICROCODE_CASE(Instruction::Type::Not, (
      IN(MADR),                              // 0 -> MADR
      OUT(REGA)  | IN(REGB),                 // A -> B
      IN(REGA)   | MADR_COUNT,               // 0 -> A, MADR count to 1
      OUT(ALU)   | IN(REGA),                 // 0 - B -> A
      OUT(MADR)  | IN(REGB),                 // 1 -> B
      IN(ALU)    | OUT(ALU)    | ALU_SUB,    // Update flags
      OUT(ALU)   | IN(REGA)    | ALU_SUB     // (-A - 1) -> A
    ));
    MICROCODE_CASE(Instruction::Type::Add, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU),                             // Update flags
      OUT(ALU)  | IN(REGA)
    ));
    MICROCODE_CASE(Instruction::Type::Sub, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_SUB,                   // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB
    ));
    MICROCODE_CASE(Instruction::Type::And, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      IN(ALU)   | OUT(ALU) | ALU_AND,                   // Update flags
      OUT(ALU)  | IN(REGA) | ALU_AND
    ));
    MICROCODE_CASE(Instruction::Type::Or, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      OUT(ALU)  | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)  | IN(REGA),              // A + B -> A
      OUT(SWAP) | IN(REGB),              // Swap -> B
      IN(ALU)   | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB     // (A + B) - (A & B) -> A
    ));
    MICROCODE_CASE(Instruction::Type::Xor, (
      OUT(PMEM) | IN(MADR) | MADR_BSELECT | PCNT_COUNT,
      OUT(PMEM) | IN(MADR) | PCNT_COUNT,
      OUT(SRAM) | IN(REGB),
      OUT(ALU)  | IN(SWAP) | ALU_AND,    // A & B -> Swap
      OUT(ALU)  | IN(REGA),              // A + B -> A
      OUT(SWAP) | IN(REGB),              // Swap -> B
      OUT(ALU)  | IN(REGA) | ALU_SUB,    // (A + B) - (A & B) -> A
      IN(ALU)   | OUT(ALU) | ALU_SUB,    // Update flags
      OUT(ALU)  | IN(REGA) | ALU_SUB     // (A | B) - (A & B) -> A
    ));
    MICROCODE_CASE(Instruction::Type::Nop, (
      0
    ));
    MICROCODE_CASE(Instruction::Type::Nop1, (
      IN(CLCK)
    ));
    MICROCODE_CASE(Instruction::Type::Nop2, (
      IN(CLCK),
      IN(CLCK)
    ));
    MICROCODE_CASE(Instruction::Type::Halt, (
      0 // Handled elsewhere
    ));
  }
  return 0;
}
