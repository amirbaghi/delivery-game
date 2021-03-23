#include <iostream>
#include "Headers/InputHandler/InputHandler.h"
#include "Headers/Game/Game.h"
#include "Headers/Command/MoveCommand.h"
#include "Headers/Command/UndoCommand.h"

InputHandler::InputHandler(GameComponent *parent) : GameComponent(parent)
{
}

InputHandler::~InputHandler()
{
    
}

Command *InputHandler::getInput()
{
    char c;
    std::cin >> c;

    // If exit button is pushed
    if (c == 'q' | c == 'Q')
    {
        exit(0);
    }

    // If undo button is pushed
    if (c == 'u' | c == 'U')
    {
        return new UndoCommand();
    }

    // If it's a move command or a not supported key
    MoveCommand* command;
    switch (c)
    {
    case KEY_UP:
        command = new MoveCommand();
        command->setDirection(UP);
        return command;
        break;
    case KEY_DOWN:
        command = new MoveCommand();
        command->setDirection(DOWN);
        return command;
        break;
    case KEY_LEFT:
        command = new MoveCommand();
        command->setDirection(LEFT);
        return command;
        break;
    case KEY_RIGHT:
        command = new MoveCommand();
        command->setDirection(RIGHT);
        return command;
        break;
    default:
        return nullptr;
        break;
    }
}