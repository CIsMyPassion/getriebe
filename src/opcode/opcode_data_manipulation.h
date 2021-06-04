#ifndef OPCODE_DATA_MANIPULATION_H
#define OPCODE_DATA_MANIPULATION_H

#include <stdint.h>

typedef struct getriebe Getriebe;

typedef enum g_data_maipulation_mode
{
	G_DATA_MANIPULATION_MODE_AND = 0x0,
	G_DATA_MANIPULATION_MODE_EOR = 0x1,
	G_DATA_MANIPULATION_MODE_SUB = 0x2,
	G_DATA_MANIPULATION_MODE_RSB = 0x3,
	G_DATA_MANIPULATION_MODE_ADD = 0x4,
	G_DATA_MANIPULATION_MODE_ADC = 0x5,
	G_DATA_MANIPULATION_MODE_SBC = 0x6,
	G_DATA_MANIPULATION_MODE_RSC = 0x7,
	G_DATA_MANIPULATION_MODE_TST = 0x8,
	G_DATA_MANIPULATION_MODE_TEQ = 0x9,
	G_DATA_MANIPULATION_MODE_CMP = 0xa,
	G_DATA_MANIPULATION_MODE_CMN = 0xb,
	G_DATA_MANIPULATION_MODE_ORR = 0xc,
	G_DATA_MANIPULATION_MODE_MOV = 0xd,
	G_DATA_MANIPULATION_MODE_BIC = 0xe,
	G_DATA_MANIPULATION_MODE_MVN = 0xf,
} G_Data_Manipulation_Mode;

typedef union
{
    uint32_t value;
    struct
    {
		uint8_t condition : 4;
        uint8_t identifier : 2;
        uint8_t immediate : 1;
		uint8_t opcode : 4;
		uint8_t set_condition : 1;
        uint8_t operand_0 : 4;
        uint8_t destination : 4;
        uint16_t operand_1 : 12;
    };
} G_Opcode_Data_Manipulation;

static inline G_Opcode_Data_Manipulation opcode_data_manipulation_create(uint8_t condition, uint8_t immediate, G_Data_Manipulation_Mode mode, uint8_t set_condition, uint8_t operand_0, uint8_t destination, uint16_t operand_1)
{
	return (G_Opcode_Data_Manipulation) { .condition = condition, .identifier = 0b00, .immediate = immediate, .opcode = (uint8_t) mode, .set_condition = set_condition, .operand_0 = operand_0, .destination = destination, .operand_1 = operand_1 };
}
void opcode_data_manipulation_handle(Getriebe * self, uint32_t opcode);

#endif
