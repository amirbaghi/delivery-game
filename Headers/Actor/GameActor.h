#ifndef GAMEACTOR_H
#define GAMEACTOR_H

#include "../GameComponent.h"
#include <time.h>
#include <iostream>

class GameActor : public GameComponent
{
public:
    GameActor(GameComponent *parent, clock_t creation_time, char character);
    virtual ~GameActor();

    // Character Setter
    void setCharacter(char character);

    // Color Code Setter
    void setColor(std::string color);

    // Character Getter
    char getCharacter();

    // Color Getter
    std::string getColor();

protected:
    // Creation Time
    clock_t creation_time;
    // Game Actor's Character
    char character;
    // Game Actor's Color Code
    std::string color;
};

#endif