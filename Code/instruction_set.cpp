#include "instruction_set.h"
#include "instructions.h"
#include "signals.h"

uint8_t getMicrocodeHighByte(uint16_t address) {
  return getMicrocode(address) >> 8;
}

uint8_t getMicrocodeLowByte(uint16_t address) {
  return getMicrocode(address) & 0xFF;
}

#define INSTRUCTION if (index-- == 0) return Instruction

Instruction getInstruction(uint8_t index) {
  // const Instruction instructions[] = {
  INSTRUCTION(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGA);
  INSTRUCTION(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGB);
  INSTRUCTION(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC);
  INSTRUCTION(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP);
  INSTRUCTION(Instruction::Type::SetPageI,   Instruction::FlagsMask::UNCONDITIONAL, 1);

  INSTRUCTION(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGA);
  INSTRUCTION(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGB);
  INSTRUCTION(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC);
  INSTRUCTION(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP);
  INSTRUCTION(Instruction::Type::SetAddrI,   Instruction::FlagsMask::UNCONDITIONAL, 1);

  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGA);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGB);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, REGC);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, SWAP);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, OUTA);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, IOA);
  INSTRUCTION(Instruction::Type::Load,      Instruction::FlagsMask::UNCONDITIONAL, 2, IOB);

  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, IOA);
  INSTRUCTION(Instruction::Type::LoadI,     Instruction::FlagsMask::UNCONDITIONAL, 1, IOB);

  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, IOA);
  INSTRUCTION(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, IOB);

  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 0);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 0);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 0);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 0);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 0);

  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 1);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 1);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 1);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 1);
  INSTRUCTION(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 1);

  INSTRUCTION(Instruction::Type::LoadStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::LoadStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::LoadStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);
  INSTRUCTION(Instruction::Type::LoadStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP);
  INSTRUCTION(Instruction::Type::LoadStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA);

  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGA);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGB);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, REGC);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, SWAP);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, OUTA);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, IOA);
  INSTRUCTION(Instruction::Type::Store,     Instruction::FlagsMask::UNCONDITIONAL, 2, IOB);

  INSTRUCTION(Instruction::Type::StoreI,    Instruction::FlagsMask::UNCONDITIONAL, 3);

  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, IOA);
  INSTRUCTION(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, IOB);

  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, IOA,  0);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, IOB,  0);

  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, IOA,  1);
  INSTRUCTION(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, IOB,  1);

  INSTRUCTION(Instruction::Type::StoreStck,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::StoreStck,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::StoreStck,   Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);
  INSTRUCTION(Instruction::Type::StoreStck,   Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP);

  INSTRUCTION(Instruction::Type::StoreNStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGA);
  INSTRUCTION(Instruction::Type::StoreNStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGB);
  INSTRUCTION(Instruction::Type::StoreNStck,  Instruction::FlagsMask::UNCONDITIONAL, 1, REGC);

  INSTRUCTION(Instruction::Type::StorePStck,  Instruction::FlagsMask::UNCONDITIONAL, CONST_ONE 2, REGC);

  INSTRUCTION(Instruction::Type::StoreStckI,  Instruction::FlagsMask::UNCONDITIONAL, TWO_VALUES 2);

  INSTRUCTION(Instruction::Type::StoreNStckI, Instruction::FlagsMask::UNCONDITIONAL, TWO_VALUES 2);

  INSTRUCTION(Instruction::Type::StorePStckI, Instruction::FlagsMask::UNCONDITIONAL, CONST_ONE TWO_VALUES 3);

  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, REGB);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, REGC);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, SWAP);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, STCK);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, OUTA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, IOA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, IOB);

  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, STCK, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, IOA,  REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, IOB,  REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, PCNT, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, PCNT, REGA, PCNT_BSELECT);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, MADR, REGA);
  INSTRUCTION(Instruction::Type::Copy,      Instruction::FlagsMask::UNCONDITIONAL, 0, MADR, REGA, MADR_BSELECT);

  INSTRUCTION(Instruction::Type::Jump,      Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::Jump,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Jump,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Jump,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::Jump,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::Call,      Instruction::FlagsMask::UNCONDITIONAL, CONST_ZERO CONST_NEXT_ADDR 5);
  INSTRUCTION(Instruction::Type::Call,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, CONST_ZERO CONST_NEXT_ADDR 5);
  INSTRUCTION(Instruction::Type::Call,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, CONST_ZERO CONST_NEXT_ADDR 5);
  INSTRUCTION(Instruction::Type::Call,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, CONST_ZERO CONST_NEXT_ADDR 5);
  INSTRUCTION(Instruction::Type::Call,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, CONST_ZERO CONST_NEXT_ADDR 5);

  INSTRUCTION(Instruction::Type::Return,    Instruction::FlagsMask::UNCONDITIONAL, CONST_ZERO 1);
  INSTRUCTION(Instruction::Type::Return,    Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, CONST_ZERO 1);
  INSTRUCTION(Instruction::Type::Return,    Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, CONST_ZERO 1);
  INSTRUCTION(Instruction::Type::Return,    Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, CONST_ZERO 1);
  INSTRUCTION(Instruction::Type::Return,    Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, CONST_ZERO 1);

  INSTRUCTION(Instruction::Type::CmpI,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::CmpAndI,   Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::Cmp,       Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::CmpAnd,    Instruction::FlagsMask::UNCONDITIONAL, 2);

  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, REGC);
  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP);
  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, STCK);
  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA);
  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, IOA);
  INSTRUCTION(Instruction::Type::CmpReg,    Instruction::FlagsMask::UNCONDITIONAL, 0, IOB);

  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC);
  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP);
  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, STCK);
  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA);
  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, IOA);
  INSTRUCTION(Instruction::Type::CmpAndReg, Instruction::FlagsMask::UNCONDITIONAL, 0, IOB);

  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 1);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 2);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 3);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 4);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 5);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 6);
  INSTRUCTION(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 7);

  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 1);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 2);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 3);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 4);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 5);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 6);
  INSTRUCTION(Instruction::Type::ShiftR,    Instruction::FlagsMask::UNCONDITIONAL, 0, 7);

  INSTRUCTION(Instruction::Type::RotateL,   Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::RotateR,   Instruction::FlagsMask::UNCONDITIONAL, 0);

  INSTRUCTION(Instruction::Type::AddI,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::AddI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AddI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AddI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::AddI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::SubI,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::SubI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::SubI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::SubI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::SubI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::AndI,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::AndI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AndI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AndI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::AndI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::AddINF,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::AddINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AddINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AddINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::AddINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::SubINF,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::SubINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::SubINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::SubINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::SubINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::AndINF,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::AndINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AndINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::AndINF,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::AndINF,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::AccumulateAdd, Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::AccumulateSub, Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::AccumulateAnd, Instruction::FlagsMask::UNCONDITIONAL, 0);

  INSTRUCTION(Instruction::Type::OrI,       Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::OrI,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::OrI,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::OrI,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::OrI,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::XorI,      Instruction::FlagsMask::UNCONDITIONAL, 1);
  INSTRUCTION(Instruction::Type::XorI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::XorI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1);
  INSTRUCTION(Instruction::Type::XorI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1);
  INSTRUCTION(Instruction::Type::XorI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1);

  INSTRUCTION(Instruction::Type::Not,       Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::Not,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 0);
  INSTRUCTION(Instruction::Type::Not,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 0);
  INSTRUCTION(Instruction::Type::Not,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 0);
  INSTRUCTION(Instruction::Type::Not,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 0);

  INSTRUCTION(Instruction::Type::Add,       Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::Add,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Add,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Add,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::Add,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::Sub,       Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::Sub,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Sub,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Sub,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::Sub,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::And,       Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::And,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::And,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::And,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::And,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::Or,        Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::Or,        Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Or,        Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Or,        Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::Or,        Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::Xor,       Instruction::FlagsMask::UNCONDITIONAL, 2);
  INSTRUCTION(Instruction::Type::Xor,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Xor,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2);
  INSTRUCTION(Instruction::Type::Xor,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2);
  INSTRUCTION(Instruction::Type::Xor,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2);

  INSTRUCTION(Instruction::Type::Nop,       Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::Nop1,      Instruction::FlagsMask::UNCONDITIONAL, 0);
  INSTRUCTION(Instruction::Type::Nop2,      Instruction::FlagsMask::UNCONDITIONAL, 0);

  INSTRUCTION(Instruction::Type::Halt,      Instruction::FlagsMask::UNCONDITIONAL, 0);
  // };

  return Instruction(Instruction::Type::Nop, Instruction::FlagsMask::UNCONDITIONAL, 0);
  // const Instruction noop = Instruction(Instruction::Type::Nop, Instruction::FlagsMask::UNCONDITIONAL, 0);
  // return index < sizeof(instructions) / sizeof(*instructions) ? instructions[index] : noop;
}

uint16_t getMicrocode(uint16_t address) {
  uint8_t mi = address & 0b001111;
  uint8_t flags = 1 << ((address & 0b110000) >> 4);
  uint8_t inst = address >> 6;

  const Instruction instruction = getInstruction(inst);
  return instruction.microCodeForCycleFlags(mi, flags);
}
