#ifndef OPCODE_BRANCH_TEST_H
#define OPCODE_BRANCH_TEST_H

#include <assert.h>
#include <stddef.h>

#include <getriebe.h>

static Getriebe br_vm;

static void internal_test_nl_alw()
{
	printf("Start condition alw test\n");

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

	printf("Condition alw tested\n");
}

static void internal_test_nl_pos()
{
	printf("Start condition pos test\n");

	G_Opcode_Branch nl_pos;
	nl_pos.id = G_OPCODE_BRANCH_ID;
	nl_pos.mode = G_BRANCH_MODE_BR;
	nl_pos.condition = G_BRANCH_CONDITION_POS;
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

	printf("Condition pos tested\n");
}

static void internal_test_nl_neg()
{
	printf("Start condition neg test\n");

	G_Opcode_Branch nl_neg;
	nl_neg.id = G_OPCODE_BRANCH_ID;
	nl_neg.mode = G_BRANCH_MODE_BR;
	nl_neg.condition = G_BRANCH_CONDITION_NEG;
	nl_neg.immediate = 0;
	nl_neg.destination_address_register = G_REGISTER_0;
	nl_neg.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_neg.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_neg.destination_address_register = G_REGISTER_7;
	nl_neg.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 255;

	getriebe_init(&br_vm, &(nl_neg.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Condition neg tested\n");
}

static void internal_test_nl_zro()
{
	printf("Start condition zro test\n");

	G_Opcode_Branch nl_zro;
	nl_zro.id = G_OPCODE_BRANCH_ID;
	nl_zro.mode = G_BRANCH_MODE_BR;
	nl_zro.condition = G_BRANCH_CONDITION_ZRO;
	nl_zro.immediate = 0;
	nl_zro.destination_address_register = G_REGISTER_0;
	nl_zro.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_zro.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_zro.destination_address_register = G_REGISTER_7;
	nl_zro.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 0;

	getriebe_init(&br_vm, &(nl_zro.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Condition zro tested\n");
}

static void internal_test_nl_eql()
{
	printf("Start condition eql test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_eql;
	nl_eql.id = G_OPCODE_BRANCH_ID;
	nl_eql.mode = G_BRANCH_MODE_BR;
	nl_eql.condition = G_BRANCH_CONDITION_EQL;
	nl_eql.immediate = 0;
	nl_eql.destination_address_register = G_REGISTER_0;
	nl_eql.compare_register_0 = G_REGISTER_1;
	nl_eql.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_eql.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_eql.destination_address_register = G_REGISTER_7;
	nl_eql.compare_register_0 = G_REGISTER_13;
	nl_eql.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	getriebe_init(&br_vm, &(nl_eql.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_eql.immediate = 1;
	nl_eql.destination_address_register = G_REGISTER_0;
	nl_eql.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_eql.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_eql.destination_address_register = G_REGISTER_7;
	nl_eql.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	code[0] = nl_eql.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Immediate mode tested\n");
	printf("Condition eql tested\n");
}

static void internal_test_nl_neq()
{
	printf("Start condition neq test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_neq;
	nl_neq.id = G_OPCODE_BRANCH_ID;
	nl_neq.mode = G_BRANCH_MODE_BR;
	nl_neq.condition = G_BRANCH_CONDITION_NEQ;
	nl_neq.immediate = 0;
	nl_neq.destination_address_register = G_REGISTER_0;
	nl_neq.compare_register_0 = G_REGISTER_1;
	nl_neq.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_neq.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_neq.destination_address_register = G_REGISTER_7;
	nl_neq.compare_register_0 = G_REGISTER_13;
	nl_neq.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	getriebe_init(&br_vm, &(nl_neq.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_neq.immediate = 1;
	nl_neq.destination_address_register = G_REGISTER_0;
	nl_neq.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_neq.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_neq.destination_address_register = G_REGISTER_7;
	nl_neq.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	code[0] = nl_neq.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition neq tested\n");
}

static void internal_test_nl_grt()
{
	printf("Start condition grt test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_grt;
	nl_grt.id = G_OPCODE_BRANCH_ID;
	nl_grt.mode = G_BRANCH_MODE_BR;
	nl_grt.condition = G_BRANCH_CONDITION_GRT;
	nl_grt.immediate = 0;
	nl_grt.destination_address_register = G_REGISTER_0;
	nl_grt.compare_register_0 = G_REGISTER_1;
	nl_grt.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_grt.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_grt.destination_address_register = G_REGISTER_7;
	nl_grt.compare_register_0 = G_REGISTER_13;
	nl_grt.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(nl_grt.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_grt.immediate = 1;
	nl_grt.destination_address_register = G_REGISTER_0;
	nl_grt.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_grt.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_grt.destination_address_register = G_REGISTER_7;
	nl_grt.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	code[0] = nl_grt.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition grt tested\n");
}

static void internal_test_nl_sml()
{
	printf("Start condition sml test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_sml;
	nl_sml.id = G_OPCODE_BRANCH_ID;
	nl_sml.mode = G_BRANCH_MODE_BR;
	nl_sml.condition = G_BRANCH_CONDITION_SML;
	nl_sml.immediate = 0;
	nl_sml.destination_address_register = G_REGISTER_0;
	nl_sml.compare_register_0 = G_REGISTER_1;
	nl_sml.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_sml.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_sml.destination_address_register = G_REGISTER_7;
	nl_sml.compare_register_0 = G_REGISTER_13;
	nl_sml.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(nl_sml.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_sml.immediate = 1;
	nl_sml.destination_address_register = G_REGISTER_0;
	nl_sml.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_sml.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	nl_sml.destination_address_register = G_REGISTER_7;
	nl_sml.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	code[0] = nl_sml.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition sml tested\n");
}

static void internal_test_nl_gre()
{
	printf("Start condition gre test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_gre;
	nl_gre.id = G_OPCODE_BRANCH_ID;
	nl_gre.mode = G_BRANCH_MODE_BR;
	nl_gre.condition = G_BRANCH_CONDITION_GRE;
	nl_gre.immediate = 0;
	nl_gre.destination_address_register = G_REGISTER_0;
	nl_gre.compare_register_0 = G_REGISTER_1;
	nl_gre.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_gre.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_gre.destination_address_register = G_REGISTER_7;
	nl_gre.compare_register_0 = G_REGISTER_13;
	nl_gre.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(nl_gre.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_gre.immediate = 1;
	nl_gre.destination_address_register = G_REGISTER_0;
	nl_gre.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_gre.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_gre.destination_address_register = G_REGISTER_7;
	nl_gre.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	code[0] = nl_gre.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition gre tested\n");
}

static void internal_test_nl_sme()
{
	printf("Start condition sme test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch nl_sme;
	nl_sme.id = G_OPCODE_BRANCH_ID;
	nl_sme.mode = G_BRANCH_MODE_BR;
	nl_sme.condition = G_BRANCH_CONDITION_SME;
	nl_sme.immediate = 0;
	nl_sme.destination_address_register = G_REGISTER_0;
	nl_sme.compare_register_0 = G_REGISTER_1;
	nl_sme.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(nl_sme.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_sme.destination_address_register = G_REGISTER_7;
	nl_sme.compare_register_0 = G_REGISTER_13;
	nl_sme.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(nl_sme.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	nl_sme.immediate = 1;
	nl_sme.destination_address_register = G_REGISTER_0;
	nl_sme.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		nl_sme.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	nl_sme.destination_address_register = G_REGISTER_7;
	nl_sme.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	code[0] = nl_sme.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition sme tested\n");
}

static void internal_test_non_link_branch()
{
	printf("Start non link opcodes\n");
	
	internal_test_nl_alw();
	internal_test_nl_pos();
	internal_test_nl_neg();
	internal_test_nl_zro();
	internal_test_nl_eql();
	internal_test_nl_neq();
	internal_test_nl_grt();
	internal_test_nl_sml();
	internal_test_nl_gre();
	internal_test_nl_sme();

	printf("Non link opcodes tested\n");
}

void opcode_branch_test()
{
	printf("opcode_branch_test started\n");
	assert(sizeof(G_Opcode_Branch) == sizeof(uint32_t));
	printf("G_Opcode_Branch size is correct\n");

	internal_test_non_link_branch();
}

#endif