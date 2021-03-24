#ifndef AVATAR_H
#define AVATAR_H

#include "GameActor.h"

class Avatar : public GameActor
{
public:
    Avatar(GameComponent *parent, clock_t creation_time, char character);
    ~Avatar();

    // Set current x and y
    void setCurrentXandY(int x, int y);

    // Get current x
    int getCurrentX();
    // Get current y
    int getCurrentY();

private:
    // Current x and y
    int current_x, current_y;
};

#endif