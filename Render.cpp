#include <iostream>
#include "Headers/Game/Game.h"
#include "Headers/Render/Render.h"

Render::Render(GameComponent* parent) : GameComponent(parent)
{

}

Render::~Render()
{

}

void Render::render(clock_t time)
{

    Game* game = dynamic_cast<Game *>(parent_component);

    game->getField()->render(time);

}