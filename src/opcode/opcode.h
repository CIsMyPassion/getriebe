#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef enum g_opcode
{
    G_OPCODE_AND = 0x00000000,
    G_OPCODE_EOR = 0x00200000,
    G_OPCODE_SUB = 0x00400000,
    G_OPCODE_RSB = 0x00600000,
    G_OPCODE_ADD = 0x00800000,
    G_OPCODE_ADC = 0x00a00000,
    G_OPCODE_SBC = 0x00c00000,
    G_OPCODE_RSC = 0x00e00000,
    G_OPCODE_TST = 0x01000000,
    G_OPCODE_TEQ = 0x01200000,
    G_OPCODE_CMP = 0x01400000,
    G_OPCODE_CMN = 0x01600000,
    G_OPCODE_ORR = 0x01800000,
    G_OPCODE_MOV = 0x01a00000,
    G_OPCODE_BIC = 0x01c00000,
    G_OPCODE_MVN = 0x01e00000,
    G_OPCODE_MUL = 0x00000090,
    G_OPCODE_MLA = 0x00200090,
    G_OPCODE_LDR = 0x02080000,
    G_OPCODE_STR = 0x02000000,
	G_OPCODE_BR  = 0x05000000,
	G_OPCODE_BRL = 0x05800000,
    G_OPCODE_SWI = 0x07800000
} G_Opcode;

static inline uint32_t g_opcode_get_id(uint32_t opcode)
{
    return opcode & 0xF0000000;
}

static inline uint32_t g_opcode_get_group(G_Opcode opcode)
{
    return opcode & (uint32_t) 0xFFFF0000;
}

#endif
