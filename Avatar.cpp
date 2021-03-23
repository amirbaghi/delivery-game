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

void Avatar::load(clock_t time)
{

}

void Avatar::update(clock_t time)
{

}

void Avatar::render(clock_t time)
{
    putchar(this->character);
}

int Avatar::getCurrentX()
{
    return this->current_x;
}

int Avatar::getCurrentY()
{
    return this->current_y;
}