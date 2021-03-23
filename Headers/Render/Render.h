#ifndef RENDER_H
#define RENDER_H

#include "../GameComponent.h"

class Render : public GameComponent
{
public:
    Render(GameComponent *parent);
    ~Render();

    // Method for Rendering the game
    void render(clock_t time);
};

#endif