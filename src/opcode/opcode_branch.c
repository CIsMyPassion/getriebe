#include "opcode.h"


static void internal_handle_non_link_branch(Getriebe * self, G_Opcode_Branch opcode)
{
	uint32_t destination_address = getriebe_read_register(self, opcode.destination_address_register);
	int32_t value_0 = (int32_t) getriebe_read_register(self, opcode.compare_register_0);
	int32_t value_1 = (int32_t) (opcode.immediate ?
				getriebe_read_next_cell(self) :
				getriebe_read_register(self, opcode.compare_register_1));

	switch (opcode.condition)
	{
		case G_BRANCH_CONDITION_ALW:
			break;
		case G_BRANCH_CONDITION_POS:
			if (value_0 <= 0)
				return;
			break;
		case G_BRANCH_CONDITION_NEG:
			if (value_0 >= 0)
				return;
			break;
		case G_BRANCH_CONDITION_ZRO:
			if (value_0 != 0)
				return;
			break;
		case G_BRANCH_CONDITION_EQL:
			if (value_0 != value_1)
				return;
			break;
		case G_BRANCH_CONDITION_NEQ:
			if (value_0 == value_1)
				return;
			break;
		case G_BRANCH_CONDITION_GRT:
			if (value_0 <= value_1)
				return;
			break;
		case G_BRANCH_CONDITION_SML:
			if (value_0 >= value_1)
				return;
			break;
		case G_BRANCH_CONDITION_GRE:
			if (value_0 < value_1)
				return;
			break;
		case G_BRANCH_CONDITION_SME:
			if (value_0 > value_1)
				return;
			break;
	}

	getriebe_write_register(self, G_REGISTER_PC, destination_address);
}

static void internal_handle_link_branch(Getriebe * self, G_Opcode_Branch opcode)
{
	uint32_t value_0 = getriebe_read_register(self, opcode.compare_register_0);
	uint32_t value_1;

	switch (opcode.immediate)
	{
		case 0:
			value_1 = getriebe_read_register(self, opcode.compare_register_1);
			break;
		case 1:
			value_1 = getriebe_read_next_cell(self);
			break;
	}

	uint32_t return_address = (getriebe_read_register(self, G_REGISTER_PC) + 1) + (opcode.immediate);
}

void opcode_branch_handle(Getriebe * self, uint32_t opcode)
{
	G_Opcode_Branch branch = { .value = opcode };

	switch (branch.mode)
	{
		case G_BRANCH_MODE_BR:
			internal_handle_non_link_branch(self, branch);
			break;
		case G_BRANCH_MODE_BRL:
			internal_handle_link_branch(self, branch);
			break;
	}
}
