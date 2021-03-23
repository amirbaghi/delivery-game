#include "Headers/Actor/GameActor.h"

GameActor::GameActor(GameComponent* parent, clock_t creation_time, char character) : GameComponent(parent)
{
    this->creation_time = creation_time;
    this->character = character;
}

GameActor::~GameActor()
{
    
}

char GameActor::getCharacter()
{
    return this->character;
}

void GameActor::setCharacter(char character)
{
    this->character = character;
}