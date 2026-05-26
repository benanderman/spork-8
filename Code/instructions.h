#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#ifndef uint8_t
// #define uint8_t unsigned char
typedef unsigned char uint8_t;
#endif
#ifndef uint16_t
// #define uint16_t unsigned short
typedef unsigned int uint16_t;
#endif

// Marks an instruction as assuming a constant 0 or 1 value after it.
#define CONST_ZERO 
#define CONST_ONE 

// Marks an instruction as assuming its address + data bytes + 1 after it (comes after consts above).
#define CONST_NEXT_ADDR 

class Instruction {
  public:

  enum FlagsMask : uint8_t {
    UNCONDITIONAL = 0b1111,
    NO_FLAGS      = 0b0001,
    CF            = 0b0010,
    ZF            = 0b0100,
    ZF_CF         = 0b1000,
  };

  enum Type : uint8_t {
    SetPageReg,      // Set the memory address high byte to a register value.
    SetPageI,        // Set the memory address high byte to a constant value.
    SetAddrReg,      // Set the memory address low byte to a register value.
    SetAddrI,        // Set the memory address low byte to a constant value.
    Load,            // Load a value from a constant address into a register.
    LoadI,           // Load a constant value into a register.
    LoadP,           // Load a value from a constant address (setting low byte only) into a register.
    LoadInc,         // Load a value from the currently set memory address into a register, and increment the address n times.
    LoadStck,        // Load a value from an offset on the current stack frame into a register.
    Store,           // Store a value to a constant address from a register.
    StoreI,          // Store a constant value into a constant address.
    StoreP,          // Store a value to a constant address (low byte only) from a register.
    StoreInc,        // Store a value from the currently set memory address from a register, and increment the address n times.
    StoreStck,       // Store a value to an offset on the current stack frame, from a register.
    StoreNStck,      // Store a value to an offset on the next stack frame, from a register.
    StorePStck,      // Store a value to an offset on the previous stack frame, from a register.
    StoreStckI,      // Store a constant value to an offset on the current stack frame.
    StoreNStckI,     // Store a constant value to an offset on the next stack frame.
    StorePStckI,     // Store a constant value to an offset on the previous stack frame.
    Copy,            // Copy a value from one register to another register.
    Jump,            // Jump to a constant location.
    JumpReg,         // Jump to a register A (high byte) + register B (low byte).
    JumpMem,         // Jump to a location pointed to by memory at the current memory address (high byte first).
    Call,            // Call a function.
    Return,          // Return from a function.
    CmpI,            // Compare A to a constant value (sets flags, but discards result).
    CmpAndI,         // Compare A to a constant value with bitwise AND (sets flags, but discards result).
    Cmp,             // Compare A to a value from memory (sets flags, but discards result).
    CmpAnd,          // Compare A to a value in memory with bitwise AND (sets flags, but discards result).
    CmpReg,          // Compare A to a value from a register (sets flags, but discards result).
    CmpAndReg,       // Compare A to a value from a register with bitwise AND (sets flags, but discards result).
    ShiftL,          // Shift B left by 1.
    ShiftR,          // Shift B right by 1.
    RotateL,         // Rotate B left by 1.
    RotateR,         // Rotate B right by 1.
    AddI,            // Add a constant value to A.
    SubI,            // Subtract a constant value from A.
    AndI,            // Bitwise-AND A with a constant value.
    AddINF,          // Add a constant value to A, without updating flags.
    SubINF,          // Subtract a constant value from A, without updating flags.
    AndINF,          // Bitwise-AND A with a constant value, without updating flags.
    AccumulateAdd,   // Add register B to A -> A.
    AccumulateSub,   // Subtract register B from A -> A.
    AccumulateAnd,   // A & B -> A.
    OrI,             // Bitwise OR B with A -> A.
    XorI,            // Bitwise OR a constant value with A -> A.
    Not,             // Invert register A.
    Add,             // Add a value from memory to A.
    Sub,             // Subtract a value from memory from A.
    And,             // AND A with a value from memory.
    Or,              // OR A with a value from memory.
    Xor,             // XOR A with a value from memory.
    Nop,             // No-op.
    Nop1,            // No-op with 1 extra clock cycle.
    Nop2,            // No-op with 2 extra clock cycles.
    Halt,            // Halt - stop the program forever (until reset).
  };

  const Type type;
  const uint8_t flags_mask;
  const uint8_t data_bytes;
  const uint8_t arg1;
  const uint8_t arg2;
  const uint8_t arg3;
  
  Instruction(Type type, uint8_t flags_mask, uint8_t data_bytes, uint8_t arg1 = 0, uint8_t arg2 = 0, uint8_t arg3 = 0);
  uint16_t microCodeForCycleFlags(uint8_t cycle, uint8_t flags) const;

  private:
  uint16_t getMicrocode(uint8_t cycle) const;
};

#endif
