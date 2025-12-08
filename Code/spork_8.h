#ifndef _SPORK_8
#define _SPORK_8

#include <Arduino.h>

// This is functionality to interface with Spork-8 counter and RAM/ROM modules
// through bus boards, to program and read EEPROMs.

// Use -1 for pins that aren't connected
struct Spork8Config {
  uint8_t memoryIndex;
  uint8_t counterIndex;
  uint8_t selfIndex; // An empty slot, for when we want to read or write without affecting anything else

  uint8_t resetPin;
  uint8_t clockPin;
  uint8_t inIndexPins[3];
  uint8_t outIndexPins[3];
  uint8_t sharedSignalPins[4];
  uint8_t busPins[8];
};

class Spork8 {
  public:
  
  typedef void (*ReadCallback)(uint16_t address, uint8_t value);
  typedef uint8_t (*WriteCallback)(uint16_t address);

  Spork8Config conf;
  Spork8(const Spork8Config& conf) : conf(conf) {};

  void setPinModes();

  void writeRange(uint16_t start, uint16_t len, WriteCallback callback, bool reverseBits = false);
  void readRange(uint16_t start, uint16_t len, ReadCallback callback, bool reverseBits = false);

  void writeAddress(uint16_t address, uint8_t value, bool reverseBits = false);
  uint8_t readAddress(uint16_t address, bool reverseBits = false);
  
  private:
  void cycleClock();
  void reset();
  void setInIndex(uint8_t index);
  void setOutIndex(uint8_t index);
  void setCounterValue(uint16_t value);
  void setBus(uint8_t value, bool reverseBits = false);
  uint8_t readBus(bool reverseBits);
  void setBusMode(int mode);
  void setCounterModes(bool countEnable, bool byteSelect);
};

#endif
