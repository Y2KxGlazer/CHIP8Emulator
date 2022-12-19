// CHIP8Emulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "chip8.h"




Chip8 game;

// This is the rom to load.
char const* file = R"(C:\Users\bmini\Desktop\Winter Break Emu Project\CH8 FIles\Tetris [Fran Dachille, 1991].ch8)";

int main()
{
    game.loadRom(file);

    system("pause>9");
}

