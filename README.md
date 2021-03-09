# Spork-8

This is an 8-bit computer project, based heavily on [Ben Eater's 8-bit breadboard computer](https://eater.net/8bit). It's made out of modular PCBs that plug into each other, and contain mostly 74LS-series chips. It runs code from an EEPROM (so it's only programmable from a computer), and has separate memory. It's meant to display what's happening, when running on a 555-timer or manually stepping, but also be capable enough to implement some sort of game, when using an oscillator as a clock.

## Modules
 * **Control module**: Coordinates everything else. Contains the micro-code EEPROMs, instruction register, micro-instruction counter, power input, reset button, and logic to interface with modules through bus boards.
 * **Bus**: Four of these interface between the control module and up to 16 other modules. These demux three signal lines each for in/out enable signals to the four modules connected to each bus board. One bus board plugs into the top of the control module, and one into the bottom. A second bus board plugs into the first ones. The first in/out signal line selects between the two boards on top / bottom, and the one connected to the control module inverts the signal before passing it onto the other bus board.
 * **Register**: Stores 8 bits, and can connect directly to an adjacent board above or below to expose its value (for use by the ALU). Has output headers, to interface with peripherals.
 * **ALU**: Performes calculations on values from register modules above and below it. Can output: add, subtract, bit-wise AND, or the carry-bit and zero-flag for any of those operations. Must be placed in the 1111 position (bottom right of top-most bus board), because the control module is hard-wired to input to the flags register when the read signal to that module position is enabled, which also enables flag output on the ALU.
 * **Clock**: Provides the clock pulse for the computer. Has three modes: manual with button to pulse, 555-timer with potentiometer to adjust timing, or crystal oscillator.
 * **Counter**: Stores and counts 16-bit values. Uses two global signal lines to select which byte to read / write, and whether to enable counting. Used for both the RAM address register and program counter / program memory address register.
 * **RAM**: RAM or EEPROM (they have the same pinout). Used for the program memory EEPROM (not intended to be written to), and the static memory used for storing data. Up to 15-bits of address are taken from an adjacent counter module.
 * **Input**: Stores 8 bits of input from peripherals. An 8-bit register that can write to the bus, but takes input from headers that can be connected to peripherals. Has built-in pull-down resistors. Only reads value on a clock cycle when input signal is high.
 
## Layout, signals, and parts list
These images show the layout of the modules in the 16 slots, the functions of each of the signals, and a parts list.
![Module layout](Images/module-layout.png)
![Signal functions](Images/signal-functions.png)
![Parts list](Images/parts-list.png)


## Design images
### Schematics
![Control Module schematic](Images/control-module-sch.png)
![Control Module bus interface schematic](Images/control-module-bus-interface-sch.png)
![Bus schematic](Images/bus-sch.png)
![Register schematic](Images/register-sch.png)
![ALU schematic](Images/alu-sch.png)
![RAM schematic](Images/ram-sch.png)
![Input schematic](Images/input-sch.png)
![Clock schematic](Images/clock-sch.png)

### PCB Layouts
![Control Module PCB layout](Images/control-module-pcb.png)
![Bus PCB layout](Images/bus-pcb.png)
![Register PCB layout](Images/register-pcb.png)
![ALU PCB layout](Images/alu-pcb.png)
![RAM PCB layout](Images/ram-pcb.png)
![Input PCB layout](Images/input-pcb.png)
![Clock PCB layout](Images/clock-pcb.png)

### 3D Renderings
![Control Module 3D render](Images/control-module-3d.png)
![Bus 3D render](Images/bus-3d.png)
![Register 3D render](Images/register-3d.png)
![ALU 3D render](Images/alu-3d.png)
![RAM 3D render](Images/ram-3d.png)
![Input 3D render](Images/input-3d.png)
![Clock 3D render](Images/clock-3d.png)