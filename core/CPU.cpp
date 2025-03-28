#include "CPU.h"
#include "iostream"
#include <vector>

void CPU::run() {
    running = true;
    while (running) {
        execute(memory[pc]);
    }
}

void CPU::execute(u8 instruction) {
    switch (instruction) {
        case NOP:
            break;
        case ADD: {
            u8 type = memory[pc + 1];
            if (type == IMM) {
                std::cout << "Here cannot be imm: " << memory[pc + 1] << std::endl;
                running = false;
            }
            u8 operand1 = getValue(memory[pc + 3], memory[pc + 4]);
            u8 operand2 = getValue(memory[pc + 5], memory[pc + 6]);

            u8 result = operand1 + operand2;
            if (type == REG) {
                changeRegister(memory[pc + 2], result);
            }
            else if (type == MEM) {
                writeMemory(memory[pc + 2], result);
            }
            else {
                std::cout << "Unknown instruction: " << static_cast<unsigned int>(memory[pc]) << std::endl;
                running = false;
            }
            pc += 6;
            break;
        }
        case MOVA:
            pc++;
            regA = memory[pc];
            break;
        case MOVB:
            pc++;
            regB = memory[pc];
            break;
        case MOVMEM:
            pc += 2;
            writeMemory(memory[pc - 1], memory[pc]);
            break;
        case SUB: {
            u8 type = memory[pc + 1];
            if (type == IMM) {
                std::cout << "Here cannot be imm: " << memory[pc + 1] << std::endl;
                running = false;
            }
            u8 operand1 = getValue(memory[pc + 3], memory[pc + 4]);
            u8 operand2 = getValue(memory[pc + 5], memory[pc + 6]);

            u8 result = operand1 - operand2;
            if (type == REG) {
                changeRegister(memory[pc + 2], result);
            }
            else if (type == MEM) {
                writeMemory(memory[pc + 2], result);
            }
            else {
                std::cout << "Unknown instruction: " << static_cast<unsigned int>(memory[pc]) << std::endl;
                running = false;
            }
            pc += 6;
            break;
        }
        case DIV: {
            u8 type = memory[pc + 1];
            if (type == IMM) {
                std::cout << "Here cannot be imm: " << memory[pc + 1] << std::endl;
                running = false;
            }
            u8 operand1 = getValue(memory[pc + 3], memory[pc + 4]);
            u8 operand2 = getValue(memory[pc + 5], memory[pc + 6]);

            u8 result = operand1 / operand2;
            if (type == REG) {
                changeRegister(memory[pc + 2], result);
            }
            else if (type == MEM) {
                writeMemory(memory[pc + 2], result);
            }
            else {
                std::cout << "Unknown instruction: " << static_cast<unsigned int>(memory[pc]) << std::endl;
                running = false;
            }
            pc += 6;
            break;
        }
        case JMP:
            pc++;
            pc = memory[pc];
            break;
        case HLR:
            running = false;
            break;
        default:
            std::cout << "Unknown instruction: " << static_cast<unsigned int>(memory[pc]) << std::endl;
            running = false;
            break;
    }
    pc++;
}

void CPU::writeMemory(u8 address, u8 value)
{
    memory[address] = value;
}

void CPU::executeProgram(std::vector<u8>& program) {
    loadProgram(program);
    run();
}

void CPU::loadProgram(std::vector<u8>& program) {
    for (size_t i = 0; i < program.size(); i++)
        memory[i] = program[i];
}

u8 CPU::getValue(u8 type, u8 val) {
    switch (type) {
        case REG: return (val == 0) ? regA : regB;
        case MEM: return memory[val];
        case IMM: return val;
        default: return 0;
    }
}

void CPU::changeRegister(u8 reg, u8 val) {
    switch (reg)
    {
        case A:
            regA = val;
            break;
        case B:
            regB = val;
            break;
        default:
            std::cout << "Unknown register: " << static_cast<unsigned int>(memory[pc]) << std::endl;
            break;
    }
}
