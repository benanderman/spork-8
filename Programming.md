# Programming The Spork-8

This document contains details about writing code for the Spork-8.

## RAM Layout and Calling Convention

Non-volatile program memory and RAM are separate, and each have 16-bits of address space. The address module for RAM and program memory both support incrementing by 1, making many common operations more efficient. The bus is only 8 bits, so it takes 2 clock cycles to set a full address on either. The RAM (HM62256) and program memory (28C256) are both 32KB, which only needs 15 bits of address, so the MSB (most significant bit) is used to select whether to access the chip on the board (0), or the cartridge slot (1), which could contain a cartridge with another EEPROM.

The stack starts from 0x0000, and grows towards 0x7FFF, with frames aligned to 256 bytes (and each one 256 bytes in size).

Or put another way, the stack is broken up into 128 frames (the top 7 bits after the MSB) of 256 bytes each (the lower byte), so that the high byte (without the MSB) is the stack frame, and the low byte is the offset within the stack frame.

In each stack frame, the return address is stored in the first 2 bytes (0 is the high byte, 1 is the low byte), function arguments take up bytes counting up from 2, and local variables take up the bytes following those. Return values are stored counting down from 0xFF. 

## Types

The only integer size natively supported by arithmetic and logic instructions is 8 bits, but pointers are 16 bits, and C types are defined as:
 * `char`: signed.
 * `int`: 16-bit.
 * `short`: 16-bit.
 * `long`: 32-bit.
 * `long long`: 64-bit.
 * `float`: 32-bit floating point (23-bit mantissa) IEEE-754-2008 binary32.
 * `double`: 64-bit floating point (52-bit mantissa) IEEE-754-2008 binary64.
 * `long double`: same as `double`.

## Compiling Assembly Files

Dependency: [customasm](https://hlorenzi.github.io/customasm/)

```
cd Code/emulator
customasm ../programs/snake2p.asm -o ../programs/snake2p.bin -f binary
```

Then pass the .bin files to the emulator.

## Compiling and Running the Emulator

```
cd Code/emulator
zig build
./zig-out/bin/emulator ../programs/snake2p.bin
```
