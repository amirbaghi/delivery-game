#ifndef PHYSICS_H
#define PHYSICS_H

#include "../GameComponent.h"
#include "../Command/Command.h"

class Physics : public GameComponent
{
public:
    Physics(GameComponent* parent);
    ~Physics();

    // Method for applying the physics
    void applyPhysics(Command* command);
};

#endif