#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <Arduino.h>

class Instruction {
  public:

  enum FlagsMask : byte {
    UNCONDITIONAL = 0b1111,
    NO_FLAGS      = 0b0001,
    CF            = 0b0010,
    ZF            = 0b0100,
    ZF_CF         = 0b1000,
  };

  enum Type : byte {
    Load,
    LoadI,
    LoadZP,
    LoadN,
    Store,
    StoreI,
    StoreZP,
    StoreN,
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
    AddI,
    SubI,
    AndI,
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
  const byte flags_mask;
  const byte data_bytes;
  const uint16_t arg1;
  const uint16_t arg2;
  const uint16_t arg3;
  
  Instruction(Type type, byte flags_mask, byte data_bytes, uint16_t arg1 = 0, uint16_t arg2 = 0, uint16_t arg3 = 0);
  uint16_t microCodeForCycleFlags(byte cycle, byte flags) const;

  private:
  uint16_t getMicrocode(byte cycle) const;
};

#endif
