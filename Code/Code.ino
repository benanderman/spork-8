#include "signals.h"
#include "instruction_set.h"
#include "programs.h"
#include "spork_8.h"
#include "instructions.h"

Spork8::WriteCallback verifyCallback = NULL;

void setup() {
  Serial.begin(57600);
//  disableSDP();
  writeProgram();
//  writeMicrocode(true);
//  printMicrocode();
//  printTestMicrocode();
//  read256();
}

void loop() {
  // put your main code here, to run repeatedly:
}

Spork8 getNewSpork8() {
  Spork8Config conf = {
    .memoryIndex = 1,
    .counterIndex = 0,
    .selfIndex = 2,

    .resetPin = 2,
    .clockPin = 3,
    .inIndexPins = {4, 5, 6},
    .outIndexPins = {7, 8, 9},
    .sharedSignalPins = {10, 11, 255, 255},
    .busPins = {12, 13, A0, A1, A2, A3, A4, A5}
  };

  Spork8 spork8 = Spork8(conf);
  spork8.setPinModes();
  return spork8;
}

void read256() {
  Spork8 spork8 = getNewSpork8();
  spork8.readRange(0, 1 << 15, printMemoryByte);
}

// May or may not work. Not sure whether reverseBits should be true or false.
void disableSDP() {
  Spork8 spork8 = getNewSpork8();
  delay(10);
  spork8.writeAddress(0x5555, 0xAA, false);
  delay(10);
  spork8.writeAddress(0x2AAA, 0x55, false);
  delay(10);
  spork8.writeAddress(0x5555, 0x80, false);
  delay(10);
  spork8.writeAddress(0x5555, 0xAA, false);
  delay(10);
  spork8.writeAddress(0x2AAA, 0x55, false);
  delay(10);
  spork8.writeAddress(0x5555, 0x20, false);
  delay(10);
}

void writeProgram() {
  Spork8 spork8 = getNewSpork8();

  Serial.println("Writing program");
  spork8.writeRange(0, 1 << 13, getSnakeByte, true);
  Serial.println("Reading");
  verifyCallback = getSnakeByte;
  spork8.readRange(0, 1 << 13, printAndVerifyByte, true);
}

void writeMicrocode(bool highBytes) {
  Spork8 spork8 = getNewSpork8();
  Spork8::WriteCallback callback = highBytes ? getMicrocodeHighByte : getMicrocodeLowByte;
  Serial.println("Writing microcode");
  spork8.writeRange(0, 1 << 15, callback);
  Serial.println("Reading");
  verifyCallback = callback;
  spork8.readRange(0, 1 << 15, printAndVerifyByte);
}

//void printTestMicrocode() {
//  Instruction inst = Instruction(Instruction::Type::PushAll,   Instruction::FlagsMask::UNCONDITIONAL, 0);
//  Serial.print("\n");
//  for (int f = 0; f < 4; f++) {
//    for (int i = 0; i < 16; i++) {
//      printMemoryByte(i, inst.microCodeForCycleFlags(i, 1 << f) >> 8);
//    }
//    Serial.print("\n");
//  }
//}

void printMicrocode() {  
  for (int i = 0; i < 1 << 13; i++) {
    printMemoryByte(i, getMicrocodeLowByte(i));
  }
  Serial.print("\n\n");
  for (int i = 0; i < 1 << 13; i++) {
    printMemoryByte(i, getMicrocodeHighByte(i));
  }
}

void printMemoryByte(uint16_t address, byte value) {
  if (address != 0 && address % 64 == 0) {
    Serial.print('\n');
  }
  if (value < 16) {
    Serial.print('0'); // leading zero
  }
  Serial.print(value, HEX);
}

void printAndVerifyByte(uint16_t address, byte value) {
//  printMemoryByte(address, verifyCallback(address));
  printMemoryByte(address, value);
  if (verifyCallback(address) != value) {
    Serial.print("!");
    Serial.print(verifyCallback(address), HEX);
    Serial.print("!");
  }
}
