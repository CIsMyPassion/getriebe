#ifndef OPCODE_CONTROL_H
#define OPCODE_CONTROL_H

#include "opcode.h"
#include "../../include/getriebe.h"

#include <stdint.h>

#define G_OPCODE_GROUP_CONTROL UINT32_C(0x000F0000)

void g_opcode_control(Getriebe * getriebe, G_Opcode opcode);

#endif