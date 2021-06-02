#include "../include/getriebe.h"

#include "opcode/opcode_data_manipulation.h"

Getriebe getriebe;

uint32_t code[] = {
};

uint32_t stack_test[] = {
};

int main()
{
    /*
    //getriebe_init(&getriebe, code, GETRIEBE_STACK_SIZE + 1, sizeof(code) / sizeof(uint32_t));
    getriebe_init(&getriebe, stack_test, GETRIEBE_STACK_SIZE + 1, sizeof(stack_test) / sizeof(uint32_t));

    getriebe_print_state(&getriebe);
    getriebe_execute_next_instruction(&getriebe);
    getriebe_execute_next_instruction(&getriebe);
    getriebe_execute_next_instruction(&getriebe);
    getriebe_execute_next_instruction(&getriebe);
    getriebe_execute_next_instruction(&getriebe);
    getriebe_print_state(&getriebe);
    getriebe_print_memory(&getriebe, 0XFFF0, 64);
    */
	G_Opcode_Data_Manipulation dm_opcode;
	dm_opcode.value = 0;
	opcode_data_manipulation_handle(&getriebe, dm_opcode.value);

    return 0;
}
