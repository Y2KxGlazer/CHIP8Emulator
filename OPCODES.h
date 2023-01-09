#pragma once

#include "chip8_emulator.h"

void Chip8::OP_00E0() { // The opcode to clear the screen... legendary bit flip.
	memset(dMemory, 0, sizeof(dMemory));
}
void Chip8::OP_00EE() { // Returns from a subroutine
	pCounter[0] = lStack[sPointer[0]];
	sPointer[0]--;
}
void Chip8::OP_1nnn() { // Jump opcode.
	uint16_t address = opCode & 0x0FFFu; 
	pCounter[0] = address;
}
