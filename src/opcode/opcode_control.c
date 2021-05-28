#include "opcode_control.h"

typedef void (* G_Opcode_Control_Func)(Getriebe *);

static void internal_psh_handler(Getriebe * getriebe);
static void internal_pop_handler(Getriebe * getriebe);
static void internal_jmp_handler(Getriebe * getriebe);
static void internal_brz_handler(Getriebe * getriebe);
static void internal_brp_handler(Getriebe * getriebe);
static void internal_brn_handler(Getriebe * getriebe);
static void internal_jsr_handler(Getriebe * getriebe);
static void internal_rts_handler(Getriebe * getriebe);
static void internal_clf_handler(Getriebe * getriebe);

static G_Opcode_Control_Func internal_handlers[] = {
    internal_psh_handler,
    internal_pop_handler,
    internal_jmp_handler,
    internal_brz_handler,
    internal_brp_handler,
    internal_brn_handler,
    internal_jsr_handler,
    internal_rts_handler,
    internal_clf_handler
};

void g_opcode_control(Getriebe * getriebe, G_Opcode opcode)
{
    internal_handlers[opcode & 0x0000FFFF](getriebe);
}

static void internal_psh_handler(Getriebe * getriebe)
{
    uint32_t register_number = getriebe_read_next_cell(getriebe);
    uint32_t register_value = getriebe_read_register(getriebe, register_number);
    uint32_t * stack_pointer = &(getriebe->registers[G_REGISTER_SP]);
    uint32_t real_stack_address = *stack_pointer-- + GETRIEBE_STACK_OFFSET;

    getriebe_write_cell(getriebe, real_stack_address, register_value);
}

static void internal_pop_handler(Getriebe * getriebe)
{
    uint32_t register_number = getriebe_read_next_cell(getriebe);
    uint32_t * stack_pointer = &(getriebe->registers[G_REGISTER_SP]);
    uint32_t real_stack_address = *stack_pointer++ + GETRIEBE_STACK_OFFSET;
    uint32_t stack_value = getriebe_read_cell(getriebe, real_stack_address);

    getriebe_write_register(getriebe, register_number, stack_value);
}

static void internal_jmp_handler(Getriebe * getriebe)
{

}

static void internal_brz_handler(Getriebe * getriebe)
{

}

static void internal_brp_handler(Getriebe * getriebe)
{

}

static void internal_brn_handler(Getriebe * getriebe)
{

}

static void internal_jsr_handler(Getriebe * getriebe)
{

}

static void internal_rts_handler(Getriebe * getriebe)
{

}

static void internal_clf_handler(Getriebe * getriebe)
{

}