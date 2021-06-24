#ifndef OPCODE_BRANCH_TEST_H
#define OPCODE_BRANCH_TEST_H

#include <assert.h>
#include <stddef.h>

#include <getriebe.h>

#include "branch/branch_non_link.h"
#include "branch/branch_link.h"

void opcode_branch_test()
{
	printf("opcode_branch_test started\n");
	assert(sizeof(G_Opcode_Branch) == sizeof(uint32_t));
	printf("G_Opcode_Branch size is correct\n");

	internal_test_non_link_branch();
	internal_test_link_branch();
}

#endif