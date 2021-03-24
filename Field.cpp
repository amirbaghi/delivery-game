#include <iostream>
#include "Headers/Actor/Field.h"
#include "Headers/Game/Game.h"

Field::Field(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{
}

Field::~Field()
{
}

void Field::setWidthAndHeight(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Field::getWidth()
{
    return this->width;
}

int Field::getHeight()
{
    return this->height;
}