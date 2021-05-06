# Revision Log

This is to document all the issues (and fixes to them) of each revision of boards.

## Revision 2

* **RAM / ROM** fully works.
* **Control Module**:
  * loads instructions from the bus randomly. It turns out that EEPROMs do not have floating outputs while new data is loaded after an address change, they have asserted random values, so pull-down resistors don't help. Since the instruction register inputs on `inverted clock & control word 15`, if `control word 15` fluctuates while the clock is low, it will trigger an erroneous read.
  * Has a (silkscreen) line above Zero flag, but it's not inverted.
  * Reset seems to be pulled high, despite the 1k resistor pulling it low; particularly register modules will reset when they shouldn't, and it gets worse the more there are (that is, a second 1k resistor fixes it with some modules, but if more are added it's not enough).

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
* **Counter** didn't count correctly past 8 bits, but was fixable by cutting 4 traces, and adding 4 connections. It turns out CEP and CET are different, and for my purposes, I need them both to be connected to the previous counter's TC.
* **RAM / ROM** was not assembled, because I realized issues before assembly:
    * It would write even while the clock was low. This would mean if control lines randomly selected it for writing while floating, it would write when not desired (hopefully also fixed by Control Module changes). It also means it may start a write cycle before the correct data was on the bus. Fixed by `AND`ing the clock with the write signal, and turning off output and switching bus transceiver to input mode when write signal is high (even while clock is low). The latter should ensure the EEPROM or RAM chip has valid data inputs before the write cycle is started.