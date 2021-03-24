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

    // Width Getter
    int getWidth();
    // Height Getter
    int getHeight();

    // Load, Update, Render
    void load(clock_t time);
    void update(clock_t time);
    void render(clock_t time);

private:
    // The Width and Height of the Ground
    int width, height;
};

#endif