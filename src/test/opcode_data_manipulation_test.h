#ifndef OPCODE_DATA_MANIPULATION_TEST_H
#define OPCODE_DATA_MANIPULATION_TEST_H

#include <assert.h>

#include "../../include/getriebe.h"
#include "../opcode/opcode_data_manipulation.h"

static Getriebe getriebe;

static void opcode_and_test()
{
	G_Opcode_Data_Manipulation opcode = opcode_data_manipulation_create(0b1110, 0, G_DATA_MANIPULATION_MODE_AND, 1, (uint8_t) G_REGISTER_0, (uint8_t) G_REGISTER_1, (uint16_t) G_REGISTER_2);

	uint32_t and_test[] = {
		opcode.value
	};
	getriebe_init(&getriebe, and_test, 0, 1);
	getriebe_write_register(&getriebe, (uint8_t) G_REGISTER_0, 0b1101);
	getriebe_write_register(&getriebe, (uint8_t) G_REGISTER_2, 0b0111);
	getriebe_execute_next_instruction(&getriebe);
	
	getriebe_print_state(&getriebe);
	//assert(getriebe_read_register(&getriebe, (uint8_t) G_REGISTER_1) == (0b1101 & 0b0111));
}

static void opcode_data_manipulation_test()
{
	opcode_and_test();
}

#endif
