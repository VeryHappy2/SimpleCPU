// CPU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "./core/CPU.h"
#include <fstream>

int main(int argc, char* argv[])
{
    std::vector<u8> program;
    if (argc == 2)
    {
        if (argv[1] == nullptr) {
            std::cerr << "You need to type the path of the binary file" << std::endl;
        }

        std::ifstream file(argv[1], std::ios::binary);
        if (!file) {
            std::cerr << "Not found\n";
            return 1;
        }
        std::vector<u8> program(
            (std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>()
        );    
        CPU cpu;
        cpu.executeProgram(program);

        std::cout << "A: " << static_cast<int>(cpu.regA) << std::endl;
        std::cout << "B: " << static_cast<int>(cpu.regB) << std::endl;
        for (size_t i = 0; i < 1024; i++)
        {
            if (cpu[i] == '\0')
                continue;

            std::cout << "Index: " << i << cpu[i] << std::endl;
        }
    } else {
        return 1;
    }


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
