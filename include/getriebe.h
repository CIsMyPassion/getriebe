#ifndef GETRIEBE_H
#define GETRIEBE_H

#include <stdint.h>

#include "../src/opcode/opcode.h"

#define GETRIEBE_STACK_SIZE UINT16_MAX
#define GETRIEBE_MEMORY_SIZE UINT16_MAX * 4

typedef enum g_register
{
    G_REGISTER_0 = 0,
    G_REGISTER_1,
    G_REGISTER_2,
    G_REGISTER_3,
    G_REGISTER_COUNT
} G_Register;

typedef enum g_flags
{
    G_FLAG_POS = 1 << 0,
    G_FLAG_ZRO = 1 << 1,
    G_FLAG_NEG = 1 << 2,
    G_FLAG_CAR = 1 << 3,
    G_FLAG_OVF = 1 << 4
} G_Flags;

typedef struct getriebe
{
    uint32_t program_counter;
    uint16_t stack_pointer;
    uint32_t flags;
    uint32_t registers[G_REGISTER_COUNT];
    uint32_t * memory;
} Getriebe;

static inline uint32_t getriebe_read_next_cell(Getriebe * self)
{
    return self->memory[self->program_counter++];
}

static inline uint32_t getriebe_read_cell(Getriebe * self, uint32_t address)
{
    return self->memory[address];
}

void getriebe_init(Getriebe * self, uint32_t * code, uint32_t code_start, uint32_t code_size);

void getriebe_execute(Getriebe * self, uint32_t start_address, uint32_t instructions);
void getriebe_execute_next_instruction(Getriebe * self);

void getriebe_print_state(Getriebe * self);
void getriebe_print_memory(Getriebe * self, uint32_t start_address, uint32_t count);

#endif