// Invoker.h
#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include <vector>
#include <memory>

class Invoker {
public:
    Invoker();

    void setCommand(uint8_t index, std::shared_ptr<Command> cmd);
    void executeCommand(Machine& machine);
    void executeAll(Machine& machine);
private:
    std::vector<std::shared_ptr<Command>> commands;
};

#endif // INVOKER_H
