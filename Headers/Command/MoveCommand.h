#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"
#include "Direction.h"

class MoveCommand : public Command
{
public:
    MoveCommand();
    ~MoveCommand();

    // Set direction for move command
    void setDirection(Direction direction);

    // Get direction of the move command
    Direction getDirection();

private:
    // Direction of the move
    Direction direction;
};

#endif