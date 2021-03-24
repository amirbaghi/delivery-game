#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameActor.h"

class Obstacle : public GameActor
{
public:
    Obstacle(GameComponent *parent, clock_t creation_time, char character);
    ~Obstacle();

    // X and Y setter
    void setXandY(int x, int y);

    // Get X
    int getX();

    // Get Y
    int getY();


private:
    // X and Y coordinates
    int x, y;
};

#endif