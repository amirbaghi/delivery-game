#include "GameActor.h"

class Ground : public GameActor
{
public:
    Ground(GameComponent *parent, int creation_time);

    // Set Width and Height
    void setWidthAndHeight(int width, int height);

    // Load, Update, Render
    void load(int time);
    void update(int time);
    void render(int time);

private:
    // The Width and Height of the Ground
    int width, height;
};