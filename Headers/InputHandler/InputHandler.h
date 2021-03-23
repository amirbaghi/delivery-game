#include "GameComponent.h"


class Command;

class InputHandler: public GameComponent
{
public:
    InputHandler(GameComponent* parent);

    // Method for handling input
    Command getInput();
};