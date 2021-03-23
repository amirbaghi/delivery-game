#include "GameActor.h"

class Obstacle : public GameActor
{
public:
    Obstacle(GameComponent *parent, int creation_time);

    // X and Y setter
    void setXandY(int x, int y);

    // Load, Update, Render Methods
    void load(int time);
    void update(int time);
    void render(int time);

private:
    // X and Y coordinates
    int x, y;
};