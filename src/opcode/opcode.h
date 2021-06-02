#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef enum g_opcode
{
    G_OPCODE_AND = 0,
    G_OPCODE_EOR,
    G_OPCODE_SUB,
    G_OPCODE_RSB,
    G_OPCODE_ADD,
    G_OPCODE_ADC,
    G_OPCODE_SBC,
    G_OPCODE_RSC,
    G_OPCODE_TST,
    G_OPCODE_TEQ,
    G_OPCODE_CMP,
    G_OPCODE_CMN,
    G_OPCODE_ORR,
    G_OPCODE_MOV,
    G_OPCODE_BIC,
    G_OPCODE_MVN,
    G_OPCODE_MUL,
    G_OPCODE_MLA,
    G_OPCODE_LDR,
    G_OPCODE_STR,
    G_OPCODE_SWI
} G_Opcode;

static inline uint32_t g_opcode_get_group(G_Opcode opcode)
{
    return opcode & (uint32_t) 0xFFFF0000;
}

#endif
