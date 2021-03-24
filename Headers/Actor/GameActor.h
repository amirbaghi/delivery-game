#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "../GameComponent.h"
#include <time.h>

class GameActor : public GameComponent
{
public:
    GameActor(GameComponent *parent, clock_t creation_time, char character);
    virtual ~GameActor();

    // Character Setter
    void setCharacter(char character);

    // Character Getter
    char getCharacter();

protected:
    // Creation Time
    clock_t creation_time;
    // Game Actor's Character
    char character;
};

#endif