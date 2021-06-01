#ifndef OPCODE_SOFTWARE_INTERRUPT_H
#define OPCODE_SOFTWARE_INTERRUPT_H

#include "../../include/getriebe.h"

typedef union
{
    uint32_t value;
    struct
    {
        uint8_t condition : 4;  
        uint8_t opcode : 4;
        uint32_t comment_field : 24;
    };
} G_Opcode_Multiply;

void opcode_software_interrupt_handle(Getriebe * self, uint32_t opcode);

#endif