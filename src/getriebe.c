#include "../include/getriebe.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "opcode/opcode.h"

static inline void internal_init_registers(uint32_t (* registers) [G_REGISTER_COUNT])
{
    memset(registers, 0, sizeof(uint32_t) * G_REGISTER_COUNT);
    (*registers)[G_REGISTER_SP] = UINT16_MAX;
}

void getriebe_init(Getriebe * self, uint32_t * code, uint32_t code_start, uint32_t code_size)
{
    internal_init_registers(&(self->registers));

    self->memory = malloc(sizeof(uint32_t) * GETRIEBE_MEMORY_SIZE);
    memcpy(self->memory + code_start, code, sizeof(uint32_t) * code_size);
    memset(self->memory, 0, sizeof(uint32_t) * code_start);
    memset(self->memory + (code_start + code_size), 0, sizeof(uint32_t) * (GETRIEBE_MEMORY_SIZE - (code_start + code_size) + 1));
}

void getriebe_execute(Getriebe * self, uint32_t start_address, uint32_t instructions)
{
    getriebe_write_register(self, G_REGISTER_PC, start_address);

    while (instructions-- > 0)
        getriebe_execute_next_instruction(self);
}

void getriebe_execute_next_instruction(Getriebe * self)
{
    uint32_t opcode = getriebe_read_next_cell(self);

    switch (g_opcode_get_id(opcode))
    {
        case G_OPCODE_BRANCH_ID:
            opcode_branch_handle(self, opcode);
            break;
        default:
            exit(EXIT_FAILURE);
    }
}

void getriebe_print_state(Getriebe * self)
{
    printf("getriebe %p\n", self);
    printf("r0:              %010"PRIu32"\n", self->registers[G_REGISTER_0]);
    printf("r1:              %010"PRIu32"\n", self->registers[G_REGISTER_1]);
    printf("r2:              %010"PRIu32"\n", self->registers[G_REGISTER_2]);
    printf("r3:              %010"PRIu32"\n", self->registers[G_REGISTER_3]);
    printf("program_counter: %010"PRIu32"\n", self->registers[G_REGISTER_PC]);
    printf("stack_pointer:   %010"PRIu32"\n", self->registers[G_REGISTER_SP]);
}

void getriebe_print_memory(Getriebe * self, uint32_t start_address, uint32_t count)
{
    printf("getriebe %p\n", self);

    for (uint32_t i = start_address; i < start_address + count; i += 16)
    {
        uint32_t * base_pointer = self->memory + i;
        printf("addr %08X vals %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X\n",
        i,
        *(base_pointer),
        *(base_pointer + 1),
        *(base_pointer + 2),
        *(base_pointer + 3),
        *(base_pointer + 4),
        *(base_pointer + 5),
        *(base_pointer + 6),
        *(base_pointer + 7),
        *(base_pointer + 8),
        *(base_pointer + 9),
        *(base_pointer + 10),
        *(base_pointer + 11),
        *(base_pointer + 12),
        *(base_pointer + 13),
        *(base_pointer + 14),
        *(base_pointer + 15)
        );        
    }
}
