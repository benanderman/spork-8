#ifndef _SPORK_8
#define _SPORK_8

#include <Arduino.h>

// This is functionality to interface with Spork-8 counter and RAM/ROM modules
// through bus boards, to program and read EEPROMs.

// Use -1 for pins that aren't connected
struct Spork8Config {
  byte memoryIndex;
  byte counterIndex;
  byte selfIndex; // An empty slot, for when we want to read or write without affecting anything else

  byte resetPin;
  byte clockPin;
  byte inIndexPins[3];
  byte outIndexPins[3];
  byte sharedSignalPins[4];
  byte busPins[8];
};

class Spork8 {
  public:
  
  typedef void (*ReadCallback)(uint16_t address, byte value);
  typedef byte (*WriteCallback)(uint16_t address);

  Spork8Config conf;
  Spork8(const Spork8Config& conf) : conf(conf) {};

  void setPinModes();

  void writeRange(uint16_t start, uint16_t len, WriteCallback callback, bool reverseBits = false);
  void readRange(uint16_t start, uint16_t len, ReadCallback callback, bool reverseBits = false);

  void writeAddress(uint16_t address, byte value, bool reverseBits = false);
  byte readAddress(uint16_t address, bool reverseBits = false);
  
  private:
  void cycleClock();
  void reset();
  void setInIndex(byte index);
  void setOutIndex(byte index);
  void setCounterValue(uint16_t value);
  void setBus(byte value, bool reverseBits = false);
  byte readBus(bool reverseBits);
  void setBusMode(int mode);
  void setCounterModes(bool countEnable, bool byteSelect);
};

#endif
