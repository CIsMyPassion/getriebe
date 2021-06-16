#ifndef OPCODE_DATA_MANIPULATION_TEST_H
#define OPCODE_DATA_MANIPULATION_TEST_H

#include <assert.h>

#include <getriebe.h>

static Getriebe getriebe;

static void opcode_and_test()
{

	uint32_t and_test[] = {
		0 //TODO
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
	assert(sizeof(G_Opcode_Data_Manipulation) == sizeof(uint32_t));

	//opcode_and_test();
}

#endif
