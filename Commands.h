// Commands.h
#ifndef COMMANDS_H
#define COMMANDS_H

#include "Command.h"
#include "Machine.h"
#include <string>

// DEC Command
class DecCommand : public Command {
public:
    DecCommand(Machine* m, const std::string& sym);
    void execute() override;
private:
    std::string symbol;
};

// LDA Command
class LdaCommand : public Command {
public:
    LdaCommand(Machine* m, const std::string& sym);
    void execute() override;
private:
    std::string symbol;
};

// LDI Command
class LdiCommand : public Command {
public:
    LdiCommand(Machine* m, int value);
    void execute() override;
private:
    int value;
};

// STR Command
class StrCommand : public Command {
public:
    StrCommand(Machine* m, const std::string& sym);
    void execute() override;
private:
    std::string symbol;
};

// XCH Command
class XchCommand : public Command {
public:
    XchCommand(Machine* m);
    void execute() override;
};

// JMP Command
class JmpCommand : public Command {
public:
    JmpCommand(Machine* m, int address);
    void execute() override;
private:
    int address;
};

// JZS Command
class JzsCommand : public Command {
public:
    JzsCommand(Machine* m, int address);
    void execute() override;
private:
    int address;
};

// ADD Command
class AddCommand : public Command {
public:
    AddCommand(Machine* m);
    void execute() override;
};

// SUB Command
class SubCommand : public Command {
public:
    SubCommand(Machine* m);
    void execute() override;
};

// HLT Command
class HltCommand : public Command {
public:
    HltCommand(Machine* m);
    void execute() override;
};

#endif // COMMANDS_H
