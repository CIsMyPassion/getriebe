#ifndef OPCODE_MULTIPLY_H
#define OPCODE_MULTIPLY_H

#include<stdint.h>

typedef struct getriebe Getriebe;

typedef union
{
    uint32_t value;
    struct
    {
        uint8_t opcode : 7;
        uint8_t accumulate : 1;
        uint8_t destination : 4;
        uint8_t source_0 : 4;
        uint8_t source_1 : 4;
        uint8_t source_2 : 4;
    };
} G_Opcode_Multiply;

void opcode_multiply_handle(Getriebe * self, uint32_t opcode);

#endif
