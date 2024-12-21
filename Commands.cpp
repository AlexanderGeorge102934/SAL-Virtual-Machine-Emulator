// Commands.cpp
#include "Commands.h"
#include <iostream>

// DEC Command
DecCommand::DecCommand(Machine* m, const std::string& sym) : symbol(sym) {
    machine = m;
    opcode = "DEC";
}

void DecCommand::execute() {
    machine->declare(symbol);
    machine->incrementPC();
}

// LDA Command
LdaCommand::LdaCommand(Machine* m, const std::string& sym) : symbol(sym) {
    machine = m;
    opcode = "LDA";
}

void LdaCommand::execute() {
    machine->loadAccumulator(symbol);
    machine->incrementPC();
}

// LDI Command
LdiCommand::LdiCommand(Machine* m, int val) : value(val) {
    machine = m;
    opcode = "LDI";
}

void LdiCommand::execute() {
    machine->loadImmediate(value);
    machine->incrementPC();
}

// STR Command
StrCommand::StrCommand(Machine* m, const std::string& sym) : symbol(sym) {
    machine = m;
    opcode = "STR";
}

void StrCommand::execute() {
    machine->storeAccumulator(symbol);
    machine->incrementPC();
}

// XCH Command
XchCommand::XchCommand(Machine* m) {
    machine = m;
    opcode = "XCH";
}

void XchCommand::execute() {
    machine->exchangeRegisters();
    machine->incrementPC();
}

// JMP Command
JmpCommand::JmpCommand(Machine* m, int addr) : address(addr) {
    machine = m;
    opcode = "JMP";
}

void JmpCommand::execute() {
    machine->jump(address);
}

// JZS Command
JzsCommand::JzsCommand(Machine* m, int addr) : address(addr) {
    machine = m;
    opcode = "JZS";
}

void JzsCommand::execute() {
    machine->jumpIfZero(address);
}

// ADD Command
AddCommand::AddCommand(Machine* m) {
    machine = m;
    opcode = "ADD";
}

void AddCommand::execute() {
    machine->add();
    machine->incrementPC();
}

// SUB Command
SubCommand::SubCommand(Machine* m) {
    machine = m;
    opcode = "SUB";
}

void SubCommand::execute() {
    machine->subtract();
    machine->incrementPC();
}

// HLT Command
HltCommand::HltCommand(Machine* m) {
    machine = m;
    opcode = "HLT";
}

void HltCommand::execute() {
    machine->halt();
}
