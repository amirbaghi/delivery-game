#include "Headers/Actor/Goal.h"


Goal::Goal(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{

}

int Goal::getX()
{
    return this->x;
}

int Goal::getY()
{
    return this->y;
}

void Goal::setXandY(int x, int y)
{
    this->x = x;
    this->y = y;
}