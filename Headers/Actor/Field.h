#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "GameActor.h"

class Field : public GameActor
{
public:
    Field(GameComponent *parent, clock_t creation_time, char character);
    ~Field();

    // Set Width and Height
    void setWidthAndHeight(int width, int height);

    // Set a character in the string sequence at x and y
    void setCharacterAtXandY(int x, int y, char character);

    // Load, Update, Render
    void load(clock_t time);
    void update(clock_t time);
    void render(clock_t time);

private:
    // The Width and Height of the Ground
    int width, height;

    // Field String Sequence (for printing to console)
    std::vector<std::vector<char>> fieldString;
};

#endif