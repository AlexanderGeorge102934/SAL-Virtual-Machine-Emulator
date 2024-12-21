// Invoker.cpp
#include "Invoker.h"
#include <iostream>

Invoker::Invoker() {
    commands.resize(128, nullptr);
}

void Invoker::setCommand(uint8_t index, std::shared_ptr<Command> cmd) {
    if (index < 128) {
        commands[index] = cmd;
    } else {
        std::cerr << "Program memory overflow. Cannot set command at index: " << static_cast<int>(index) << std::endl;
    }
}

void Invoker::executeCommand(Machine& machine) {
    uint8_t pc = machine.pc;
    if (pc < 128) {
        auto cmd = commands[pc];
        if (cmd) {
            cmd->execute();
        } else {
            std::cerr << "No command at PC: " << static_cast<int>(pc) << std::endl;
            machine.incrementPC();
        }
    } else {
        std::cerr << "Program has halted or ran out of memory." << std::endl;
    }
}

void Invoker::executeAll(Machine& machine) {
    int steps = 0;
    while (machine.pc < 128) {
        executeCommand(machine);
        steps++;
        if (steps >= 1000) {
            std::cout << "Reached 1000 steps. Continue? (y/n): ";
            std::string answer;
            std::getline(std::cin, answer);
            if (answer != "y") {
                break;
            }
            steps = 0;
        }
        if (machine.pc >= 128) {
            break;
        }
    }
}
