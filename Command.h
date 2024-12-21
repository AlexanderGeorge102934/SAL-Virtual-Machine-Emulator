// Command.h
#ifndef COMMAND_H
#define COMMAND_H

#include <string>

// Forward declaration of Machine class
class Machine;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
protected:
    Machine* machine;
    std::string opcode;
};

#endif // COMMAND_H
