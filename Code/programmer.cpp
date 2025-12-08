#include "programmer.h"

// Delay in microseconds when cycling reset, or allowing for setup time.
// 1 is equivalent to a 1MHz clock.
static const int standardDelayTime = 1;

static void standardDelay() {
  delayMicroseconds(standardDelayTime);
}

static const int pageWriteDelay = 11; // ms
static const uint16_t pageMask = 0b1111111000000;
static const int pageSize = 64;

void Programmer::setPinModes() {
  pinMode(conf.weClockPin, OUTPUT);
  pinMode(conf.pauseButtonPin, INPUT_PULLUP);
  pinMode(conf.stepButtonPin, INPUT_PULLUP);
  pinMode(conf.continueButtonPin, INPUT_PULLUP);
  pinMode(conf.addrClockPin, OUTPUT);
  pinMode(conf.addrCountPin, OUTPUT);
  pinMode(conf.addrPE0Pin, OUTPUT);
  pinMode(conf.addrPE1Pin, OUTPUT);
  pinMode(conf.eepromCEPin, OUTPUT);
  pinMode(conf.eepromOEPin, OUTPUT);

  setBusMode(INPUT);

  // These are all active low
  digitalWrite(conf.weClockPin, HIGH);
  digitalWrite(conf.addrPE0Pin, HIGH);
  digitalWrite(conf.addrPE1Pin, HIGH);
  digitalWrite(conf.eepromCEPin, HIGH);
  digitalWrite(conf.eepromOEPin, LOW);
}

void Programmer::writeRange(unsigned short start, unsigned short len, WriteCallback callback, bool reverseBits) {
  setCounterValue(start);
  setEEPROMEnabled(true);
  setEEPROMOutput(false);
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
    
    uint8_t value = page_cache[addr % pageSize];
    setBus(value, reverseBits);
    cycleEEPROMWrite(); // Write current address

    if (((addr + 1) & pageMask) != (addr & pageMask)) {
      delay(pageWriteDelay);
    }

    if (i != len - 1) { // Don't count on final address
      incrementAddr();
    }
  }
  setBusMode(INPUT);
  setEEPROMEnabled(false);
}

void Programmer::readRange(unsigned short start, unsigned short len, ReadCallback callback, bool reverseBits) {
  setCounterValue(start);
  setBusMode(INPUT);
  setEEPROMOutput(true);
  setEEPROMEnabled(true);
  for (uint16_t i = 0; i < len; i++) {
    standardDelay(); // Setup time
    uint8_t value = readBus(reverseBits);
    callback(start + i, value);
    if (i != len - 1) { // Don't count on final address
      incrementAddr();
    }
  }
}

void Programmer::writeAddress(unsigned short address, unsigned char value, bool reverseBits) {
  setCounterValue(address);
  setEEPROMEnabled(true);
  setEEPROMOutput(false);
  setBusMode(OUTPUT);
  setBus(value, reverseBits);
  standardDelay(); // Setup time
  cycleEEPROMWrite();
  standardDelay(); // Setup time
  setBusMode(INPUT);
  setEEPROMOutput(true);
  setEEPROMEnabled(false);
}

uint8_t Programmer::readAddress(unsigned short address, bool reverseBits) {
  setBusMode(INPUT);
  setEEPROMOutput(true);
  setEEPROMEnabled(true);
  setCounterValue(address);
  standardDelay(); // Setup time
  return readBus(reverseBits);
}

void Programmer::setCounterValue(uint16_t value) {
  setBusMode(OUTPUT);

  digitalWrite(conf.addrPE0Pin, LOW);
  setBus(value & 0xFF, false);
  cycleAddrClock();
  digitalWrite(conf.addrPE0Pin, HIGH);

  digitalWrite(conf.addrPE1Pin, LOW);
  setBus((value >> 8) & 0xFF, false);
  cycleAddrClock();
  digitalWrite(conf.addrPE1Pin, HIGH);

  setBusMode(INPUT);
}

void Programmer::setBus(uint8_t value, bool reverseBits) {
  PORTD = (PORTD & 0b00000011) | value << 2;
  PORTB = (PORTB & 0b11111100) | value >> 6;
  // for (int i = 0; i < 8; i++) {
  //   bool b = reverseBits ? (value & 1 << i) : (value & (0b10000000 >> i));
  //   digitalWrite(conf.busPins[i], b);
  // }
}

uint8_t Programmer::readBus(bool reverseBits) {
  uint8_t value;
  value = (PIND >> 2) | (PINB << 6);
  return value;
}

void Programmer::setBusMode(int mode) {
  if (mode == OUTPUT) {
    DDRD = (DDRD & 0b00000011) | 0b11111100;
    DDRB = (DDRB & 0b11111100) | 0b00000011;
  } else {
    DDRD = DDRD & 0b00000011;
    DDRB = DDRB & 0b11111100;
  }
  // for (int i = 0; i < 8; i++) {
  //   pinMode(conf.busPins[i], mode);
  // }
}

void Programmer::setEEPROMEnabled(bool enabled) {
  digitalWrite(conf.eepromCEPin, !enabled);
}

void Programmer::setEEPROMOutput(bool output) {
  digitalWrite(conf.eepromOEPin, !output);
}

void Programmer::cycleEEPROMWrite() {
  digitalWrite(conf.weClockPin, LOW);
  standardDelay(); // Setup time
  digitalWrite(conf.weClockPin, HIGH);
}

void Programmer::incrementAddr() {
  digitalWrite(conf.addrCountPin, HIGH);
  cycleAddrClock();
  digitalWrite(conf.addrCountPin, LOW);
}

void Programmer::cycleAddrClock() {
  digitalWrite(conf.addrClockPin, HIGH);
  digitalWrite(conf.addrClockPin, LOW);
}
