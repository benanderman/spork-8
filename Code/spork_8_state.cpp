#include "spork_8_state.h"
#include "instructions.h"
#include "instruction_set.h"
#include "signals.h"

// #undef uint8_t
// #undef uint16_t
// #undef bool

// #include <iostream>

void spork8_state_reset(Spork8State *state) {
  state->inst_reg = 0;
  state->flags_reg = 0;
  state->mi_counter = 0;
  state->bus = 0;
  for (int i = 0; i < sizeof(state->module_values) / sizeof(*state->module_values); i++) {
    state->module_values[i] = 0;
  }
}

void spork8_state_cycle(Spork8State *state) {
  Instruction instruction = getInstruction(state->inst_reg);
  // Flags is actually an enum representing the 4 possible states of the flags register.
  uint8_t flags = 1 << state->flags_reg;
  uint16_t microcode = instruction.microCodeForCycleFlags(state->mi_counter, flags);
  uint8_t out_index = (microcode >> 12) & 0xF;
  uint8_t in_index  = (microcode >>  8) & 0xF;

  // fprintf(stderr, "Cycle %p:%p [%p] ", state->module_values[PCNT], state->mi_counter, microcode);
  // fprintf(stderr, "inst(%p) out(%p) in(%p) bus(%p) flags(%p)\n", state->inst_reg, out_index, in_index, state->bus, state->flags_reg);

  // Cycle the out index first, to write to the bus.
  state->bus = 0;
  spork8_state_cycle_module(state, out_index, spork8_state_signals_for_module(state, out_index, microcode));

  uint8_t module_count = sizeof(state->module_values) / sizeof(*state->module_values);
  for (uint8_t i = 0; i < module_count; i++) {
    if (i == out_index) continue;
    ModuleSignals signals = spork8_state_signals_for_module(state, i, microcode);
    spork8_state_cycle_module(state, i, signals);
  }

  state->mi_counter++;
  if (microcode & MI_RESET) state->mi_counter = 0;
  if ((microcode & INST_IN) == 0) state->inst_reg = state->bus;
  if (in_index == ALU) state->flags_reg = (state->bus & 0b11);
}

void spork8_state_cycle_module(Spork8State *state, uint8_t index, ModuleSignals signals) {
  if (!(signals.in || signals.out || signals.sig0 || signals.sig1)) {
    return;
  }
  ModuleType type = spork8_state_module_type_at_index(index);
  switch (type) {
    case none: {
      return;
    }
    case reg: {
      if (!(signals.in || signals.out)) return;
      // std::cerr << "Cycling reg " << (int)index << (signals.out ? " OUT" : "") << (signals.in ? " IN" : "") << "\n";
      if (signals.out) state->bus = state->module_values[index];
      if (signals.in)  state->module_values[index] = state->bus;
      return;
    }
    case counter: {
      // fprintf(stderr, "Cycling counter (%d) %s%s%s%s\n", index, signals.out ? " OUT" : "", signals.in ? " IN" : "", signals.sig0 ? " COUNT" : "", signals.sig1 ? " BSEL" : "");
      uint8_t byte_offset = signals.sig1 ? 8 : 0;
      if (signals.out) state->bus = (state->module_values[index] >> byte_offset) & 0xFF;
      if (signals.sig0) {
        state->module_values[index]++;
      }
      if (signals.in) {
        // This mask is for the byte we're not setting.
        uint16_t byte_mask = signals.sig1 ? 0x00FF : 0xFF00;
        state->module_values[index] = (state->module_values[index] & byte_mask) | ((uint16_t)state->bus << byte_offset);
      }
      return;
    }
    case memory: {
      if (!(signals.in || signals.out)) return;
      // std::cerr << "Cycling memory " << (int)index << (signals.out ? " OUT" : "") << (signals.in ? " IN" : "") << "\n";
      uint8_t address_module = spork8_state_input1_module_index_for_index(index);
      uint16_t address = state->module_values[address_module];
      uint8_t (*get_memory_func)(uint16_t) = index == PMEM ? state->get_progmem_byte : state->get_ram_byte;
      if (signals.out && get_memory_func) {
        state->bus = get_memory_func(address);
      }
      if (signals.in && index == SRAM && state->set_ram_byte) {
        state->set_ram_byte(address, state->bus);
        // memory[address] = state->bus;
      }
      return;
    }
    case alu: {
      if (!(signals.in || signals.out)) return;
      // fprintf(stderr, "Cycling ALU %p%s%s %d/%d\n", index, signals.out ? " OUT" : "", signals.in ? " IN" : "", signals.sig0, signals.sig1);
      uint8_t input_module1 = spork8_state_input1_module_index_for_index(index);
      uint8_t input_module2 = spork8_state_input2_module_index_for_index(index);
      if (signals.out) {
        uint8_t value1 = state->module_values[input_module1];
        uint8_t value2 = state->module_values[input_module2];
        uint8_t out_value = 0;
        bool overflow = false;
        if (signals.sig1) {
          out_value = value1 & value2;
          // fprintf(stderr, "ALU: %p & %p = %p\n", value1, value2, out_value);
        } else {
          out_value = signals.sig0 ? (value1 - value2) : (value1 + value2);
          overflow = out_value < value1;
          overflow = signals.sig0 ? !overflow : overflow;
          // fprintf(stderr, "ALU: %d %s %d = %d\n", value1, signals.sig0 ? "-" : "+", value2, out_value);
        }
        if (signals.in) {
          bool is_zero = out_value == 0;
          out_value = (out_value & ~0b01) | (overflow ? 0b01 : 0);
          out_value = (out_value & ~0b10) | (is_zero  ? 0b10 : 0);
          // fprintf(stderr, "ALU flags: %p\n", out_value);
        }
        state->bus = out_value;
      }
      return;
    }
    case shift: {
      if (!(signals.in || signals.out)) return;
      // std::cerr << "Cycling shift " << (int)index << (signals.out ? " OUT" : "") << (signals.in ? " IN" : "") << "\n";
      uint8_t input_module = spork8_state_input1_module_index_for_index(index);
      uint8_t input_value = state->module_values[input_module];
      if (signals.out) {
        bool right = signals.sig0;
        bool rotate = signals.sig1;
        uint8_t out_value = right ? (input_value >> 1) : (input_value << 1);
        if (rotate) {
          out_value |= right ? (input_value << 7) : (input_value >> 7);
        }
        state->bus = out_value;
      }
      return;
    }
    case input_output: {
      if (!(signals.in || signals.out)) return;
      uint8_t in_value = spork8_state_get_input_value(state, index);
      // fprintf(stderr, "Cycling IO %p%s%s %p\n", index, (signals.out ? " OUT" : ""), (signals.in ? " IN" : ""), in_value);
      if (signals.out) state->bus = in_value;
      if (signals.in)  spork8_state_set_output_value(state, index, state->bus);
      return;
    }
  }
}

uint8_t spork8_state_get_input_value(Spork8State *state, uint8_t module_index) {
  return state->module_values[module_index] >> 8;
}

uint8_t spork8_state_get_output_value(Spork8State *state, uint8_t module_index) {
  return state->module_values[module_index] & 0xFF;
}

void spork8_state_set_input_value(Spork8State *state, uint8_t module_index, uint8_t value) {
  state->module_values[module_index] = (state->module_values[module_index] & 0x00FF) | ((uint16_t)value << 8);
  // fprintf(stderr, "Set input value to %p (%p)\n", value, state->module_values[module_index]);
}

void spork8_state_set_output_value(Spork8State *state, uint8_t module_index, uint8_t value) {
  state->module_values[module_index] = (state->module_values[module_index] & 0xFF00) | (value & 0xFF);
  // fprintf(stderr, "Set output value to %p (%p)\n", value, state->module_values[module_index]);
}

ModuleType spork8_state_module_type_at_index(uint8_t index) {
  switch (index) {
    case ZERO: return none;
    case STCK: return reg;
    case OUTA: return reg;
    case SRAM: return memory;
    case SWAP: return reg;
    case IOA:  return input_output;
    case MADR: return counter;
    case IOB:  return input_output;

    case CLCK: return none;
    case REGC: return reg;
    case REGB: return reg;
    case SHFT: return shift;
    case PCNT: return counter;
    case PMEM: return memory;
    case REGA: return reg;
    case ALU:  return alu;
  }
  return none;
}


uint8_t spork8_state_input1_module_index_for_index(uint8_t index) {
  switch (index) {
    case ALU:  return REGA;
    case SRAM: return MADR;
    case PMEM: return PCNT;
    case SHFT: return REGB;
  }
  return ZERO;
}
uint8_t spork8_state_input2_module_index_for_index(uint8_t index) {
  if (index == ALU) return REGB;
  return ZERO;
}

ModuleSignals spork8_state_signals_for_module(Spork8State *state, uint8_t index, uint16_t global_signals) {
  uint8_t out_index = (global_signals >> 12) & 0xF;
  uint8_t in_index  = (global_signals >>  8) & 0xF;

  uint8_t cpu_side_offset   = (index & 0b0001) ? 0 : 4;
  uint8_t top_bottom_offset = (index & 0b1000) ? 2 : 0;

  ModuleSignals signals = {
    .out = index == out_index,
    .in = index == in_index,
    .sig0 = (global_signals >> (cpu_side_offset + top_bottom_offset + 0) & 1) == 1,
    .sig1 = (global_signals >> (cpu_side_offset + top_bottom_offset + 1) & 1) == 1,
  };
  return signals;
}
