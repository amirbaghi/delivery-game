#ifndef WALL_H
#define WALL_H

#include "GameActor.h"

class Wall : public GameActor
{
public:
    Wall(GameComponent *parent, clock_t creation_time, char character);
    ~Wall();

    // X and Y Setter
    void setXandY(int x, int y);

    // Get X
    int getX();

    // Get Y
    int getY();


private:
    // X and Y coordiates
    int x, y;
};

#endif