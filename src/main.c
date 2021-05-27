#include "../include/getriebe.h"

Getriebe getriebe;

uint32_t code[] = {
    G_OPCODE_LD, G_REGISTER_0, 0xFF,
    G_OPCODE_LD, G_REGISTER_1, 0x01,
    G_OPCODE_SUB, G_REGISTER_0, 0x1,
    G_OPCODE_BRP, 0x10003
};

uint32_t stack_test[] = {
    G_OPCODE_LD, G_REGISTER_0, 0xFFFFFFFF,
    G_OPCODE_LD, G_REGISTER_1, 0x00000FFF,
    G_OPCODE_PSH, G_REGISTER_0,
    G_OPCODE_SUB, G_REGISTER_0, G_REGISTER_1,
    G_OPCODE_PSH, G_REGISTER_0
};

int main()
{
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

    return 0;
}