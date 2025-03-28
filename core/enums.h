#pragma once

enum Instruction
{
    NOP = 0x0,
    ADD = 0x02,
    STORE = 0x03,
    MOVA = 0x04,
    MOVB = 0x05,
    MOVMEM = 0x06,
    JMP = 0x07,
    SUB = 0x08,
    DIV = 0x09,
    MUL = 0x10,
    HLR = 0xFF,
};

enum Type
{
    IMM = 0x00,
    REG = 0x01,
    MEM = 0x02,
};

enum Register
{
    A = 0x00,
    B = 0x01,
};