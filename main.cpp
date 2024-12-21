// main.cpp
#include "Machine.h"
#include "Invoker.h"
#include "Commands.h"
#include "Machine.cpp"
#include "Invoker.cpp"
#include "Commands.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

std::shared_ptr<Command> parseCommand(const std::string& line, Machine* machine);

int main() {
    Machine machine;
    Invoker invoker;

    std::cout << "Enter the SAL program file name: ";
    std::string fileName;
    std::getline(std::cin, fileName);

    std::ifstream infile(fileName);
    if (!infile) {
        std::cerr << "File not found: " << fileName << std::endl;
        return 1;
    }

    std::string line;
    uint8_t index = 0;
    while (std::getline(infile, line) && index < 128) {
        // Remove leading and trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        // Skip empty lines or comments
        if (line.empty() || line[0] == '#') continue;

        auto cmd = parseCommand(line, &machine);
        if (cmd) {
            invoker.setCommand(index, cmd);
            index++;
        } else {
            std::cerr << "Unknown command in line: " << line << std::endl;
        }
    }

    // Command loop
    while (machine.pc < 128) {
        std::cout << "Enter command (s: step, a: all, q: quit): ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "s") {
            invoker.executeCommand(machine);
            machine.displayState();
        } else if (input == "a") {
            invoker.executeAll(machine);
            machine.displayState();
            std::cout << "Program halted or no more commands." << std::endl;
        } else if (input == "q") {
            std::cout << "Exiting." << std::endl;
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
        if (machine.pc >= 128) {
            std::cout << "Program has halted or ran out of memory." << std::endl;
            break;
        }
    }

    return 0;
}

std::shared_ptr<Command> parseCommand(const std::string& line, Machine* machine) {
    std::istringstream iss(line);
    std::string opcode;
    iss >> opcode;
    // Convert opcode to uppercase
    for (auto& c : opcode) c = toupper(c);

    if (opcode == "DEC") {
        std::string symbol;
        iss >> symbol;
        return std::make_shared<DecCommand>(machine, symbol);
    } else if (opcode == "LDA") {
        std::string symbol;
        iss >> symbol;
        return std::make_shared<LdaCommand>(machine, symbol);
    } else if (opcode == "LDI") {
        int value;
        iss >> value;
        return std::make_shared<LdiCommand>(machine, value);
    } else if (opcode == "STR") {
        std::string symbol;
        iss >> symbol;
        return std::make_shared<StrCommand>(machine, symbol);
    } else if (opcode == "XCH") {
        return std::make_shared<XchCommand>(machine);
    } else if (opcode == "JMP") {
        int address;
        iss >> address;
        return std::make_shared<JmpCommand>(machine, address);
    } else if (opcode == "JZS") {
        int address;
        iss >> address;
        return std::make_shared<JzsCommand>(machine, address);
    } else if (opcode == "ADD") {
        return std::make_shared<AddCommand>(machine);
    } else if (opcode == "SUB") {
        return std::make_shared<SubCommand>(machine);
    } else if (opcode == "HLT") {
        return std::make_shared<HltCommand>(machine);
    } else {
        return nullptr;
    }
}
