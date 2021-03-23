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

    // Load, Update, Render Methods
    void virtual load(clock_t time) = 0;
    void virtual update(clock_t time) = 0;
    void virtual render(clock_t time) = 0;

protected:
    // Creation Time
    clock_t creation_time;
    // Game Actor's Character
    char character;
};

#endif