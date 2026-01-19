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
  
  typedef void (*ReadCallback)(signed short address, uint8_t value);
  typedef uint8_t (*WriteCallback)(unsigned short address);

  ProgrammerConfig conf;
  Programmer(const ProgrammerConfig& conf) : conf(conf) {};

  void setPinModes(uint8_t cpuMode = false);

  void writeRange(unsigned short start, unsigned short len, WriteCallback callback, unsigned char reverseBits = false);
  void readRange(unsigned short start, unsigned short len, ReadCallback callback, unsigned char reverseBits = false);

  void writeAddress(unsigned short address, unsigned char value, unsigned char reverseBits = false);
  uint8_t readAddress(unsigned short address, unsigned char reverseBits = false);

  void setBus(uint8_t value, uint8_t reverseBits = false);
  uint8_t readBus(uint8_t reverseBits);
  void setBusMode(int mode);

  void resetCPU();
  void setCPUClock(uint8_t value);
  bool getCPUSigIn();
  bool getCPUSigOut();
  
  private:
  void setEEPROMEnabled(bool enabled);
  void setEEPROMOutput(bool output);
  void cycleEEPROMWrite();
  void setCounterValue(uint16_t value);
  void incrementAddr();
  void cycleAddrClock();
};

#endif
