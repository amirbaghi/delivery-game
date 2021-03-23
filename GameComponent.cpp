#include "Headers/GameComponent.h"

GameComponent::GameComponent(GameComponent* parent)
{
    this->parent_component = parent;
}

GameComponent::~GameComponent()
{
    
}