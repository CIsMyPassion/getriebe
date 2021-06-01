#ifndef OPCODE_ADD_H
#define OPCODE_ADD_H

#include "../../include/getriebe.h"

typedef union
{
    uint32_t value;
    struct
    {
        uint8_t opcode : 7;
        uint8_t immediate : 1;
        uint8_t destination : 4;
        uint8_t source_0 : 4;
        uint16_t source_1;
    };
} G_Opcode_Data_Manipulation;

void opcode_data_manipulation_handle(Getriebe * self, uint32_t opcode);

#endif