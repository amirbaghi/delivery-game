#ifndef AIENGINE_H
#define AIENGINE_H

#include "../GameComponent.h"
#include "../Command/Command.h"

class Command;

class AIEngine : public GameComponent
{
public:
    AIEngine(GameComponent *parent);
    ~AIEngine();

    // Method for generating moves by AI
    Command *generateMove();
};

#endif