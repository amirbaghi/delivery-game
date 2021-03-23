#include "Command.h"

class UndoCommand : public Command
{
public:
    UndoCommand(GameComponent *parent);
};