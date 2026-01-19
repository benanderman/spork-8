#include "signals.h"
#include "instruction_set.h"
#include "programs.h"
#include "spork_8.h"
#include "spork_8_state.h"
#include "programmer.h"
#include "instructions.h"

Spork8::WriteCallback verifyCallback = NULL;

void setup() {
  Serial.begin(57600);
//  read256();
//  writeMicrocode(false);
//  writeMicrocode(true);
//  disableSDP();
  writeProgram();
//  testBus();
//  emulate();
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

Programmer getNewProgrammer(bool cpuMode = false) {
  ProgrammerConfig conf = {
    .busPins = {2, 3, 4, 5, 6, 7, 8, 9},
    .weClockPin = 10,
    .pauseButtonPin = 11,
    .stepButtonPin = 12,
    .continueButtonPin = 13,
    .addrClockPin = 14,
    .addrCountPin = 15,
    .addrPE0Pin = 17,
    .addrPE1Pin = 16,
    .eepromCEPin = 18,
    .eepromOEPin = 19,
  };

  Programmer programmer = Programmer(conf);
  programmer.setPinModes(cpuMode);
  return programmer;
}

void testBus() {
  Programmer programmer = getNewProgrammer();
  programmer.setBusMode(OUTPUT);
  programmer.setBus(0b00000001);
  delay(1000);
  programmer.setBus(0b00000010);
  delay(1000);
  programmer.setBus(0b00000100);
  delay(1000);
  programmer.setBus(0b00001000);
  delay(1000);
  programmer.setBus(0b00010000);
  delay(1000);
  programmer.setBus(0b00100000);
  delay(1000);
  programmer.setBus(0b01000000);
  delay(1000);
  programmer.setBus(0b10000000);
  delay(1000);
}

uint8_t emulatorGetProgmemByte(uint16_t address) {
  uint8_t value = (address & 0x8000) ? getMovingDotByte(address ^ 0x8000) : getJumpToCartridgeByte(address);
  return value;
}

uint8_t *emulator_memory = nullptr;
uint16_t emulator_memory_size = 0;
uint8_t emulator_ram_pages = 0;
uint8_t emulator_ram_page_size = 0;
uint8_t emulatorGetRamByte(uint16_t address) {
  uint8_t page = address >> 8;
  uint8_t addr = address & 0xFF;
  if (page < emulator_ram_pages && addr < emulator_ram_page_size) {
    return emulator_memory[page * emulator_ram_page_size];
  } else {
    return 0;
  }
}
void emulatorSetRamByte(uint16_t address, uint8_t value) {
  uint8_t page = address >> 8;
  uint8_t addr = address & 0xFF;
  if (page < emulator_ram_pages && addr < emulator_ram_page_size) {
    emulator_memory[page * emulator_ram_page_size] = value;
  }
}

void emulate() {
  Programmer programmer = getNewProgrammer(true);
  Serial.println("Emulator");

  const uint8_t pages = 2;
  const uint8_t page_size = 32;
  uint8_t ram_buffer[pages * page_size];
  emulator_memory = ram_buffer;
  emulator_memory_size = sizeof(ram_buffer) / sizeof(*ram_buffer);
  uint8_t emulator_ram_pages = pages;
  uint8_t emulator_ram_page_size = page_size;

  Spork8State state = Spork8State();
  spork8_state_reset(&state);
  state.get_progmem_byte = emulatorGetProgmemByte;
  state.get_ram_byte = emulatorGetRamByte;
  state.set_ram_byte = emulatorSetRamByte;
  spork8_state_cycle(&state);

  programmer.resetCPU();

  while (true) {
    // Get signal values.
    bool sig_out = programmer.getCPUSigOut();

    // TODO: Verify signal values are as expected.

    // Set bus mode and value if output is enabled.
    if (sig_out) {
      programmer.setBusMode(OUTPUT);
      programmer.setBus(state.bus);
      Serial.print("Bus: ");
      Serial.print(state.bus, HEX);
      Serial.print(" (output)\n");

    // Verify bus is as expected if not outputting to it.
    } else {
      programmer.setBusMode(INPUT);
      uint8_t bus = programmer.readBus(false);
      Serial.print("Bus: virtual ");
      Serial.print(state.bus, HEX);
      Serial.print(" real ");
      Serial.print(bus, HEX);
      Serial.print("\n");
      // if (state.bus != bus) {
      //   break;
      // }
    }

    // Set clock to high to "do" the cycle, and cycle the state.
    delay(500);
    programmer.setCPUClock(HIGH);
    delay(500);
    spork8_state_cycle(&state);

    // Set clock to low again. Don't delay here, because we want to change bus output
    // mode ASAP after reading SIG_OUT, since this is when signals update.
    programmer.setCPUClock(LOW);
  }
  Serial.println("Found difference");
  // Just in case, set bus mode to INPUT.
  programmer.setBusMode(INPUT);
  while (true) {}
}

void read256() {
  Programmer programmer = getNewProgrammer();
  programmer.readRange(0, 1 << 8, printMemoryByte);
}

void disableSDP() {
  Programmer programmer = getNewProgrammer();
  programmer.writeAddress(0x5555, 0xAA, false);
  programmer.writeAddress(0x2AAA, 0x55, false);
  programmer.writeAddress(0x5555, 0x80, false);
  programmer.writeAddress(0x5555, 0xAA, false);
  programmer.writeAddress(0x2AAA, 0x55, false);
  programmer.writeAddress(0x5555, 0x20, false);
}

void writeProgram() {
  Programmer programmer = getNewProgrammer();

  Serial.println("Writing program");
  programmer.writeRange(0, 1 << 10, getMovingDotByte, false);
  Serial.println("Reading");
  verifyCallback = getMovingDotByte;
  programmer.readRange(0, 1 << 10, printAndVerifyByte, false);
}

void writeMicrocode(bool highBytes) {
  Programmer programmer = getNewProgrammer();
  Programmer::WriteCallback callback = highBytes ? getMicrocodeHighByte : getMicrocodeLowByte;
  Serial.println("Writing microcode");
  uint16_t start = 0; // 0x1780;
  uint16_t end = 1 << 15; // 0x1A40;
  programmer.writeRange(start, end - start, callback);
  Serial.println("Reading");
  verifyCallback = callback;
  programmer.readRange(start, end - start, printAndVerifyByte);
}

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
  if (address % 64 == 0) {
    Serial.print(address, HEX);
    Serial.print(": ");
  }
  if (value < 16) {
    Serial.print('0'); // leading zero
  }
  Serial.print(value, HEX);
}

void printAndVerifyByte(uint16_t address, byte value) {
//  printMemoryByte(address, verifyCallback(address));
  byte expectedValue = verifyCallback(address);
  printMemoryByte(address, value);
  if (expectedValue != value) {
    Serial.print("(");
    if (expectedValue < 16) {
      Serial.print('0'); // leading zero
    }
    Serial.print(expectedValue, HEX);
    Serial.print(")");
  }
}
