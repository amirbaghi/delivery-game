#ifndef GOAL_H
#define GOAL_H

#include "GameActor.h"

class Goal : public GameActor
{
public:

    Goal(GameComponent *parent, clock_t creation_time, char character);

    // X and Y Setter
    void setXandY(int x, int y);

    // X Getter
    int getX();

    // Y Getter
    int getY();

private:
    // Goal Coordinates
    int x, y;
};



#endif