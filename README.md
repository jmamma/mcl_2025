# MCL Migration: ATmega2560 to RP2040/RP2035

This is a WIP migration of [MCL](https://github.com/jmamma/mcl) from the ATmega2560 to the RP2040/RP2035. Given MCL became a modified Arduino core, the port will initially be based around arduino-pico, enabling us to leverage the SdFat and Adafruit graphics libraries that are core components of MCL.

## Current Progress

Port is now complete.

- [X] VSCode + gdb + openocd SW debugger integration
  - For realtime hardware debugging

- [X] Implementation of low level ISRs for UART + timers, as per MCL
  - The atmega2560 does not support nested interrupts. I've re-implemented ISR locking as per MCL, with the ability to unlock when entering Sequencer and MIDI processing routines.
  - Eventually this will be re-architectured to leverage the 2nd core.
- [X] MIDI stack
  - Low level MIDI stack responsible for initialising the UARTs
  - Processing rx/tx of MIDI data

- [X] Validate MIDI stack at various turbo speeds (1x, 2x, 4x, 8x, 10x)
  - [X] Sysex Tx/Rx
  - [X] Midi Note Tx/Rx
  - [X] MIDI CC Tx/Rx

- [X] Verify SDFat is functional with the arduino-pico core

- [X] Compressed Asset generation via 'make assets'

- [X] Oled SSD1305 display + Adafruit GFX

- [X] Migrate all MCL source code

- [X] Fix compliation errors

- [X] Fix linking

- [X] Sequencer

- [X] Verify user GUI (buttons + encoders)

- [X] Verify Page System

- [X] Verify Menus

- [X] Validate UART and timer IRQ timings.

- [X] MCL project/grid initialisation

- [X] Object serialisation to/from SD Card

- [X] Port to platformio

- [X] Integrate with TBD hardware libraries

#Todo

- [ ] Backport refactor to main MCL github repo.  Preserve git history.
