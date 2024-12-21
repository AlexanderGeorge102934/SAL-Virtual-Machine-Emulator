// Machine.h
#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdint>

class Machine {
public:
    Machine();

    // Data Memory (128 cells from address 128 to 255)
    std::vector<int16_t> dataMemory;

    // Registers
    int16_t registerA;
    int16_t registerB;

    // Program Counter (PC)
    uint8_t pc;

    // Zero Bit
    bool zeroBit;

    // Symbol Table
    std::unordered_map<std::string, uint8_t> symbolTable; // Maps symbol names to data memory addresses

    // Methods
    void declare(const std::string& symbol);
    void loadAccumulator(const std::string& symbol);
    void loadImmediate(int16_t value);
    void storeAccumulator(const std::string& symbol);
    void exchangeRegisters();
    void jump(uint8_t address);
    void jumpIfZero(uint8_t address);
    void add();
    void subtract();
    void halt();
    void incrementPC();

    // Helper methods
    bool isValidAddress(uint8_t address);
    bool isValidData(int32_t value);

    void reset();

    // For displaying state
    void displayState();
    void displayMemory();
};

#endif // MACHINE_H
