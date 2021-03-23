#ifndef COMMANDSTREAM_H
#define COMMANDSTREAM_H

#include <stack>
#include <queue>
#include "Command.h"
#include "../GameComponent.h"

class CommandStream : public GameComponent
{
public:
    CommandStream(GameComponent *parent);
    ~CommandStream();

    // Pop most recent pending command
    Command* popRecentPendingCommand();

    // Pop most recent resolved command
    Command* popRecentResolvedCommand();

    // Add to Pending Commands
    void addToPendingCommands(Command* command);

    // Add to Resolved Commands
    void addToResolvedCommands(Command* command);

private:
    // Pending Commands
    std::queue<Command *> pending_commands;
    // Resolved Commands
    std::stack<Command *> resolved_commands;
};

#endif