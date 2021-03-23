#include "Headers/Game/Game.h"

Game::Game() : GameComponent(nullptr)
{
}

Game::~Game()
{
    delete this->inputHandler;
    delete this->aiEngine;
    delete this->commandStream;
    delete this->physicsModule;
    delete this->renderModule;
    delete this->field;
    delete this->avatar;

    for (auto &obstacle : obstacles)
    {
        delete obstacle;
    }

    for (auto &wall : walls)
    {
        delete wall;
    }
}

Avatar *Game::getAvatar()
{

    return this->avatar;
}

std::vector<Obstacle *> Game::getObstacles()
{
    return this->obstacles;
}

std::vector<Wall *> Game::getWalls()
{
    return this->walls;
}

Field *Game::getField()
{
    return this->field;
}

void Game::mainLoop()
{
    // Setting the start time of the game
    startTime = clock();

    // Initialize and load the main components of the game
    inputHandler = new InputHandler(this);
    aiEngine = new AIEngine(this);
    commandStream = new CommandStream(this);
    physicsModule = new Physics(this);
    renderModule = new Render(this);

    field = new Field(this, startTime, '-');
    int width, height;
    width = 20;
    height = 60;
    field->setWidthAndHeight(width, height);

    avatar = new Avatar(this, startTime, 'X');
    avatar->setCurrentXandY(10, 30);

    std::vector<Obstacle *> obstacles;

    Obstacle *obs = new Obstacle(this, startTime, '#');
    obs->setXandY(12, 50);
    obstacles.push_back(obs);

    obs = new Obstacle(this, startTime, '#');
    obs->setXandY(15, 45);
    obstacles.push_back(obs);

    obs = new Obstacle(this, startTime, '#');
    obs->setXandY(15, 38);
    obstacles.push_back(obs);

    obs = new Obstacle(this, startTime, '#');
    obs->setXandY(9, 10);
    obstacles.push_back(obs);

    obs = new Obstacle(this, startTime, '#');
    obs->setXandY(18, 22);
    obstacles.push_back(obs);

    obs = new Obstacle(this, startTime, '#');
    obs->setXandY(19, 32);
    obstacles.push_back(obs);

    this->obstacles = obstacles;


    std::vector<Wall *> walls;
    
    for (int i = 0 ; i < width ; i++)
    {
        Wall* wall1 = new Wall(this, startTime, '@');
        Wall* wall2 = new Wall(this, startTime, '@');

        wall1->setXandY(i, 0);
        wall2->setXandY(i, height - 1);

        walls.push_back(wall1);
        walls.push_back(wall2);
    }

    for (int i = 0 ; i < height ; i++)
    {
        Wall* wall1 = new Wall(this, startTime, '@');
        Wall* wall2 = new Wall(this, startTime, '@');

        wall1->setXandY(0, i);
        wall2->setXandY(width - 1, i);

        walls.push_back(wall1);
        walls.push_back(wall2);
    }

    this->walls = walls;


    this->field->load(startTime);


    this->renderModule->render(clock());

}
