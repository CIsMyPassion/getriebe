#ifndef BRANCH_LINK_H
#define BRANCH_LINK_H

#include <stdio.h>
#include <assert.h>
#include <getriebe.h>

static Getriebe br_vm;

static void internal_test_l_alw()
{
	printf("Start condition alw test\n");

	G_Opcode_Branch l_alw;
	l_alw.id = G_OPCODE_BRANCH_ID;
	l_alw.mode = G_BRANCH_MODE_BRL;
	l_alw.condition = G_BRANCH_CONDITION_ALW;
	l_alw.immediate = 0;
	l_alw.destination_address_register = G_REGISTER_0;
	uint32_t branch_address = 0xff;

	getriebe_init(&br_vm, &(l_alw.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_alw.destination_address_register = G_REGISTER_11;
	branch_address = 0xce8a;

	getriebe_init(&br_vm, &(l_alw.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_11, branch_address);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Condition alw tested\n");
}

static void internal_test_l_pos()
{
	printf("Start condition pos test\n");

	G_Opcode_Branch l_pos;
	l_pos.id = G_OPCODE_BRANCH_ID;
	l_pos.mode = G_BRANCH_MODE_BRL;
	l_pos.condition = G_BRANCH_CONDITION_POS;
	l_pos.immediate = 0;
	l_pos.destination_address_register = G_REGISTER_0;
	l_pos.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(l_pos.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_pos.destination_address_register = G_REGISTER_7;
	l_pos.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 255;

	getriebe_init(&br_vm, &(l_pos.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Condition pos tested\n");
}

static void internal_test_l_neg()
{
	printf("Start condition neg test\n");

	G_Opcode_Branch l_neg;
	l_neg.id = G_OPCODE_BRANCH_ID;
	l_neg.mode = G_BRANCH_MODE_BRL;
	l_neg.condition = G_BRANCH_CONDITION_NEG;
	l_neg.immediate = 0;
	l_neg.destination_address_register = G_REGISTER_0;
	l_neg.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(l_neg.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_neg.destination_address_register = G_REGISTER_7;
	l_neg.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 255;

	getriebe_init(&br_vm, &(l_neg.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Condition neg tested\n");
}

static void internal_test_l_zro()
{
	printf("Start condition zro test\n");

	G_Opcode_Branch l_zro;
	l_zro.id = G_OPCODE_BRANCH_ID;
	l_zro.mode = G_BRANCH_MODE_BRL;
	l_zro.condition = G_BRANCH_CONDITION_ZRO;
	l_zro.immediate = 0;
	l_zro.destination_address_register = G_REGISTER_0;
	l_zro.compare_register_0 = G_REGISTER_1;
	uint32_t branch_address = 0xff;
	uint32_t compare_value = (int32_t) -255;

	getriebe_init(&br_vm, &(l_zro.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_zro.destination_address_register = G_REGISTER_7;
	l_zro.compare_register_0 = G_REGISTER_13;
	branch_address = 0xce8a;
	compare_value = (int32_t) 0;

	getriebe_init(&br_vm, &(l_zro.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Condition zro tested\n");
}

static void internal_test_l_eql()
{
	printf("Start condition eql test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_eql;
	l_eql.id = G_OPCODE_BRANCH_ID;
	l_eql.mode = G_BRANCH_MODE_BRL;
	l_eql.condition = G_BRANCH_CONDITION_EQL;
	l_eql.immediate = 0;
	l_eql.destination_address_register = G_REGISTER_0;
	l_eql.compare_register_0 = G_REGISTER_1;
	l_eql.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_eql.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_eql.destination_address_register = G_REGISTER_7;
	l_eql.compare_register_0 = G_REGISTER_13;
	l_eql.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	getriebe_init(&br_vm, &(l_eql.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_eql.immediate = 1;
	l_eql.destination_address_register = G_REGISTER_0;
	l_eql.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_eql.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_eql.destination_address_register = G_REGISTER_7;
	l_eql.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	code[0] = l_eql.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	printf("Immediate mode tested\n");
	printf("Condition eql tested\n");
}

static void internal_test_l_neq()
{
	printf("Start condition neq test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_neq;
	l_neq.id = G_OPCODE_BRANCH_ID;
	l_neq.mode = G_BRANCH_MODE_BRL;
	l_neq.condition = G_BRANCH_CONDITION_NEQ;
	l_neq.immediate = 0;
	l_neq.destination_address_register = G_REGISTER_0;
	l_neq.compare_register_0 = G_REGISTER_1;
	l_neq.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_neq.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_neq.destination_address_register = G_REGISTER_7;
	l_neq.compare_register_0 = G_REGISTER_13;
	l_neq.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	getriebe_init(&br_vm, &(l_neq.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_neq.immediate = 1;
	l_neq.destination_address_register = G_REGISTER_0;
	l_neq.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_neq.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_neq.destination_address_register = G_REGISTER_7;
	l_neq.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 0;
	compare_value_1 = (int32_t) 255;

	code[0] = l_neq.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition neq tested\n");
}

static void internal_test_l_grt()
{
	printf("Start condition grt test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_grt;
	l_grt.id = G_OPCODE_BRANCH_ID;
	l_grt.mode = G_BRANCH_MODE_BRL;
	l_grt.condition = G_BRANCH_CONDITION_GRT;
	l_grt.immediate = 0;
	l_grt.destination_address_register = G_REGISTER_0;
	l_grt.compare_register_0 = G_REGISTER_1;
	l_grt.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_grt.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_grt.destination_address_register = G_REGISTER_7;
	l_grt.compare_register_0 = G_REGISTER_13;
	l_grt.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(l_grt.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_grt.immediate = 1;
	l_grt.destination_address_register = G_REGISTER_0;
	l_grt.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_grt.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_grt.destination_address_register = G_REGISTER_7;
	l_grt.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	code[0] = l_grt.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition grt tested\n");
}

static void internal_test_l_sml()
{
	printf("Start condition sml test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_sml;
	l_sml.id = G_OPCODE_BRANCH_ID;
	l_sml.mode = G_BRANCH_MODE_BRL;
	l_sml.condition = G_BRANCH_CONDITION_SML;
	l_sml.immediate = 0;
	l_sml.destination_address_register = G_REGISTER_0;
	l_sml.compare_register_0 = G_REGISTER_1;
	l_sml.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_sml.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_sml.destination_address_register = G_REGISTER_7;
	l_sml.compare_register_0 = G_REGISTER_13;
	l_sml.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(l_sml.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_sml.immediate = 1;
	l_sml.destination_address_register = G_REGISTER_0;
	l_sml.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_sml.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) != branch_address);

	l_sml.destination_address_register = G_REGISTER_7;
	l_sml.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	code[0] = l_sml.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition sml tested\n");
}

static void internal_test_l_gre()
{
	printf("Start condition gre test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_gre;
	l_gre.id = G_OPCODE_BRANCH_ID;
	l_gre.mode = G_BRANCH_MODE_BRL;
	l_gre.condition = G_BRANCH_CONDITION_GRE;
	l_gre.immediate = 0;
	l_gre.destination_address_register = G_REGISTER_0;
	l_gre.compare_register_0 = G_REGISTER_1;
	l_gre.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_gre.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_gre.destination_address_register = G_REGISTER_7;
	l_gre.compare_register_0 = G_REGISTER_13;
	l_gre.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(l_gre.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_gre.immediate = 1;
	l_gre.destination_address_register = G_REGISTER_0;
	l_gre.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_gre.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_gre.destination_address_register = G_REGISTER_7;
	l_gre.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) 255;
	compare_value_1 = (int32_t) 0;

	code[0] = l_gre.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition gre tested\n");
}

static void internal_test_l_sme()
{
	printf("Start condition sme test\n");
	printf("Test non immediate mode\n");

	G_Opcode_Branch l_sme;
	l_sme.id = G_OPCODE_BRANCH_ID;
	l_sme.mode = G_BRANCH_MODE_BRL;
	l_sme.condition = G_BRANCH_CONDITION_SME;
	l_sme.immediate = 0;
	l_sme.destination_address_register = G_REGISTER_0;
	l_sme.compare_register_0 = G_REGISTER_1;
	l_sme.compare_register_1 = G_REGISTER_2;
	uint32_t branch_address = 0xff;
	uint32_t compare_value_0 = (int32_t) -255;
	uint32_t compare_value_1 = (int32_t) -255;

	getriebe_init(&br_vm, &(l_sme.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_2, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_sme.destination_address_register = G_REGISTER_7;
	l_sme.compare_register_0 = G_REGISTER_13;
	l_sme.compare_register_1 = G_REGISTER_6;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	getriebe_init(&br_vm, &(l_sme.value), 0, 1);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);
	getriebe_write_register(&br_vm, G_REGISTER_6, compare_value_1);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Non immediate mode tested\n");
	printf("Test immediate mode\n");

	l_sme.immediate = 1;
	l_sme.destination_address_register = G_REGISTER_0;
	l_sme.compare_register_0 = G_REGISTER_1;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) -255;

	uint32_t code[] = {
		l_sme.value,
		compare_value_1
	};

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_0, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_1, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	l_sme.destination_address_register = G_REGISTER_7;
	l_sme.compare_register_0 = G_REGISTER_13;
	compare_value_0 = (int32_t) -255;
	compare_value_1 = (int32_t) 0;

	code[0] = l_sme.value;
	code[1] = compare_value_1;

	getriebe_init(&br_vm, code, 0, 2);
	getriebe_write_register(&br_vm, G_REGISTER_7, branch_address);
	getriebe_write_register(&br_vm, G_REGISTER_13, compare_value_0);

	getriebe_execute_next_instruction(&br_vm);

	assert(getriebe_read_register(&br_vm, G_REGISTER_PC) == branch_address);

	printf("Immediate mode tested\n");
	printf("Condition sme tested\n");
}

static void internal_test_link_branch()
{
	printf("Start non link opcodes\n");
	
	internal_test_l_alw();
	internal_test_l_pos();
	internal_test_l_neg();
	internal_test_l_zro();
	internal_test_l_eql();
	internal_test_l_neq();
	internal_test_l_grt();
	internal_test_l_sml();
	internal_test_l_gre();
	internal_test_l_sme();

	printf("Non link opcodes tested\n");
}

#endif
