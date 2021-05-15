#include "signals.h"
#include "instruction_set.h"
#include "programs.h"
#include "spork_8.h"

void setup() {
  Serial.begin(57600);
//  writeProgram();
  writeMicrocode(false);
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

void writeProgram() {
  Spork8 spork8 = getNewSpork8();

  Serial.println("Writing program");
  spork8.writeRange(0, 1 << 13, getMovingDotByte, true);
  Serial.println("Reading");
  spork8.readRange(0, 1 << 13, printAndVerifyTestProgramByte, true);
}

void printAndVerifyTestProgramByte(uint16_t address, byte value) {
  printMemoryByte(address, value);
  if (getMovingDotByte(address) != value) {
    Serial.print("\nValue was incorrect, should be:");
    Serial.println(getMovingDotByte(address), HEX);
  }
}

void writeMicrocode(bool highBytes) {
  Spork8 spork8 = getNewSpork8();

  Serial.println("Writing microcode");
  spork8.writeRange(0, 1 << 13, highBytes ? getMicrocodeHighByte : getMicrocodeLowByte);
  Serial.println("Reading");
  spork8.readRange(0, 1 << 13, highBytes ? printAndVerifyMicrocodeHighByte : printAndVerifyMicrocodeLowByte);
}

void printAndVerifyMicrocodeHighByte(uint16_t address, byte value) {
  printMemoryByte(address, value);
  if (getMicrocodeHighByte(address) != value) {
    Serial.print("\nValue was incorrect, should be:");
    Serial.println(getMicrocodeHighByte(address), HEX);
  }
}

void printAndVerifyMicrocodeLowByte(uint16_t address, byte value) {
  printMemoryByte(address, value);
  if (getMicrocodeLowByte(address) != value) {
    Serial.print("\nValue was incorrect, should be:");
    Serial.println(getMicrocodeLowByte(address), HEX);
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

void testSpork8Mem() {
  Spork8 spork8 = getNewSpork8();

  Serial.println("Writing test data");
  spork8.writeRange(0, 1 << 13, spork8TestData);
  Serial.println("Reading");
  spork8.readRange(0, 1 << 13, printSpork8TestData);
}

byte spork8TestData(uint16_t address) {
  const char *test = "0 1 2 3 4 5 6 7 ";
  return test[address % strlen(test)];
}

void printSpork8TestData(uint16_t address, byte value) {
  if (address != 0 && address % 64 == 0) {
    Serial.print('\n');
  }
  if (value < 16) {
    Serial.print('0'); // leading zero
  }
  Serial.print(value, HEX);
  if (spork8TestData(address) != value) {
    Serial.print("\nValue was incorrect, should be:");
    Serial.println(spork8TestData(address), HEX);
  }
}
