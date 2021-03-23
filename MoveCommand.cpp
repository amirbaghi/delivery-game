#include "Headers/Command/MoveCommand.h"

MoveCommand::MoveCommand() : Command()
{
}

MoveCommand::~MoveCommand()
{
}

void MoveCommand::setDirection(Direction direction)
{
    this->direction = direction;
}

Direction MoveCommand::getDirection()
{
    return this->direction;
}