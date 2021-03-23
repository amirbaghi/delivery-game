#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "Command.h"

class UndoCommand : public Command
{
public:
    UndoCommand();
    ~UndoCommand();
};

#endif