#include "opcode_data_manipulation.h"

#include "../../include/getriebe.h"

static inline uint32_t internal_right_rotate(uint32_t value, uint8_t ammount)
{
	return (value << ammount) | (value >> (32 - ammount));
}

static inline uint32_t internal_compute_operand_1_value(Getriebe * self, G_Opcode_Data_Manipulation opcode)
{
	uint32_t result;

	if (opcode.immediate)
	{
		uint8_t register_number = opcode.operand_1 & 0xf;
		uint32_t register_value = getriebe_read_register(self, register_number);
		uint8_t shift_type = opcode.operand_1 & 0x60 >> 5;
		uint32_t shift_ammount;
		
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
    G_Opcode_Data_Manipulation operation = (G_Opcode_Data_Manipulation) { .value = opcode };
	uint32_t opernad_0 = getriebe_read_register(self, operation.operand_0);
	uint32_t opernad_1 = internal_compute_operand_1_value(self, operation);
	
	switch (operation.opcode)
	{
		case G_DATA_MANIPULATION_MODE_AND:
			break;
		case G_DATA_MANIPULATION_MODE_EOR:
			break;
		case G_DATA_MANIPULATION_MODE_SUB:
			break;
		case G_DATA_MANIPULATION_MODE_RSB:
			break;
		case G_DATA_MANIPULATION_MODE_ADD:
			break;
		case G_DATA_MANIPULATION_MODE_ADC:
			break;
		case G_DATA_MANIPULATION_MODE_SBC:
			break;
		case G_DATA_MANIPULATION_MODE_RSC:
			break;
		case G_DATA_MANIPULATION_MODE_TST:
			break;
		case G_DATA_MANIPULATION_MODE_TEQ:
			break;
		case G_DATA_MANIPULATION_MODE_CMP:
			break;
		case G_DATA_MANIPULATION_MODE_CMN:
			break;
		case G_DATA_MANIPULATION_MODE_ORR:
			break;
		case G_DATA_MANIPULATION_MODE_MOV:
			break;
		case G_DATA_MANIPULATION_MODE_BIC:
			break;
		case G_DATA_MANIPULATION_MODE_MVN:
			break;
	}
}


