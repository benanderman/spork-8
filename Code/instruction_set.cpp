#include "instruction_set.h"
#include "instructions.h"
#include "signals.h"

byte getMicrocodeHighByte(uint16_t address) {
  return getMicrocode(address) >> 8;
}

byte getMicrocodeLowByte(uint16_t address) {
  return getMicrocode(address) & 0xFF;
}

Instruction getInstruction(byte index) {
  const Instruction instructions[] = {
    Instruction(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
    Instruction(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
    Instruction(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
    Instruction(Instruction::Type::SetPageReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
    Instruction(Instruction::Type::SetPageI,   Instruction::FlagsMask::UNCONDITIONAL, 1),
    
    Instruction(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGA),
    Instruction(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGB),
    Instruction(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, REGC),
    Instruction(Instruction::Type::SetAddrReg, Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP),
    Instruction(Instruction::Type::SetAddrI,   Instruction::FlagsMask::UNCONDITIONAL, 1),
    
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
    
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGA),
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGB),
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, REGC),
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP),
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA),
    Instruction(Instruction::Type::LoadP,     Instruction::FlagsMask::UNCONDITIONAL, 1, OUTB),
    
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 0),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 0),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 0),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 0),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 0),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB, 0),
    
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 1),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 1),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 1),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 1),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 1),
    Instruction(Instruction::Type::LoadInc,   Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB, 1),
    
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
    
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGA),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGB),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, REGC),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, SWAP),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, OUTA),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, OUTB),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, INPA),
    Instruction(Instruction::Type::StoreP,    Instruction::FlagsMask::UNCONDITIONAL, 1, INPB),
    
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, INPA, 0),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, INPB, 0),
    
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGA, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGB, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, REGC, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, SWAP, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTA, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, OUTB, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, INPA, 1),
    Instruction(Instruction::Type::StoreInc,  Instruction::FlagsMask::UNCONDITIONAL, 0, INPB, 1),
    
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
  
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 0),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 1),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 2),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 3),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 4),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 5),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 6),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 7),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 8),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 9),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 10),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 11),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 12),
    Instruction(Instruction::Type::Mult,      Instruction::FlagsMask::UNCONDITIONAL, 0, 13),
  
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 1),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 2),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 3),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 4),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 5),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 6),
    Instruction(Instruction::Type::ShiftL,    Instruction::FlagsMask::UNCONDITIONAL, 0, 7),
    
    Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
    Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1),
    Instruction(Instruction::Type::AddI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1),
    
    Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
    Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1),
    Instruction(Instruction::Type::SubI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1),
    
    Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
    Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1),
    Instruction(Instruction::Type::AndI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1),
    
    Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::UNCONDITIONAL, 1),
    Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1),
    Instruction(Instruction::Type::OrI,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1),
    
    Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::UNCONDITIONAL, 1),
    Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 1),
    Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 1),
    Instruction(Instruction::Type::XorI,      Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 1),
    
    Instruction(Instruction::Type::Not,       Instruction::FlagsMask::UNCONDITIONAL, 0),
    Instruction(Instruction::Type::Not,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 0),
    Instruction(Instruction::Type::Not,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 0),
    Instruction(Instruction::Type::Not,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 0),
    Instruction(Instruction::Type::Not,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 0),
    
    Instruction(Instruction::Type::Add,       Instruction::FlagsMask::UNCONDITIONAL, 2),
    Instruction(Instruction::Type::Add,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Add,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Add,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
    Instruction(Instruction::Type::Add,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
    
    Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::UNCONDITIONAL, 2),
    Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
    Instruction(Instruction::Type::Sub,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
    
    Instruction(Instruction::Type::And,       Instruction::FlagsMask::UNCONDITIONAL, 2),
    Instruction(Instruction::Type::And,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::And,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::And,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
    Instruction(Instruction::Type::And,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
    
    Instruction(Instruction::Type::Or,        Instruction::FlagsMask::UNCONDITIONAL, 2),
    Instruction(Instruction::Type::Or,        Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Or,        Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Or,        Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
    Instruction(Instruction::Type::Or,        Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
    
    Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::UNCONDITIONAL, 2),
    Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::CF | Instruction::FlagsMask::ZF_CF, 2),
    Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::CF | Instruction::FlagsMask::NO_FLAGS, 2),
    Instruction(Instruction::Type::Xor,       Instruction::FlagsMask::ZF | Instruction::FlagsMask::NO_FLAGS, 2),
    
    Instruction(Instruction::Type::Nop,       Instruction::FlagsMask::UNCONDITIONAL, 0),
    Instruction(Instruction::Type::Nop1,      Instruction::FlagsMask::UNCONDITIONAL, 0),
    Instruction(Instruction::Type::Nop2,      Instruction::FlagsMask::UNCONDITIONAL, 0),
    
    Instruction(Instruction::Type::Halt,      Instruction::FlagsMask::UNCONDITIONAL, 0),
  };
  
  static const Instruction noop = Instruction(Instruction::Type::Nop, Instruction::FlagsMask::UNCONDITIONAL, 0);
  return index < sizeof(instructions) / sizeof(*instructions) ? instructions[index] : noop;
}

uint16_t getMicrocode(uint16_t address) {
  byte mi = address & 0b001111;
  byte flags = 1 << ((address & 0b110000) >> 4);
  byte inst = address >> 6;

  const Instruction instruction = getInstruction(inst);
  return instruction.microCodeForCycleFlags(mi, flags);
}
