# Revision Log

This is to document all the issues (and fixes to them) of each revision of boards.

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
    * Control lines could be floating while EEPROMs load after address change. Fixed with 1k pull-down resistors.
* **Counter** didn't count correctly past 8 bits, but was fixable by cutting 4 traces, and adding 4 connections. It turns out CEP and CET are different, and for my purposes, I need them both to be connected to the previous counter's TC.
* **RAM / ROM** was not assembled, because I realized issues before assembly:
    * It would write even while the clock was low. This would mean if control lines randomly selected it for writing while floating, it would write when not desired (hopefully also fixed by Control Module changes). It also means it may start a write cycle before the correct data was on the bus. Fixed by `AND`ing the clock with the write signal, and turning off output and switching bus transceiver to input mode when write signal is high (even while clock is low). The latter should ensure the EEPROM or RAM chip has valid data inputs before the write cycle is started.