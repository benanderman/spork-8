# Revision Log

This is to document all the issues (and fixes to them) of each revision of boards.

## Revision 3
* **Clock**:
  * Switched to a vertical potentiometer, to be more ergnomic. It's probably higher Ohms as well.
* **ALU** fully works.
* **Control Module**:
  * Switched instruction register to use 2x 173 4-bit registers, rather than 1x 273 8-bit register, which allows removing a gate chip. The 4-bit registers support separate clock-pulse and enable signals, which solves the random loading issue in revision 2.
  * Switched to using signal 14 for `reset micro-instruction counter`, since it was unused, and this enables getting rid of the only 30 chip (8-input AND).
  * The net removal of 1 chip also fixes the issue of the crowding of U11/U12, and U6/U7.
  * Switched to USB-C from USB-B.
  * Remove pull-down resistors for control lines, since the outputs from the EEPROMs never float.
  * Removed the inaccurate line over the Zero flag on the silk screen.
  * Signal 15 (`instruction register in`) is inverted accidentally. Easily worked around in the microcode.
* **Counter** fully works.
* **RAM / ROM**:
  * Added a cartridge slot, using the most significant bit of the address to select between the cartridge and on-board EEPROM.
* **General fixes, improvements, and issues**:
  * Binary display on all boards is corrected.
  * Switched to HC chips, which use MUCH less power (~3A vs. ~0.1A).
  * Added screw holes to all boards to be able to mount it.
  * While it generally works reliably at 2MHz, it only does so on battery at ~3.7V, and the Call / Return instructions don't work (but they work at slower speeds). It's still unclear what isn't working or why.
  * When assembled with 10kOhm pull down resistors on the bus, the voltage doesn't dissipate fast enough to read a constant 0 without outputting anything it at faster speeds. This is presumably because the bus wires are very long, and therefore have a high capacitance. The above issue could be related to this.
  * There's now an emulator, written in Zig, which supports controller input and screen display (but no).
* **New boards**:
  * IO module: replaces Input, to have output and input next to each other. The trade-off is that for inputting, it doesn't hold the input value in a register, it just directly connects it to the bus, and for outputting, the outputted value (which is stored in a register) is write-only (it can't be copied back out). But it makes it much more convenient to interface with a shift register.
  * Battery module: holds a battery, can charge it, and has a switch to output power to the CPU. Plugs into the non-addressable module slot on the bottom bus boards.
  * Controller Connector peripheral board: plugs into IO module, and has two RJ12 plugs on it, to connect to parallel-to-serial shift register-based controllers.
  * Screen peripheral board: 10x20 595-shift register-based monochrome display. Plugs into output module (vertically), or IO module (horizontally).
  * Programming board: Arduino-based board used to program and test the CPU in 3 ways:
    1. Separate from the CPU, read / write to EEPROMs (big ones, or cartridges).
    2. Plug into bus boards, to test all the modules plugged in (doesn't work, because the bus is needed to set the signals, but that could cause bus contention).
    3. Replace the program memory and clock, to have a very fast development cycle to write program code (not necessary now that there's an emulator), or to test the CPU.

## Revision 2

* **RAM / ROM** fully works.
* **Control Module**:
  * Loads instructions from the bus randomly. It turns out that EEPROMs do not have floating outputs while new data is loaded after an address change, they have asserted random values, so pull-down resistors don't help. Since the instruction register inputs on `inverted clock & control word 15`, if `control word 15` fluctuates while the clock is low, it will trigger an erroneous read.
  * Has a (silkscreen) line above Zero flag, but it's not inverted.
  * Reset seems to be pulled high, despite the 1k resistor pulling it low; particularly register modules will reset when they shouldn't, and it gets worse the more there are (that is, a second 1k resistor fixes it with some modules, but if more are added it's not enough).
  * Two pairs of chips don't fully fit next to each other: U11/U12, and U6/U7. They're close enough that they could still be soldered though, and the Xinluda chips fit much better than the (I think) Texas Instruments chips.
* **General issues**:
  * All binary values are represented in reverse, since pins 0-8 are displayed left to right, which puts the least significant bit on the left. This is done consistently, so it all works, but is confusing, especially for programming.
  * Power: the whole thing uses around 3A or more of current, which is beyond the USB spec, and too much for even fast chargers. It works to connect a second power supply (2.4A + 1A), but obviously isn't ideal.

## Revision 1

* **Input** fully works.
* **Register** fully works.
* **Clock** mostly works, but:
    * Initial mode is either random, or continuously cycles.
    * Manual pulse sometimes double-pulses.
    * "Slow" mode doesn't go very slow (100k Ohm isn't a big enough range), and the variable resistor UX isn't ideal.
* **ALU** works, but has connections on all headers backwards, meaning it must be installed rotated 180º.
* **Control Module** was not assembled, because I realized issues before assembly:
    * Instruction register, and flags register would change while clock was high, causing control lines to float. Fixed by changing them to use inverted clock.
    * Micro-instruction counter would reset on clock going high rather than low. Fixed by using Parallel Load on inverted clock instead. Also buffered the inverted clock, to try to synchronize it with the instruction and flag register loading.
    * Control lines could be floating while EEPROMs load after address change. Fixed with 1k pull-down resistors. (Or so I thought; turns out they don't float, they assert random values).
* **Counter**:
  * Didn't count correctly past 8 bits, but was fixable by cutting 4 traces, and adding 4 connections. It turns out CEP and CET are different, and for my purposes, I need them both to be connected to the previous counter's TC.
  * Uses the clock as an input for 4 chips; this hasn't caused an issue, but could hit the fan-out limit. Easy to fix by buffering the clock through an unused gate.
* **RAM / ROM** was not assembled, because I realized issues before assembly:
    * It would write even while the clock was low. This would mean if control lines randomly selected it for writing while floating, it would write when not desired (hopefully also fixed by Control Module changes). It also means it may start a write cycle before the correct data was on the bus. Fixed by `AND`ing the clock with the write signal, and turning off output and switching bus transceiver to input mode when write signal is high (even while clock is low). The latter should ensure the EEPROM or RAM chip has valid data inputs before the write cycle is started.