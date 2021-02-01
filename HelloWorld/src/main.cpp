#include <iostream>
#include <filesystem>
#include <fcntl.h>

namespace fs = std::filesystem;

int main(int argc, char const* argv[]) {
    std::string exec_path = argv[0];

    std::cout << "Hello, World!\n";
    std::cout << "Executable path: \n";
    std::cout << exec_path << "\n";

    std::cout << "Run path: \n";
    std::cout << fs::current_path().string() << "\n";

    std::cout << "\U0001F680"
              << "\n";

    // Stops the program
    std::cin.ignore();
    return 0;
}
