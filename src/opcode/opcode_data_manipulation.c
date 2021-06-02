#include "opcode_data_manipulation.h"

#include "../../include/getriebe.h"

void opcode_data_manipulation_handle(Getriebe * self, uint32_t opcode)
{
    G_Opcode_Data_Manipulation operation = (G_Opcode_Data_Manipulation) { .value = opcode };

    switch (operation.immediate)
    {
    case 0:
        break;
    case 1:
        break; 
    }
}


