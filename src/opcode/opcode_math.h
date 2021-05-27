#ifndef OPCODE_MATH_H
#define OPCODE_MATH_H

#include "opcode.h"

#include <stdint.h>

#define G_OPCODE_GROUP_MATH UINT32_C(0x00010000)

static inline void g_opcode_math(Getriebe * getriebe, G_Opcode opcode)
{
    uint8_t register_a = (uint8_t) getriebe_read_next_cell(getriebe);
    uint8_t register_b = (uint8_t) getriebe_read_next_cell(getriebe);

    switch (opcode)
    {
        case G_OPCODE_ADD:
            getriebe->registers[register_a] += getriebe->registers[register_b];
            break;
        case G_OPCODE_SUB:
            getriebe->registers[register_a] -= getriebe->registers[register_b];
            break;
        default:
            break;
    }
}

#endif