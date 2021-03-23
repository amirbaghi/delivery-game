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

    // Load, Update, Render Methods
    void load(clock_t time);
    void update(clock_t time);
    void render(clock_t time);

private:
    // X and Y coordinates
    int x, y;
};

#endif