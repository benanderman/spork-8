#ifndef _SPORK_8_STATE
#define _SPORK_8_STATE

#include "signals.h"

#ifndef uint8_t
#define uint8_t unsigned char
#endif
#ifndef uint16_t
#define uint16_t unsigned short
#endif

#ifndef bool
#define bool unsigned char
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Only includes modules that have logic to be emulated (no clock or battery).
typedef enum ModuleType {
  none,
  reg,
  counter,
  memory,
  alu,
  shift,
  input_output
} __attribute__((packed)) ModuleType;

typedef struct ModuleSignals {
  bool out;
  bool in;
  bool sig0;
  bool sig1;
} __attribute__((packed)) ModuleSignals;

// This struct stores the state of a Spork-8, for the purposes of emulating it.
// The functions below have the logic to cycle it.
typedef struct Spork8State {
  uint16_t module_values[16];
  uint8_t inst_reg;
  uint8_t flags_reg;
  uint8_t mi_counter;
  uint8_t bus;

  uint8_t (*get_progmem_byte)(uint16_t address);
  uint8_t (*get_ram_byte)(uint16_t address);
  void (*set_ram_byte)(uint16_t address, uint8_t value);
} Spork8State;

void spork8_state_reset(Spork8State *state);

void spork8_state_cycle(Spork8State *state);
void spork8_state_cycle_module(Spork8State *state, uint8_t index, ModuleSignals signals);

ModuleType spork8_state_module_type_at_index(uint8_t index);
uint8_t spork8_state_input1_module_index_for_index(uint8_t index);
uint8_t spork8_state_input2_module_index_for_index(uint8_t index);
ModuleSignals spork8_state_signals_for_module(Spork8State *state, uint8_t index, uint16_t global_signals);

// Interface with IO modules
uint8_t spork8_state_get_input_value(Spork8State *state, uint8_t module_index);
uint8_t spork8_state_get_output_value(Spork8State *state, uint8_t module_index);
void spork8_state_set_input_value(Spork8State *state, uint8_t module_index, uint8_t value);
void spork8_state_set_output_value(Spork8State *state, uint8_t module_index, uint8_t value);

#ifdef __cplusplus
}
#endif

#endif