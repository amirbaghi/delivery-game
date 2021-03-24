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

    // isInPlace Setter
    void setIsInPlace(bool isInPlace);

    // isInPlace Getter
    bool getIsInPlace();

    // Get X
    int getX();

    // Get Y
    int getY();


private:
    // X and Y coordinates
    int x, y;

    // Is the obstacle in a goal place
    bool isInPlace;
};

#endif