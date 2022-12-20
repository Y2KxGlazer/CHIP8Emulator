// CHIP8Emulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>
#include "chip8.h"

namespace fs = std::filesystem;

void romChoice(std::string filePath);
Chip8 game;

// This is the rom to load.


// Folder Create folder that'll have the roms
std::string path = R"(C:\Users\bmini\Desktop\Winter Break Emu Project\CH8 FIles)";


int main()
{

    //game.loadRom(file);
    romChoice(path);
    system("pause>9");
}

void romChoice(std::string filePath) { // Allows user to select a rom to load.
    std::string path = filePath;
    std::vector<std::string> files;
    int userChoice;
    for (const auto& entry : fs::directory_iterator(path)) {
        std::string basePath = entry.path().string();
        std::string base_filename = entry.path().filename().string();
        std::cout << base_filename << std::endl;
        files.push_back(basePath);
    }
    std::cout << "Which rom would you like to load?\n";
    std::cin >> userChoice;
    std::cout << "Now loading rom...\n";
    game.loadRom(files[userChoice - 1].c_str());


    std::cout << "Rom Loaded...\n";

        

}
