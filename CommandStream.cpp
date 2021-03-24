#include "Headers/Command/CommandStream.h"

CommandStream::CommandStream(GameComponent *parent) : GameComponent(parent)
{
}

CommandStream::~CommandStream()
{
}

void CommandStream::addToPendingCommands(Command *command)
{
    this->pending_commands.push(command);
}

void CommandStream::addToResolvedCommands(Command *command)
{
    this->resolved_commands.push(command);
}

Command *CommandStream::popRecentPendingCommand()
{
    if (this->pending_commands.empty())
    {
        return nullptr;
    }
    Command *c = this->pending_commands.front();
    this->pending_commands.pop();

    return c;
}

Command *CommandStream::popRecentResolvedCommand()
{
    if (this->resolved_commands.empty())
    {
        return nullptr;
    }
    Command *c = this->resolved_commands.top();
    this->resolved_commands.pop();
    return c;
}