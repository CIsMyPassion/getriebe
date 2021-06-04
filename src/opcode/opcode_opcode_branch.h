#ifndef OPCODE_BRANCH_H
#define OPCODE_BRANCH_H

#include <stdint.h>

typedef struct getriebe Getriebe;

typedef union
{
	uint32_t value;
	struct
	{
		uint8_t condition : 4;
		uint8_t identifier : 3;
		uint8_t link : 1;
		uint32_t offset : 24;
	};
} G_Opcode_Branch;

void opcode_branch_handle(Getriebe * self, uint32_t opcode);

#endif
