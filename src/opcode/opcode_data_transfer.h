#ifndef OPCODE_DATA_TRANSFER_H
#define OPCODE_DATA_TRANSFER_H

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
        uint8_t pre_post_indexing : 1;
        uint8_t up_down : 1;
        uint8_t byte_word : 1;
        uint8_t write_back : 1;
        uint8_t load_store : 1;
        uint8_t base : 4;
        uint8_t source_destination : 4;
        uint16_t source_1 : 11;
    };
} G_Opcode_Data_Transfer;

void opcode_data_transfer_handle(Getriebe * self, uint32_t opcode);

#endif
