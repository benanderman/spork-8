#ifndef _PROGRAMMER
#define _PROGRAMMER

#include <Arduino.h>

// This is functionality to interface with Spork-8 counter and RAM/ROM modules
// through bus boards, to program and read EEPROMs.

// Use -1 for pins that aren't connected
struct ProgrammerConfig {
  uint8_t busPins[8];
  uint8_t weClockPin;
  uint8_t pauseButtonPin;
  uint8_t stepButtonPin;
  uint8_t continueButtonPin;
  uint8_t addrClockPin;
  uint8_t addrCountPin;
  uint8_t addrPE0Pin;
  uint8_t addrPE1Pin;
  uint8_t eepromCEPin;
  uint8_t eepromOEPin;
};

class Programmer {
  public:
  
  typedef void (*ReadCallback)(unsigned short address, uint8_t value);
  typedef uint8_t (*WriteCallback)(unsigned short address);

  ProgrammerConfig conf;
  Programmer(const ProgrammerConfig& conf) : conf(conf) {};

  void setPinModes();

  void writeRange(unsigned short start, unsigned short len, WriteCallback callback, bool reverseBits = false);
  void readRange(unsigned short start, unsigned short len, ReadCallback callback, bool reverseBits = false);

  void writeAddress(unsigned short address, unsigned char value, bool reverseBits = false);
  uint8_t readAddress(unsigned short address, bool reverseBits = false);

  void setBus(uint8_t value, bool reverseBits = false);
  uint8_t readBus(bool reverseBits);
  void setBusMode(int mode);
  
  private:
  void setEEPROMEnabled(bool enabled);
  void setEEPROMOutput(bool output);
  void cycleEEPROMWrite();
  void setCounterValue(uint16_t value);
  void incrementAddr();
  void cycleAddrClock();
};

#endif
