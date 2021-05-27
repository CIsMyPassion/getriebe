#ifndef OPCODE_LOGIC_H
#define OPCODE_LOGIC_H

#include "opcode.h"

#include <stdint.h>

#define G_OPCODE_GROUP_LOGIC UINT32_C(0x00020000)

static inline void g_opcode_logic(Getriebe * getriebe, G_Opcode opcode)
{
    uint8_t register_a = (uint8_t) getriebe_read_next_cell(getriebe);
    uint8_t register_b;

    switch (opcode)
    {
        case G_OPCODE_AND:
            register_b = (uint8_t) getriebe_read_next_cell(getriebe);
            getriebe->registers[register_a] &= getriebe->registers[register_b];
            break;
        case G_OPCODE_OR:
            register_b = (uint8_t) getriebe_read_next_cell(getriebe);
            getriebe->registers[register_a] |= getriebe->registers[register_b];
            break;
        case G_OPCODE_XOR:
            register_b = (uint8_t) getriebe_read_next_cell(getriebe);
            getriebe->registers[register_a] ^= getriebe->registers[register_b];
            break;
        case G_OPCODE_NOT:
            getriebe->registers[register_a] = ~(getriebe->registers[register_a]);
            break;
        default:
            break;
    }
}

#endif