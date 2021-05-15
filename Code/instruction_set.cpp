#include "instruction_set.h"
#include "instructions.h"
#include "signals.h"

byte getMicrocodeHighByte(uint16_t address) {
  return getMicrocode(address) >> 8;
}

byte getMicrocodeLowByte(uint16_t address) {
  return getMicrocode(address) & 0xFF;
}

static Instruction instructions[] = {
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGA),
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGB),
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGC),
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, SWAP),
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, OUTA),
  Instruction(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, OUTB),
  
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGA),
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGB),
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGC),
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP),
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA),
  Instruction(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTB),
  
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGA),
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGB),
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGC),
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP),
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA),
  Instruction(Instruction::Type::LoadZP,    Instruction::FlagsMask::UNCONDITIONAL, 1, OUTB),
  
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA),
  Instruction(Instruction::Type::LoadN,     Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB),
  
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGA),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGB),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGC),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, SWAP),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, OUTA),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, OUTB),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, INPA),
  Instruction(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, INPB),
  
  Instruction(Instruction::Type::StoreI,    Instruction::FlagsMask::UNCONDITIONAL, 3),
  
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGA),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGB),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGC),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, OUTB),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, INPA),
  Instruction(Instruction::Type::StoreZP,   Instruction::FlagsMask::UNCONDITIONAL, 1, INPB),
  
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, INPA),
  Instruction(Instruction::Type::StoreN,    Instruction::FlagsMask::UNCONDITIONAL, 0, INPB),
  
  Instruction(Instruction::Type::Read,      Instruction::FlagsMask::UNCONDITIONAL, 0, INPA),
  Instruction(Instruction::Type::Read,      Instruction::FlagsMask::UNCONDITIONAL, 0, INPB),
  
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, REGB),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, REGC),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, SWAP),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, STCK),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, OUTA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, OUTB),
  
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, STCK, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, INPA, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, INPB, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, PCNT, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, PCNT, REGA, PCNT_BSELECT),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, MADR, REGA),
  Instruction(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, MADR, REGA, MADR_BSELECT),
  
  Instruction(Instruction::Type::Jump,      Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::Jump,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
  Instruction(Instruction::Type::Jump,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
  Instruction(Instruction::Type::Jump,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
  Instruction(Instruction::Type::Jump,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
  
  Instruction(Instruction::Type::Call,      Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::Call,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
  Instruction(Instruction::Type::Call,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
  Instruction(Instruction::Type::Call,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
  Instruction(Instruction::Type::Call,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
  
  Instruction(Instruction::Type::Return,    Instruction::FlagsMask::UNCONDITIONAL, 0),
  
  Instruction(Instruction::Type::Push,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
  Instruction(Instruction::Type::Push,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
  Instruction(Instruction::Type::Push,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  
  Instruction(Instruction::Type::Pop,       Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
  Instruction(Instruction::Type::Pop,       Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
  Instruction(Instruction::Type::Pop,       Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  
  Instruction(Instruction::Type::PushAll,   Instruction::FlagsMask::UNCONDITIONAL, 0),
  Instruction(Instruction::Type::PopAll,    Instruction::FlagsMask::UNCONDITIONAL, 0),
  
  Instruction(Instruction::Type::CmpI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::CmpAndI,   Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::Cmp,       Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::CmpAnd,    Instruction::FlagsMask::UNCONDITIONAL, 2),
  
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, STCK),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, INPA),
  Instruction(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, INPB),
  
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, STCK),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, INPA),
  Instruction(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, INPB),
  
  Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::UNCONDITIONAL, 1),
  Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
  
  Instruction(Instruction::Type::Not,       Instruction::FlagsMask::UNCONDITIONAL, 0),
  
  Instruction(Instruction::Type::Add,       Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::And,       Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::Or,        Instruction::FlagsMask::UNCONDITIONAL, 2),
  Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::UNCONDITIONAL, 2),
  
  Instruction(Instruction::Type::Nop,       Instruction::FlagsMask::UNCONDITIONAL, 0),
  Instruction(Instruction::Type::Nop1,      Instruction::FlagsMask::UNCONDITIONAL, 0),
  Instruction(Instruction::Type::Nop2,      Instruction::FlagsMask::UNCONDITIONAL, 0),
  
  Instruction(Instruction::Type::Halt,      Instruction::FlagsMask::UNCONDITIONAL, 0),
};

uint16_t getMicrocode(uint16_t address) {
  byte mi = address & 0b001111;
  byte flags = 1 << ((address & 0b110000) >> 4);
  byte inst = address >> 6;

  if (inst < sizeof(instructions) / sizeof(*instructions)) { // The instruction exists
    return instructions[inst].microCodeForCycleFlags(mi, flags);
  }
  return 0;
}
