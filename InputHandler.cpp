#include <iostream>
#include "Headers/InputHandler/InputHandler.h"
#include "Headers/Utils.h"
#include "Headers/Game/Game.h"
#include "Headers/Command/MoveCommand.h"
#include "Headers/Command/UndoCommand.h"
#include "Headers/Command/ExitCommand.h"

InputHandler::InputHandler(GameComponent *parent) : GameComponent(parent)
{
}

InputHandler::~InputHandler()
{
}

Command *InputHandler::getInput()
{
    char c;
    c = Utils::getch();

    // If exit button is pushed
    if (c == 'q' | c == 'Q')
    {
        return new ExitCommand();
    }

    // If undo button is pushed
    if (c == 'u' | c == 'U')
    {
        return new UndoCommand();
    }

    // If it's a move command or a not supported key
    MoveCommand *command;

    // Check for arrow keys
    if (c == '\033')
    {

        c = Utils::getch();
        c = Utils::getch();

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
    return nullptr;
}