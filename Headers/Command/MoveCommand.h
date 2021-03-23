#include "Command.h"
#include "Direction.h"

class MoveCommand : public Command
{
public:
    MoveCommand(GameComponent* parent);

private:
    // Direction of the move
    Direction direction;
};