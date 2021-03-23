#include <iostream>
#include "Headers/Actor/Wall.h"

Wall::Wall(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{

}

Wall::~Wall()
{
    
}

void Wall::setXandY(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Wall::load(clock_t time)
{

}

void Wall::update(clock_t time)
{

}

void Wall::render(clock_t time)
{
    putchar(this->character);
}

int Wall::getX()
{
    return this->x;
}

int Wall::getY()
{
    return this->y;
}