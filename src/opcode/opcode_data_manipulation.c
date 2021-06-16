#include "opcode.h"

#include <stdio.h>
#include <inttypes.h>

#include "../../include/getriebe.h"

static inline uint32_t internal_right_rotate(uint32_t value, uint8_t ammount)
{
	return (value << ammount) | (value >> (32 - ammount));
}

static inline uint32_t internal_compute_operand_1_value(Getriebe * self, G_Opcode_Data_Manipulation opcode)
{
	uint32_t result = -1;

	if (!opcode.immediate)
	{
		uint8_t register_number = opcode.operand_1 & 0xf;
		uint32_t register_value = getriebe_read_register(self, register_number);
		uint8_t shift_type = opcode.operand_1 & 0x60 >> 5;
		uint32_t shift_ammount;
		
		printf("register number: %d\n", register_number);
		printf("register value: %d\n", register_value);

		if (opcode.operand_1 & 0x10)
		{
			shift_ammount = getriebe_read_register(self, opcode.operand_1 & 0xf00);
		}
		else
		{
			shift_ammount = (opcode.operand_1 & 0xf80) >> 7;
		}
		
		switch (shift_type)
		{
			case 0:
				result = register_value << shift_ammount;
				break;
			case 1:
				result = register_value >> shift_ammount;
				break;
			case 2:
				result = (uint32_t) ((int32_t) register_value) >> shift_ammount;
				break;
			case 3:
				result = internal_right_rotate(register_value, shift_ammount);
				break;
		}
	}
	else
	{
		uint32_t immediate_value = opcode.operand_1 & 0xff;
		uint8_t shift_ammount = (opcode.operand_1 & 0xf00) * 2;

		result = internal_right_rotate(immediate_value, shift_ammount);
	}

	return result;
}

void opcode_data_manipulation_handle(Getriebe * self, uint32_t opcode)
{
    G_Opcode_Data_Manipulation op = (G_Opcode_Data_Manipulation) { .value = opcode };
	uint32_t operand_0 = getriebe_read_register(self, op.operand_0);
	uint32_t operand_1 = internal_compute_operand_1_value(self, op);
	uint32_t result = 0;
	
	printf("operand_1: %" PRIu32 "\n", operand_1);

	switch (op.opcode)
	{
		case G_DATA_MANIPULATION_MODE_AND:
			result = operand_0 & operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_EOR:
			result = operand_0 ^ operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_SUB:
			result = operand_0 - operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_RSB:
			result = operand_1 - operand_0;
			break;
		case G_DATA_MANIPULATION_MODE_ADD:
			result = operand_0 + operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_ADC:
			result = operand_0 + operand_1 + 1;
			break;
		case G_DATA_MANIPULATION_MODE_SBC:
			result = operand_0 - operand_1 + 1;
			break;
		case G_DATA_MANIPULATION_MODE_RSC:
			result = operand_1 - operand_0 - 1;
			break;
		case G_DATA_MANIPULATION_MODE_ORR:
			result = operand_0 | operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_MOV:
			result = operand_1;
			break;
		case G_DATA_MANIPULATION_MODE_BIC:
			result = operand_0 & (~operand_1);
			break;
		case G_DATA_MANIPULATION_MODE_MVN:
			result = ~operand_1;
			break;
	}

	printf("result: %d\n", result);

	getriebe_write_register(self, op.destination, (uint32_t) result);
}
