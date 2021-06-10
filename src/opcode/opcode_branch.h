#ifndef OPCODE_BRANCH_H
#define OPCODE_BRANCH_H

#include <stdint.h>

#define G_OPCODE_BRANCH_ID UINT32_C(0x0)

typedef struct getriebe Getriebe;

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
typedef union
{
	struct
	{
		uint32_t id : 4;
		G_Branch_Mode mode : 1;
		G_Branch_Condition condition : 5;
		uint32_t immediate : 1;
		uint32_t destination_address_register : 4;
		uint32_t compare_register_0 : 4;
		uint32_t compare_register_1 : 4;
		uint32_t unused : 9;
	};
	uint32_t value;
} G_Opcode_Branch;
#pragma pack(pop)

void opcode_branch_handle(Getriebe * self, uint32_t opcode);

#endif
