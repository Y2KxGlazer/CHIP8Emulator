#include "chip8_rom.h"
#include "chip8_emulator.h"

namespace fs = std::filesystem;

std::filesystem::path cwd = std::filesystem::current_path();
std::filesystem::path dir_path = cwd / "CH8 Roms";

Chip8 game;
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

void createRomFolder() {
    try {
        if (std::filesystem::exists(dir_path)) {
            std::cout << "Rom folder found!\n";
            romChoice(dir_path.string());
        }
        else {
            std::cout << "Rom folder not found, thus one was created!\nPlease Save your roms there, and restart";
            std::filesystem::create_directory(dir_path.string());
        }
    }
    catch (const std::filesystem::filesystem_error& error) {
        std::cerr << "Error creating directory: " << error.what() << std::endl;
    }
}
