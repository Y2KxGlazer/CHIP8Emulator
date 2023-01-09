#pragma once
#include <iostream>
#include <cstdint>
#include <fstream>
#include <chrono>
#include <random>


void romChoice(std::string filePath);
void createRomFolder();

struct Chip8 {
    uint8_t registers[16] = { 0 };          // The registers
    uint8_t ram[4096] = { 0 };              // Ram
    uint16_t index[4096] = { 0 };           // Index register
    uint16_t pCounter[1] = { 0 };           // Next instruction to execute
    uint16_t lStack[16] = { 0 };            // This is the stack
    uint8_t sPointer[1] = { 0 };            // Stack pointer 
    uint8_t dTimer[1] = { 0 };              // Delay timer
    uint8_t sTimer[1] = { 0 };              // Sound timer
    uint8_t InputKeys[16] = { 0 };          // User inputs
    uint32_t dMemory[64 * 32] = { 0 };      // Display Memory
    uint16_t opCode;                        // Opcodes 

    const unsigned int START_ADDRESS = 0x200;            // Starting address for loading programs
    const unsigned int FONTSET_SIZE = 80;                // Current available font 
    const unsigned int FONTSET_START_ADDRESS = 0x50;     // Address where font will start in memory



    uint8_t fontType[80] = {

    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    void OP_00E0();
    void OP_00EE();
    void OP_1nnn();
    void OP_2nnn();
    void OP_3xkk();
    void OP_4xkk();
    void OP_5xy0();
    void OP_6xkk();
    void OP_7xkk();
    void OP_8xy0();
    void OP_8xy1();
    void OP_8xy2();
    void OP_8xy3();
    void OP_8xy4();
    void OP_8xy5();
    void OP_8xy6();
    void OP_8xy7();
    void OP_8xyE();
    void OP_9xy0();
    void OP_Annn();
    void OP_Bnnn();
    void OP_Cxkk();
    void OP_Dxyn();
    void OP_Ex9E();
    void OP_ExA1();
    void OP_Fx07();
    void OP_Fx0A();
    void OP_Fx15();
    void OP_Fx1E();
    void OP_Fx29();
    void OP_Fx33();
    void OP_Fx65();
        
    

    void loadRom(char const* filename) {

        // Open the file as a stream of binary and move the file pointer to the end
        std::ifstream file(filename, std::ios::binary | std::ios::ate);

        if (file.is_open()) {
            // Get size of file and allocate a buffer to hold the contents
            std::streampos size = file.tellg();
            char* buffer = new char[size];

            // Go back to the beginning of the file and fill the buffer
            file.seekg(0, std::ios::beg);
            file.read(buffer, size);
            file.close();
            // Load the ROM contents into the Chip8's memory, starting at 0x200
            for (long i = 0; i < size; ++i)
            {
                ram[START_ADDRESS + i] = buffer[i];
            }
            

            // Free the buffer
            delete[] buffer;

        }

    }


    Chip8() {
        std::default_random_engine randGen;
        std::uniform_int_distribution<uint8_t> randByte;
        randByte = std::uniform_int_distribution<uint8_t>(0, 255U);


        pCounter[0] = START_ADDRESS;
        for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
        {
            ram[FONTSET_START_ADDRESS + i] = fontType[i];
        }
        
    }


};




