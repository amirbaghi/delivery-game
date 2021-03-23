#include <iostream>
#include "Headers/Actor/Field.h"
#include "Headers/Game/Game.h"

Field::Field(GameComponent *parent, clock_t creation_time, char character) : GameActor(parent, creation_time, character)
{
}

Field::~Field()
{
}

void Field::setWidthAndHeight(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Field::setCharacterAtXandY(int x, int y, char character)
{
    fieldString[x][y] = character;
}

void Field::load(clock_t time)
{
    // Initializing the field string with the ground tile
    std::vector<std::vector<char>> field(width, std::vector<char>(height, character));
    fieldString = field;

    Game *game = dynamic_cast<Game *>(parent_component);

    Avatar *avatar = game->getAvatar();
    std::vector<Wall *> walls = game->getWalls();
    std::vector<Obstacle *> obstacles = game->getObstacles();

    // Setting the avatar
    fieldString[avatar->getCurrentX() - 1][avatar->getCurrentY() - 1] = avatar->getCharacter();

    // Setting the walls
    for (auto &wall : walls)
    {
        fieldString[wall->getX()][wall->getY()] = wall->getCharacter();
    }

    // Setting the Obstacles
    for (auto &obstacle : obstacles)
    {
        fieldString[obstacle->getX() - 1][obstacle->getY() - 1] = obstacle->getCharacter();
    }
}

void Field::update(clock_t time)
{
}

void Field::render(clock_t time)
{
    for (size_t i = 0; i < fieldString.size(); i++)
    {
        for (size_t j = 0; j < fieldString[i].size(); j++)
        {
            std::cout << fieldString[i][j];
        }
        std::cout << "\n";
    }
}