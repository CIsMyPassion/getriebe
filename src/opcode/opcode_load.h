#ifndef OPCODE_LOAD_H
#define OPCODE_LOAD_H

#include "opcode.h"

#include <stdint.h>

#define G_OPCODE_GROUP_LOAD UINT32_C(0x00040000)

static inline void g_opcode_load(Getriebe * getriebe, G_Opcode opcode)
{
    uint8_t register_a = (uint8_t) getriebe_read_next_cell(getriebe);
    uint32_t operand_a = getriebe_read_next_cell(getriebe);
    uint32_t operand_b;

    switch (opcode)
    {
        case G_OPCODE_LD:
            getriebe->registers[register_a] = operand_a;
            break;
        case G_OPCODE_LDO:
            getriebe->registers[register_a] =
                    getriebe_read_cell(getriebe, getriebe_read_register(getriebe, G_REGISTER_PC) + operand_a);
            break;
        case G_OPCODE_LDR:
            operand_b = getriebe_read_next_cell(getriebe);
            getriebe->registers[register_a] =
                    getriebe_read_cell(getriebe, getriebe->registers[(uint8_t) operand_a] + operand_b);
            break;
        case G_OPCODE_LDI:
            getriebe->registers[register_a] =
                    getriebe_read_cell(getriebe, getriebe_read_cell(getriebe, operand_a));
            break;
        case G_OPCODE_LEA:
            getriebe->registers[register_a] =
                    getriebe_read_register(getriebe, G_REGISTER_PC) + operand_a;
            break;
        default:
            break;
    }
}

#endif