#include "../include/getriebe.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "opcode/opcode_math.h"
#include "opcode/opcode_logic.h"
#include "opcode/opcode_load.h"
#include "opcode/opcode_store.h"
#include "opcode/opcode_control.h"

static inline void internal_init_registers(uint32_t (* registers) [G_REGISTER_COUNT])
{
    memset(registers, 0, sizeof(uint32_t) * G_REGISTER_COUNT);
}

void getriebe_init(Getriebe * self, uint32_t * code, uint32_t code_start, uint32_t code_size)
{
    internal_init_registers(&(self->registers));
    self->program_counter = UINT16_MAX + 1;
    self->stack_pointer = UINT16_MAX;

    self->memory = malloc(sizeof(uint32_t) * GETRIEBE_MEMORY_SIZE);
    memcpy(self->memory + code_start, code, sizeof(uint32_t) * code_size);
    memset(self->memory, 0, sizeof(uint32_t) * code_start);
    memset(self->memory + (code_start + code_size), 0, sizeof(uint32_t) * (GETRIEBE_MEMORY_SIZE - (code_start + code_size) + 1));
}

void getriebe_execute(Getriebe * self, uint32_t start_address, uint32_t instructions)
{
    self->program_counter = start_address;

    while (instructions-- > 0)
        getriebe_execute_next_instruction(self);
}

void getriebe_execute_next_instruction(Getriebe * self)
{
    uint32_t opcode = getriebe_read_next_cell(self);

    switch (g_opcode_get_group(opcode))
    {
        case G_OPCODE_NOP:
            return;
        case G_OPCODE_GROUP_MATH:
            g_opcode_math(self, opcode);
            break;
        case G_OPCODE_GROUP_LOGIC:
            g_opcode_logic(self, opcode);
            break;
        case G_OPCODE_GROUP_LOAD:
            g_opcode_load(self, opcode);
            break;
        case G_OPCODE_GROUP_STORE:
            g_opcode_store(self, opcode);
            break;
        case G_OPCODE_GROUP_CONTROL:
            g_opcode_control(self, opcode);
            break;
    }
}

void getriebe_print_state(Getriebe * self)
{
    printf("getriebe %p\n", self);
    printf("r0:              %010"PRIu32"\n", self->registers[G_REGISTER_0]);
    printf("r1:              %010"PRIu32"\n", self->registers[G_REGISTER_1]);
    printf("r2:              %010"PRIu32"\n", self->registers[G_REGISTER_2]);
    printf("r3:              %010"PRIu32"\n", self->registers[G_REGISTER_3]);
    printf("program_counter: %010"PRIu32"\n", self->program_counter);
    printf("stack_pointer:   %010"PRIu32"\n", self->stack_pointer);
    printf("flags:           %08X\n", self->flags);
    printf("positive:        %d\n", (self->flags & 1 << 0) >> 0);
    printf("zero:            %d\n", (self->flags & 1 << 1) >> 1);
    printf("negative:        %d\n", (self->flags & 1 << 2) >> 2);
    printf("carry:           %d\n", (self->flags & 1 << 3) >> 3);
    printf("overflow:        %d\n", (self->flags & 1 << 4) >> 4);
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