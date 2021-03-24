#include <iostream>
#include "Headers/Actor/Obstacle.h"

Obstacle::Obstacle(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{
}

Obstacle::~Obstacle()
{
    
}

void Obstacle::setXandY(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Obstacle::getX()
{
    return this->x;
}

int Obstacle::getY()
{
    return this->y;
}