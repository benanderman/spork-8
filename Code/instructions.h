#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#ifndef uint8_t
#define uint8_t unsigned char
#endif
#ifndef uint16_t
#define uint16_t unsigned short
#endif

// Marks an instruction as assuming a constant 0 or 1 value after it.
#define CONST_ZERO(value) value
#define CONST_ONE(value) value

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
    SetPageReg,
    SetPageI,
    SetAddrReg,
    SetAddrI,
    Load,
    LoadI,
    LoadZP,
    LoadP,
    LoadInc,
    Store,
    StoreI,
    StoreZP,
    StoreP,
    StoreInc,
    Read,
    Copy,
    Jump,
    Call,
    Return,
    Push,
    Pop,
    PushAll,
    PopAll,
    CmpI,
    CmpAndI,
    Cmp,
    CmpAnd,
    CmpReg,
    CmpAndReg,
    Mult,
    ShiftL,
    ShiftR,
    RotateL,
    RotateR,
    AddI,
    SubI,
    AndI,
    AddINF, // No flags update.
    SubINF, // No flags update.
    AndINF, // No flags update.
    AccumulateAdd,
    AccumulateSub,
    AccumulateAnd,
    OrI,
    XorI,
    Not,
    Add,
    Sub,
    And,
    Or,
    Xor,
    Nop,
    Nop1,
    Nop2,
    Halt,
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
