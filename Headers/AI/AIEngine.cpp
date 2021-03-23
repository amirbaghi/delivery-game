#include "GameComponent.h"

class Command;

class AIEngine : public GameComponent
{
    AIEngine(GameComponent *parent);

    // Method for generating moves by AI
    Command generateMove();
};