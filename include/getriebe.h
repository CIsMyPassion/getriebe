#ifndef GETRIEBE_H
#define GETRIEBE_H

#include <stdint.h>

#define G_OPCODE_BRANCH_ID UINT32_C(0x0)

#define GETRIEBE_MEMORY_SIZE (UINT16_MAX + 1) * 4
#define GETRIEBE_STACK_SIZE UINT16_MAX + 1

// Opcode definitions

// branch
typedef enum g_branch_mode
{
	G_BRANCH_MODE_BR  = 0x0,
	G_BRANCH_MODE_BRL
} G_Branch_Mode;

typedef enum g_branch_condition
{
	G_BRANCH_CONDITION_ALW = 0x0,
	G_BRANCH_CONDITION_POS,
	G_BRANCH_CONDITION_NEG,
	G_BRANCH_CONDITION_ZRO,
	G_BRANCH_CONDITION_EQL,
	G_BRANCH_CONDITION_NEQ,
	G_BRANCH_CONDITION_GRT,
	G_BRANCH_CONDITION_SML,
	G_BRANCH_CONDITION_GRE,
	G_BRANCH_CONDITION_SME
} G_Branch_Condition;

#pragma pack(push, 1)
typedef union g_opcode_branch
{
	struct
	{
		uint32_t id : 4;
		G_Branch_Mode mode : 2;
		G_Branch_Condition condition : 5;
		uint32_t immediate : 1;
		uint32_t destination_address_register : 4;
		uint32_t compare_register_0 : 4;
		uint32_t compare_register_1 : 4;
		uint32_t unused : 8;
	};
	uint32_t value;
} G_Opcode_Branch;
#pragma pack(pop)

//data manipulation
typedef enum g_data_maipulation_mode
{
	G_DATA_MANIPULATION_MODE_AND = 0x0,
	G_DATA_MANIPULATION_MODE_EOR,
	G_DATA_MANIPULATION_MODE_SUB,
	G_DATA_MANIPULATION_MODE_RSB,
	G_DATA_MANIPULATION_MODE_ADD,
	G_DATA_MANIPULATION_MODE_ADC,
	G_DATA_MANIPULATION_MODE_SBC,
	G_DATA_MANIPULATION_MODE_RSC,
	G_DATA_MANIPULATION_MODE_ORR,
	G_DATA_MANIPULATION_MODE_MOV,
	G_DATA_MANIPULATION_MODE_BIC,
	G_DATA_MANIPULATION_MODE_MVN
} G_Data_Manipulation_Mode;

#pragma pack(push, 1)
typedef union
{
    uint32_t value;
    struct
    {
		uint32_t condition : 4;
        uint32_t identifier : 2;
        uint32_t immediate : 1;
		uint32_t opcode : 4;
		uint32_t set_condition : 1;
        uint32_t operand_0 : 4;
        uint32_t destination : 4;
        uint32_t operand_1 : 12;
    };
} G_Opcode_Data_Manipulation;
#pragma pack(pop)

typedef enum g_register
{
    G_REGISTER_0 = 0,
    G_REGISTER_1,
    G_REGISTER_2,
    G_REGISTER_3,
    G_REGISTER_4,
    G_REGISTER_5,
    G_REGISTER_6,
    G_REGISTER_7,
    G_REGISTER_8,
    G_REGISTER_9,
    G_REGISTER_10,
    G_REGISTER_11,
    G_REGISTER_12,
    G_REGISTER_13,
    G_REGISTER_PC,
    G_REGISTER_SP,
    G_REGISTER_COUNT
} G_Register;



typedef struct getriebe
{
    uint32_t registers[G_REGISTER_COUNT];
    uint32_t * memory;
	uint32_t * stack;
} Getriebe;

static inline uint32_t getriebe_read_register(Getriebe * self, uint32_t register_number)
{
    return self->registers[register_number];
}

static inline void getriebe_write_register(Getriebe * self, uint32_t register_number, uint32_t value)
{
    self->registers[register_number] = value;
}

static inline uint32_t getriebe_read_next_cell(Getriebe * self)
{
    return self->memory[self->registers[G_REGISTER_PC]++];
}

static inline uint32_t getriebe_read_cell(Getriebe * self, uint32_t address)
{
    return self->memory[address];
}

static inline void getriebe_write_cell(Getriebe * self, uint32_t address, uint32_t value)
{
    self->memory[address] = value;
}

void getriebe_init(Getriebe * self, uint32_t * code, uint32_t code_start, uint32_t code_size);

void getriebe_execute(Getriebe * self, uint32_t start_address, uint32_t instructions);
void getriebe_execute_next_instruction(Getriebe * self);

void getriebe_print_state(Getriebe * self);
void getriebe_print_memory(Getriebe * self, uint32_t start_address, uint32_t count);

#endif
