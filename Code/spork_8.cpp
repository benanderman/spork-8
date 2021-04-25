#include "spork_8.h"

// Delay in microseconds when cycling clock, reset, or allowing for setup time.
// 1 is equivalent to a 1MHz clock.
static const int standardDelayTime = 3;

static void standardDelay() {
  delayMicroseconds(standardDelayTime);
}

void Spork8::setPinModes() {
  pinMode(conf.resetPin, OUTPUT);
  pinMode(conf.clockPin, OUTPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(conf.inIndexPins[i], OUTPUT);
    pinMode(conf.outIndexPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(conf.sharedSignalPins[i], OUTPUT);
  }
  setBusMode(INPUT);
}

void Spork8::writeRange(uint16_t start, uint16_t len, WriteCallback callback) {
  setCounterValue(start);
  setInIndex(conf.memoryIndex);
  setOutIndex(conf.selfIndex);
  setCounterModes(true, false);
  setBusMode(OUTPUT);
  for (uint16_t i = 0; i < len; i++) {
    byte value = callback(start + i);
    setBus(value);
    standardDelay(); // Setup time
    cycleClock();
  }
  setBusMode(INPUT);
}

void Spork8::readRange(uint16_t start, uint16_t len, ReadCallback callback) {
  setCounterValue(start);
  setInIndex(conf.selfIndex);
  setOutIndex(conf.memoryIndex);
  setCounterModes(true, false);
  setBusMode(INPUT);
  standardDelay(); // Setup time
  for (uint16_t i = 0; i < len; i++) {
    byte value = readBus();
    callback(start + i, value);
    cycleClock();
  }
}

void Spork8::writeAddress(uint16_t address, byte value) {
  setCounterValue(address);
  setOutIndex(conf.selfIndex);
  setInIndex(conf.memoryIndex);
  setBusMode(OUTPUT);
  setBus(value);
  cycleClock();
  setBusMode(INPUT);
}

byte Spork8::readAddress(uint16_t address) {
  setCounterValue(address);
  setInIndex(conf.selfIndex);
  setOutIndex(conf.memoryIndex);
  setBusMode(INPUT);
  return readBus();
}

void Spork8::cycleClock() {
  digitalWrite(conf.clockPin, HIGH);
  standardDelay();
  digitalWrite(conf.clockPin, LOW);
}

void Spork8::reset() {
  digitalWrite(conf.resetPin, HIGH);
  standardDelay();
  digitalWrite(conf.resetPin, LOW);
}

void Spork8::setInIndex(byte index) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(conf.inIndexPins[i], index & (0b100 >> i));
  }
}

void Spork8::setOutIndex(byte index) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(conf.outIndexPins[i], index & (0b100 >> i));
  }
}

void Spork8::setCounterValue(uint16_t value) {
  setOutIndex(conf.selfIndex);
  setInIndex(conf.counterIndex);
  setBusMode(OUTPUT);
  setCounterModes(false, false);
  setBus(value & 0xFF, true);
  cycleClock();
  setCounterModes(false, true);
  setBus((value >> 8) & 0xFF, true);
  cycleClock();
  setBusMode(INPUT);
}

void Spork8::setBus(byte value, bool reverseBits) {
  for (int i = 0; i < 8; i++) {
    bool b = reverseBits ? (value & 1 << i) : (value & (0b10000000 >> i));
    digitalWrite(conf.busPins[i], b);
  }
}

byte Spork8::readBus() {
  byte value = 0;
  for (int i = 0; i < 8; i++) {
    value |= digitalRead(conf.busPins[i]) << (7 - i);
  }
  return value;
}

void Spork8::setBusMode(int mode) {
  for (int i = 0; i < 8; i++) {
    pinMode(conf.busPins[i], mode);
  }
}

void Spork8::setCounterModes(bool countEnable, bool byteSelect) {
  // If the index of the counter is odd, then it's in a bottom slot
  bool onBottom = conf.counterIndex & 1;
  byte countEnablePin = conf.sharedSignalPins[onBottom ? 2 : 0];
  byte byteSelectPin = conf.sharedSignalPins[onBottom ? 3 : 1];
  digitalWrite(countEnablePin, countEnable);
  digitalWrite(byteSelectPin, byteSelect);
}
