#include "GameComponent.h"

class Render : public GameComponent
{
public:
    Render(GameComponent *parent);

    // Method for Rendering the game
    void render(int time);
};