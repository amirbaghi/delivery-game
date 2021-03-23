#include <vector>
#include "Command.h"
#include "GameComponent.h"

class CommandStream : public GameComponent
{
public:
    CommandStream(GameComponent *parent);

    // Pop most recent pending command
    Command popRecentPendingCommand();

    // Pop most recent resolved command
    Command popRecentResolvedCommand();

    // Add to Pending Commands
    void addToPendingCommands(Command &command);

    // Add to Resolved Commands
    void addToResolvedCommands(Command &command);

private:
    // Pending Commands
    std::vector<Command> pending_commands;
    // Resolved Commands
    std::vector<Command> resolved_commands;
};