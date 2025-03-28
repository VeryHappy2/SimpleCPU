#pragma once
#include <cstdint>
#include "enums.h"
#include <vector>

using u8 = uint8_t;

class CPU
{
private:
    u8 pc = 0;
    u8 getValue(u8 type, u8 val);
public:
    bool running;
    u8 regA = 0;
    u8 regB = 0;
    u8 memory[1024];
    CPU() {
        running = false;
        for (uint16_t i = 0; i < 1024; i++) {
            memory[i] = 0;
        }
    }

    void run();
    void writeMemory(u8 index, u8 value);

    void reset() {
        running = false;
        regA = 0;
        regB = 0;
        pc = 0;
        for (uint16_t i = 0; i < 1024; i++) {
            memory[i] = 0;
        }
    }

    u8 operator[](uint16_t address) const
    {
        return memory[address];
    }

    u8& operator[](uint16_t address)
    {
        return memory[address];
    }

    void loadProgram(std::vector<u8>& program);
    void changeRegister(u8 reg, u8 val);
    void execute(u8 instruction);
    void executeProgram(std::vector<u8>& program);
};