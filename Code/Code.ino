#include "signals.h"
#include "instructions.h"
#include "spork_8.h"

void setup() {
  Serial.begin(57600);
  testSpork8Mem();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void testSpork8Mem() {
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

  Serial.println("Writing test data");
  spork8.writeRange(0, 1 << 15, spork8TestData);
  Serial.println("Done writing test data; reading");
  spork8.readRange(0, 1 << 15, printSpork8TestData);
}

byte spork8TestData(uint16_t address) {
  const char *test = "Hello memory!";
  return test[address % strlen(test)];
}

void printSpork8TestData(uint16_t address, byte value) {
  char c = value;
  Serial.print(c);
  if (address % 78 == 0) {
    Serial.print('\n');
  }
}
