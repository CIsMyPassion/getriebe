#ifndef OPCODE_BRANCH_TEST_H
#define OPCODE_BRANCH_TEST_H

#include <assert.h>

#include <getriebe.h>

static Getriebe br_vm;

static void internal_test_nl_alw()
{
	G_Opcode_Branch nl_alw;
	nl_alw.id = G_OPCODE_BRANCH_ID;
	nl_alw.mode = G_BRANCH_MODE_BR;
	nl_alw.condition = G_BRANCH_CONDITION_ALW;
	nl_alw.immediate = 0;
	nl_alw.destination_address_register = G_REGISTER_0;
	uint32_t branch_address = 0xff;

	getriebe_init(&br_vm, &(nl_alw.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_alw.destination_address_register = G_REGISTER_11;
	branch_address = 0xce8a;

	getriebe_init(&br_vm, &(nl_alw.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_11, branch_address);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);
}

static void internal_test_nl_pos()
{
	G_Opcode_Branch nl_pos;
	nl_pos.id = G_OPCODE_BRANCH_ID;
	nl_pos.mode = G_BRANCH_MODE_BR;
	nl_pos.condition = G_BRANCH_CONDITION_ALW;
	nl_pos.immediate = 0;
	nl_pos.destination_address_register = G_REGISTER_0;
	nl_pos.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_pos.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_pos.destination_address_register = G_REGISTER_7;
	nl_pos.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 255;

	getriebe_init(&br_vm, &(nl_pos.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);
}

static void internal_test_non_link_branch()
{
	printf("Start non link opcodes\n");

	internal_test_nl_alw();
	internal_test_nl_pos();
}

void opcode_branch_test()
{
	printf("opcode_branch_test started\n");
	assert(sizeof(G_Opcode_Branch) == sizeof(uint32_t));
	printf("G_Opcode_Branch size is correct\n");

	internal_test_non_link_branch();
}

#endif