#include "GameActor.h"

class Wall : public GameActor
{
public:
    Wall(GameComponent *parent, int creation_time);

    // X and Y Setter
    void setXandY(int x, int y);

    // Load, Update, Render
    void load(int time);
    void update(int time);
    void render(int time);

private:
    // X and Y coordiates
    int x, y;
};