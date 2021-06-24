#ifndef STACK_MANIPULATION_H
#define STACK_MANIPULATION_H

#include "../include/getriebe.h"

static inline void getriebe_stack_push(Getriebe * self, G_Register push_value)
{
	self->stack[self->registers[G_REGISTER_SP]--] = getriebe_read_register(self, push_value);
}

#endif
