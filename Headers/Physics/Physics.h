#include "GameComponent.h"
#include "Command.h"

class Physics : public GameComponent
{
public:
    Physics(GameComponent* parent);

    // Method for applying the physics
    void applyPhysics(Command& command);
};