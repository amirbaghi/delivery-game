#ifndef RENDER_H
#define RENDER_H

#include "../GameComponent.h"

class Render : public GameComponent
{
public:
    Render(GameComponent *parent);
    ~Render();

    // Initialize the render module
    void initRender();

    // Update the Current Frame Buffer
    void updateFrameBuffer();

    // Render the current frame
    void render();

private:
    // Current Frame Buffer
    std::vector<std::vector<char>> currentFrameBuffer;

    // Previous Frame Buffer
    std::vector<std::vector<char>> previousFrameBuffer;
};

#endif