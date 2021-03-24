#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../GameComponent.h"
#include "../Command/Command.h"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67


class InputHandler: public GameComponent
{
public:
    InputHandler(GameComponent* parent);
    ~InputHandler();

    // Method for handling input
    Command* getInput();
};

#endif