#ifndef OPCODE_H
#define OPCODE_H

#include <stdint.h>

typedef enum g_opcode
{
    G_OPCODE_NOP = 0x00000000,
    G_OPCODE_ADD = 0x00010000,
    G_OPCODE_SUB = 0x00010001,
    G_OPCODE_AND = 0x00020000,
    G_OPCODE_OR  = 0x00020001,
    G_OPCODE_XOR = 0x00020002,
    G_OPCODE_NOT = 0x00020003,
    G_OPCODE_LD  = 0x00040000,
    G_OPCODE_LDO = 0x00040001,
    G_OPCODE_LDR = 0x00040002,
    G_OPCODE_LDI = 0x00040003,
    G_OPCODE_LEA = 0x00040004,
    G_OPCODE_ST  = 0x00080000,
    G_OPCODE_STO = 0x00080001,
    G_OPCODE_STR = 0x00080002,
    G_OPCODE_STI = 0x00080003,
    G_OPCODE_PSH = 0x000F0000,
    G_OPCODE_POP = 0x000F0001,
    G_OPCODE_JMP = 0x000F0002,
    G_OPCODE_BRZ = 0x000F0003,
    G_OPCODE_BRP = 0x000F0004,
    G_OPCODE_BRN = 0x000F0005,
    G_OPCODE_JSR = 0x000F0006,
    G_OPCODE_RTS = 0x000F0007,
    G_OPCODE_CLF = 0x000F0008
} G_Opcode_Dep;

typedef enum g_opcode
{
    G_OPCODE_AND = 0,
    G_OPCODE_EOR,
    G_OPCODE_SUB,
    G_OPCODE_RSB,
    G_OPCODE_ADD,
    G_OPCODE_ADC,
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
    G_OPCODE_MVN
} G_Opcode;

static inline uint32_t g_opcode_get_group(G_Opcode opcode)
{
    return opcode & (uint32_t) 0xFFFF0000;
}

#endif