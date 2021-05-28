#ifndef OPCODE_STORE_H
#define OPCODE_STORE_H

#include "opcode.h"

#include <stdint.h>

#define G_OPCODE_GROUP_STORE UINT32_C(0x00080000)

static inline void g_opcode_store(Getriebe * getriebe, G_Opcode opcode)
{
    uint8_t register_a = (uint8_t) getriebe_read_next_cell(getriebe);
    uint32_t operand_a = getriebe_read_next_cell(getriebe);
    uint32_t operand_b;

    switch (opcode)
    {
        case G_OPCODE_ST:
            getriebe->memory[operand_a] =
                    getriebe->registers[register_a];
            break;
        case G_OPCODE_STO:
            getriebe->memory[getriebe_read_register(getriebe, G_REGISTER_PC) + operand_a] =
                    getriebe->registers[register_a];
            break;
        case G_OPCODE_STR:
            operand_b = getriebe_read_next_cell(getriebe);
            getriebe->memory[getriebe->registers[register_a] + operand_b] =
                    getriebe->registers[(uint8_t) operand_a];
            break;
        case G_OPCODE_STI:
            getriebe->memory[getriebe_read_cell(getriebe, operand_a)] =
                    getriebe->registers[register_a];
            break;
        default:
            break;
    }
}

#endif