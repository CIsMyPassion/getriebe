#include <getriebe.h>

#include <stdio.h>
#include <stdlib.h>

#include "opcodes/opcode_branch_test.h"
#include "opcodes/opcode_data_manipulation_test.h"

int main()
{
	printf("Starting tests\n");

	opcode_branch_test();
	opcode_data_manipulation_test();

	return EXIT_SUCCESS;
}