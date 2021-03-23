#include "GameActor.h"

class Avatar : public GameActor
{
public:
    Avatar(GameComponent *parent, int creation_time);

    // Set current x and y
    void setCurrentXandY(int x, int y);

    // Load, Update, Render
    void load(int time);
    void update(int time);
    void render(int time);

private:
    // Current x and y
    int current_x, current_y;
};