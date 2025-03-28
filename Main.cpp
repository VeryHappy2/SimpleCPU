// CPU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "./core/CPU.h"

int main()
{
    CPU cpu;
    std::vector<u8> program = {
        MOVMEM, 0x02C, 0x0D,
        MOVMEM, 0x03D, 0x0E,
        MOVA, 0x14,
        MOVB, 0x20,
        NOP,
        ADD, REG, A, IMM, 0x02C, MEM, 0x03D,
        ADD, MEM, 0x03D, REG, A, REG, B,
        ADD, MEM, 0x02C, MEM, 0x02C, MEM, 0x03D,
        HLR,
    };
    cpu.executeProgram(program);
    const u8 val1 = cpu[0x03D];
    const u8 val2 = cpu[0x2C];
    std::cout << "0x02C: " << static_cast<int>(val1) << std::endl;
    std::cout << "0x03D: " << static_cast<int>(val2) << std::endl;
    std::cout << "A: " << static_cast<int>(cpu.regA) << std::endl;
    std::cout << "B: " << static_cast<int>(cpu.regB) << std::endl;
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
