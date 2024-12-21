// Machine.cpp
#include "Machine.h"
#include <iostream>

Machine::Machine() {
    dataMemory.resize(128, 0); // Data memory from addresses 128 to 255
    registerA = 0;
    registerB = 0;
    pc = 0;
    zeroBit = false;
}

void Machine::declare(const std::string& symbol) {
    if (symbolTable.find(symbol) == symbolTable.end()) {
        uint8_t address = static_cast<uint8_t>(symbolTable.size());
        if (address < 128) {
            symbolTable[symbol] = address;
            dataMemory[address] = 0;
        } else {
            std::cerr << "Data memory full. Cannot declare symbol: " << symbol << std::endl;
        }
    }
}

void Machine::loadAccumulator(const std::string& symbol) {
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end()) {
        uint8_t address = it->second;
        registerA = dataMemory[address];
    } else {
        std::cerr << "Symbol not found: " << symbol << std::endl;
    }
}

void Machine::loadImmediate(int16_t value) {
    registerA = value;
}

void Machine::storeAccumulator(const std::string& symbol) {
    auto it = symbolTable.find(symbol);
    if (it != symbolTable.end()) {
        uint8_t address = it->second;
        dataMemory[address] = registerA;
    } else {
        std::cerr << "Symbol not found: " << symbol << std::endl;
    }
}

void Machine::exchangeRegisters() {
    int16_t temp = registerA;
    registerA = registerB;
    registerB = temp;
}

void Machine::jump(uint8_t address) {
    if (address < 128) {
        pc = address;
    } else {
        std::cerr << "Invalid jump address: " << static_cast<int>(address) << std::endl;
    }
}

void Machine::jumpIfZero(uint8_t address) {
    if (zeroBit) {
        jump(address);
    } else {
        incrementPC();
    }
}

void Machine::add() {
    int32_t result = static_cast<int32_t>(registerA) + static_cast<int32_t>(registerB);
    if (isValidData(result)) {
        registerA = static_cast<int16_t>(result);
        zeroBit = (registerA == 0);
    } else {
        std::cerr << "Addition overflow. Operation has no effect." << std::endl;
    }
}

void Machine::subtract() {
    int32_t result = static_cast<int32_t>(registerA) - static_cast<int32_t>(registerB);
    if (isValidData(result)) {
        registerA = static_cast<int16_t>(result);
        zeroBit = (registerA == 0);
    } else {
        std::cerr << "Subtraction overflow. Operation has no effect." << std::endl;
    }
}

void Machine::halt() {
    pc = 128; // Set pc to an invalid address to halt execution
}

void Machine::incrementPC() {
    pc++;
}

bool Machine::isValidAddress(uint8_t address) {
    return address < 128;
}

bool Machine::isValidData(int32_t value) {
    return value >= -32768 && value <= 32767;
}

void Machine::reset() {
    dataMemory.assign(128, 0);
    registerA = 0;
    registerB = 0;
    pc = 0;
    zeroBit = false;
    symbolTable.clear();
}

void Machine::displayState() {
    std::cout << "Registers:" << std::endl;
    std::cout << "  A: " << registerA << std::endl;
    std::cout << "  B: " << registerB << std::endl;
    std::cout << "Zero Bit: " << zeroBit << std::endl;
    std::cout << "Program Counter: " << static_cast<int>(pc) << std::endl;
    displayMemory();
}

void Machine::displayMemory() {
    std::cout << "Data Memory (used locations):" << std::endl;
    for (const auto& pair : symbolTable) {
        const std::string& symbol = pair.first;
        uint8_t address = pair.second;
        int16_t value = dataMemory[address];
        std::cout << "  " << symbol << " (Address " << static_cast<int>(address + 128) << "): " << value << std::endl;
    }
}
