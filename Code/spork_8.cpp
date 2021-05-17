#include "spork_8.h"

// Delay in microseconds when cycling reset, or allowing for setup time.
// 1 is equivalent to a 1MHz clock.
static const int standardDelayTime = 1;

static void standardDelay() {
  delayMicroseconds(standardDelayTime);
}

static const int pageWriteDelay = 11; // ms
static const uint16_t pageMask = 0b1111111000000;
static const int pageSize = 64;

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

void Spork8::writeRange(uint16_t start, uint16_t len, WriteCallback callback, bool reverseBits) {
  setCounterValue(start);
  setInIndex(conf.memoryIndex);
  setOutIndex(conf.selfIndex);
  setCounterModes(false, false);
  standardDelay(); // Setup time
  setBusMode(OUTPUT);
  
  uint8_t page_cache[64];
  for (uint16_t i = 0; i < len; i++) {
    uint16_t addr = start + i;

    // At the beginning of a page, pre-calculate the whole page to make writes fast enough
    if (i == 0 || addr % pageSize == 0) {
      for (int p = addr; (p & pageMask) == (addr & pageMask); p++) {
        page_cache[p % pageSize] = callback(p);
      }
    }
    
    byte value = page_cache[addr % pageSize];
    setBus(value, reverseBits);
    cycleClock(); // Write current address

    if (((addr + 1) & pageMask) != (addr & pageMask)) {
      delay(pageWriteDelay);
    }

    if (i != len - 1) { // Don't count on final address
      setCounterModes(true, false);
      setInIndex(conf.selfIndex);
      cycleClock(); // Go to next address
      setInIndex(conf.memoryIndex);
      setCounterModes(false, false);
    }
  }
  setBusMode(INPUT);
}

void Spork8::readRange(uint16_t start, uint16_t len, ReadCallback callback, bool reverseBits) {
  setCounterValue(start);
  setInIndex(conf.selfIndex);
  setOutIndex(conf.memoryIndex);
  setCounterModes(true, false);
  setBusMode(INPUT);
  for (uint16_t i = 0; i < len; i++) {
    standardDelay(); // Setup time
    byte value = readBus(reverseBits);
    callback(start + i, value);
    if (i != len - 1) { // Don't count on final address
      cycleClock();
    }
  }
}

void Spork8::writeAddress(uint16_t address, byte value, bool reverseBits) {
  setCounterValue(address);
  setOutIndex(conf.selfIndex);
  setInIndex(conf.memoryIndex);
  setBusMode(OUTPUT);
  setBus(value, reverseBits);
  standardDelay(); // Setup time
  cycleClock();
  setBusMode(INPUT);
}

byte Spork8::readAddress(uint16_t address, bool reverseBits) {
  setCounterValue(address);
  setInIndex(conf.selfIndex);
  setOutIndex(conf.memoryIndex);
  setBusMode(INPUT);
  return readBus(reverseBits);
}

void Spork8::cycleClock() {
  digitalWrite(conf.clockPin, HIGH);
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

byte Spork8::readBus(bool reverseBits) {
  byte value = 0;
  for (int i = 0; i < 8; i++) {
    byte b = reverseBits ? digitalRead(conf.busPins[i]) << i : digitalRead(conf.busPins[i]) << (7 - i);
    value |= b;
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
