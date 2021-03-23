#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

class GameComponent
{
public:
    GameComponent(GameComponent* parent);
    virtual ~GameComponent();

protected:
    // Parent Component
    GameComponent* parent_component;
};

#endif