#include "GameComponent.h"

class Command : public GameComponent
{
public:
    Command(GameComponent *parent);
};