#ifndef OPCODE_DATA_MANIPULATION_H
#define OPCODE_DATA_MANIPULATION_H

#include <stdint.h>

typedef struct getriebe Getriebe;

typedef union
{
    uint32_t value;
    struct
    {
		uint8_t condition : 4;
        uint8_t identifier : 2;
        uint8_t immediate : 1;
		uint8_t opcode : 4;
		uint8_t set_condition : 1;
        uint8_t operand_0 : 4;
        uint8_t destination : 4;
        uint16_t operand_1 : 12;
    };
} G_Opcode_Data_Manipulation;

void opcode_data_manipulation_handle(Getriebe * self, uint32_t opcode);

#endif
