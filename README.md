# Spork-8

This is an 8-bit computer project, inspired by [Ben Eater's 8-bit breadboard computer](https://eater.net/8bit). It's made out of modular PCBs that plug into each other, and contain mostly 74HC-series chips (original 74LS). It runs code from an EEPROM (so it's only programmable from a computer), and has separate memory. It's meant to display what's happening, when running on a 555-timer or manually stepping, but also be capable enough to implement some sort of game, when using an oscillator as a clock.

## Status of project

The project was originally completed in 2021 and mostly worked with 74LS-series chips, but it had some issues (see [RevisionLog](RevisionLog.md)), and used way too much power.

In 2025, it was rebuilt with 74HC-series chips, and several improvements, an emulator, and peripheral boards. It has some issues, but mostly works well.

## Modules
 * **Control module**: Coordinates everything else. Contains the micro-code EEPROMs, instruction register, micro-instruction counter, power input, reset button, and logic to interface with modules through bus boards.
 * **Bus**: Four of these interface between the control module and up to 16 other modules. These demux three signal lines each for in/out enable signals to the four modules connected to each bus board. One bus board plugs into the top of the control module, and one into the bottom. Two more bus boards plug into the first two. The first in/out signal line selects between the two boards on top / bottom, and the one connected to the control module inverts the signal before passing it onto the other bus board.
 * **Register**: Stores 8 bits, and can connect directly to an adjacent board above or below to expose its value (for use by the ALU and shift / rotate module). Has output headers, to interface with peripherals.
 * **ALU**: Performes calculations on values from register modules above and below it. Can output: add, subtract, bit-wise AND, or the carry-bit and zero-flag for any of those operations. Must be placed in the 1111 position (bottom right of top-most bus board), because the control module is hard-wired to input to the flags register when the read signal to that module position is enabled, which also enables flag output on the ALU.
 * **Clock**: Provides the clock pulse for the computer. Has three modes: manual with button to pulse, 555-timer with potentiometer to adjust timing, or crystal oscillator (2MHz seems to work).
 * **Counter**: Stores and counts 16-bit values. Uses two global signal lines to select which byte to read / write, and whether to enable counting. Used for both the RAM address register and program counter / program memory address register.
 * **RAM**: RAM or EEPROM (they have the same pinout). Used for the program memory EEPROM (not intended to be written to), and the static memory used for storing data. Up to 15-bits of address are taken from an adjacent counter module. Also has a cartridge slot, and switches between it and the EEPROM on the board using the 16th address bit. This allows swapping out programs much easier
 * **Input / Output**: Like a register module, except when outputting to the bus, outputs the value from input headers instead of the registers. The 8-bit value stored in the registers is accessible on output headers as well. The two headers are in parallel, making it sturdy to plug in a peripheral that uses both.
 * **Battery**: Has a battery, charging capability with USB-C, and a switch to output power to the CPU.

## Peripherals
* **Controller Connector**: Plugs into IO module, and has two RJ12 plugs on it, to connect to parallel-to-serial shift register-based controllers.
* **Screen**: An 10x20 595-shift register-based monochrome display. Plugs into output module (vertically), or IO module (horizontally).
* **Cartridge**: A small board with a surface-mount version of the same 28C256 EEPROM used as in the program memory module. Plugs into the program memory module with the smallest PCIe board edge connector.
* **Programmer**: Arduino-based board used to program and test the CPU in 3 ways:
    1. Separate from the CPU, read / write to EEPROMs (big ones, or cartridges).
    2. Plug into bus boards, to test all the modules plugged in (doesn't work, because the bus is needed to set the signals, but that could cause bus contention).
    3. Replace the program memory and clock, to have a very fast development cycle to write program code (not necessary now that there's an emulator), or to test the CPU.
 
## Layout, signals, and parts list
These images show the layout of the modules in the 16 slots, the functions of each of the signals, and a parts list.
![Module layout](Images/module-layout.png)
![Signal functions](Images/signal-functions.png)
![Parts list](Images/parts-list.png)


## Design images
### Overall layout
![Layout of the CPU](Images/layout.png)

### Mounting board (laser cut acrylic)
![Mounting board design](Images/mounting-board-pcb.png)

### Schematics
![Control Module schematic](Images/control-module-sch.png)
![Control Module bus interface schematic](Images/control-module-bus-interface-sch.png)
![Bus schematic](Images/bus-sch.png)
![Register schematic](Images/register-sch.png)
![ALU schematic](Images/alu-sch.png)
![Shift / Rotate schematic](Images/shift-sch.png)
![Clock schematic](Images/clock-sch.png)
![Counter schematic](Images/counter-sch.png)
![RAM schematic](Images/ram-sch.png)
![Input / Output schematic](Images/io-sch.png)
![Battery schematic](Images/battery-sch.png)
![Screen schematic](Images/screen-sch.png)
![Screen schematic](Images/screen-led-row-sch.png)
![Controller Connector schematic](Images/controller-connector-sch.png)
![Cartridge schematic](Images/cartridge-sch.png)
![Programmer schematic](Images/programmer-sch.png)
![Programmer USB Interface schematic](Images/programmer-usb-interface-sch.png)
![Programmer LEDs schematic](Images/programmer-leds-sch.png)

### PCB Layouts
![Control Module PCB layout](Images/control-module-pcb.png)
![Bus PCB layout](Images/bus-pcb.png)
![Register PCB layout](Images/register-pcb.png)
![ALU PCB layout](Images/alu-pcb.png)
![Shift / Rotate PCB layout](Images/shift-pcb.png)
![Clock PCB layout](Images/clock-pcb.png)
![Counter PCB layout](Images/counter-pcb.png)
![RAM PCB layout](Images/ram-pcb.png)
![Input / Output PCB layout](Images/io-pcb.png)
![Battery PCB layout](Images/battery-pcb.png)
![Screen PCB layout](Images/screen-pcb.png)
![Controller Connector PCB layout](Images/controller-connector-pcb.png)
![Cartridge PCB layout](Images/cartridge-pcb.png)
![Programmer PCB layout](Images/programmer-pcb.png)

### 3D Renderings
![Control Module 3D render](Images/control-module-3d.png)
![Bus 3D render](Images/bus-3d.png)
![Register 3D render](Images/register-3d.png)
![ALU 3D render](Images/alu-3d.png)
![Shift / Rotate 3D render](Images/shift-3d.png)
![Clock 3D render](Images/clock-3d.png)
![Counter 3D render](Images/counter-3d.png)
![RAM 3D render](Images/ram-3d.png)
![Input / Output 3D render](Images/io-3d.png)
![Battery 3D render](Images/battery-3d.png)
![Screen 3D render](Images/screen-3d.png)
![Controller Connector 3D render](Images/controller-connector-3d.png)
![Cartridge 3D render](Images/cartridge-3d.png)
![Programmer 3D render](Images/programmer-3d.png)
