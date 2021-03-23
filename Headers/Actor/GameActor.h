#include "GameComponent.h"

class GameActor : public GameComponent
{
public:
    GameActor(GameComponent *parent, int creation_time);

    // Character Setter
    void setCharacter(char character);

    // Load, Update, Render Methods
    void virtual load(int time) = 0;
    void virtual update(int time) = 0;
    void virtual render(int time) = 0;

private:
    // Creation Time
    int creation_time;
    // Game Actor's Character
    char character;
};