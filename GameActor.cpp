#include "Headers/Actor/GameActor.h"

GameActor::GameActor(GameComponent* parent, clock_t creation_time, char character) : GameComponent(parent)
{
    this->creation_time = creation_time;
    this->character = character;
}

GameActor::~GameActor()
{
    
}

void GameActor::setColor(std::string color)
{
    this->color = color;
}

char GameActor::getCharacter()
{
    return this->character;
}

std::string GameActor::getColor()
{
    return this->color;
}

void GameActor::setCharacter(char character)
{
    this->character = character;
}