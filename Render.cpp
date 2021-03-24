#include <iostream>
#include "Headers/Game/Game.h"
#include "Headers/Render/Render.h"

Render::Render(GameComponent *parent) : GameComponent(parent)
{
}

Render::~Render()
{
}

void Render::initRender()
{
    Game *game = dynamic_cast<Game *>(parent_component);

    Field *field = game->getField();

    int width = field->getWidth();
    int height = field->getHeight();
    char tileChar = field->getCharacter();

    // Initializing the frame buffer with the ground tile
    std::vector<std::vector<char>> frameBuffer(width, std::vector<char>(height, tileChar));
    currentFrameBuffer = frameBuffer;

    Avatar *avatar = game->getAvatar();
    std::vector<Wall *> walls = game->getWalls();
    std::vector<Obstacle *> obstacles = game->getObstacles();

    // Setting the avatar
    currentFrameBuffer[avatar->getCurrentX() - 1][avatar->getCurrentY() - 1] = avatar->getCharacter();

    // Setting the walls
    for (auto &wall : walls)
    {
        currentFrameBuffer[wall->getX() - 1][wall->getY() - 1] = wall->getCharacter();
    }

    // Setting the Obstacles
    for (auto &obstacle : obstacles)
    {
        currentFrameBuffer[obstacle->getX() - 1][obstacle->getY() - 1] = obstacle->getCharacter();
    }

    // Setting the previous frame buffer as the current frame
    previousFrameBuffer = currentFrameBuffer;

    // Rendering the first frame
    system("clear");

    for (size_t i = 0; i < currentFrameBuffer.size(); i++)
    {
        for (size_t j = 0; j < currentFrameBuffer[i].size(); j++)
        {
            std::cout << currentFrameBuffer[i][j];
        }
        std::cout << "\n";
    }
}

void Render::updateFrameBuffer()
{
    // Updating the current frame buffer
    Game *game = dynamic_cast<Game *>(parent_component);

    Field *field = game->getField();

    int width = field->getWidth();
    int height = field->getHeight();
    char tileChar = field->getCharacter();

    // Initializing the frame buffer with the ground tile
    std::vector<std::vector<char>> frameBuffer(width, std::vector<char>(height, tileChar));
    currentFrameBuffer = frameBuffer;

    Avatar *avatar = game->getAvatar();
    std::vector<Wall *> walls = game->getWalls();
    std::vector<Obstacle *> obstacles = game->getObstacles();

    // Setting the avatar
    currentFrameBuffer[avatar->getCurrentX() - 1][avatar->getCurrentY() - 1] = avatar->getCharacter();

    // Setting the walls
    for (auto &wall : walls)
    {
        currentFrameBuffer[wall->getX() - 1][wall->getY() - 1] = wall->getCharacter();
    }

    // Setting the Obstacles
    for (auto &obstacle : obstacles)
    {
        currentFrameBuffer[obstacle->getX() - 1][obstacle->getY() - 1] = obstacle->getCharacter();
    }
}

void Render::render()
{
    // Render the current frame using a double buffer technique
    for (size_t i = 0; i < currentFrameBuffer.size(); i++)
    {
        for (size_t j = 0; j < currentFrameBuffer[i].size(); j++)
        {
            // Only render the character if it's different than the previous frame
            if (currentFrameBuffer[i][j] != previousFrameBuffer[i][j])
            {
                std::cout << "\033[" << i + 1 << ";" << j + 1 << "H";
                std::cout << currentFrameBuffer[i][j];
            }
        }
    }

    // Set previous buffer as the current buffer
    previousFrameBuffer = currentFrameBuffer;
}