#include <iostream>
#include "Headers/Game/Game.h"

int main(int argc, char **argv)
{
    Game *game = new Game();

    game->mainLoop();

    return 0;
}
