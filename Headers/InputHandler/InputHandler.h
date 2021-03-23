#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../GameComponent.h"
#include "../Command/Command.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75


class InputHandler: public GameComponent
{
public:
    InputHandler(GameComponent* parent);
    ~InputHandler();

    // Method for handling input
    Command* getInput();
};

#endif