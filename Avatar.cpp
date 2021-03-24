#include <iostream>
#include "Headers/Actor/Avatar.h"

Avatar::Avatar(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{

}

Avatar::~Avatar()
{
    
}

void Avatar::setCurrentXandY(int x, int y)
{
    this->current_x = x;
    this->current_y = y;
}

int Avatar::getCurrentX()
{
    return this->current_x;
}

int Avatar::getCurrentY()
{
    return this->current_y;
}