#include "Headers/Game/Game.h"
#include "Headers/Utils.h"
#include <iostream>

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

    for (auto &goal : goals)
    {
        delete goal;
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

std::vector<Goal *> Game::getGoals()
{
    return this->goals;
}

Field *Game::getField()
{
    return this->field;
}

void Game::initGame()
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

    std::srand((unsigned int)std::time(NULL));
    auto randDirection = 0 + (std::rand() % (3 - 0 + 1));
    int x, y;

    avatar = new Avatar(this, startTime, 'X');
    // Setting a random x and y for the character
    x = 2 + (std::rand() % ((width - 1) - 2 + 1));
    y = 2 + (std::rand() % ((height - 1) - 2 + 1));
    // Set the avatar color
    avatar->setColor(BRIGHTRED);
    avatar->setCurrentXandY(x, y);

    // Initialize the obstacles with random coordinates
    std::vector<Obstacle *> obstacles;

    for (int i = 0; i < 6; i++)
    {
        Obstacle *obs = new Obstacle(this, startTime, '#');

        // Set obstacle color
        obs->setColor(BRIGHTYELLOW);

        // Generating random coords for the obstacle and checking so that they're not equal to avatar's coords
        do
        {
            x = 3 + (std::rand() % ((width - 2) - 2 + 1));
            y = 3 + (std::rand() % ((height - 2) - 2 + 1));

        } while (x == avatar->getCurrentX() && y == avatar->getCurrentY());

        obs->setXandY(x, y);
        obs->setIsInPlace(false);
        
        obstacles.push_back(obs);
    }

    this->obstacles = obstacles;

    // Initializing the goals
    std::vector<Goal *> goals;

    for (int i = 0; i < 6; i++)
    {
        Goal *goal = new Goal(this, startTime, 'O');

        // Set Goal color
        goal->setColor(BRIGHTCYAN);

        // Generating random coords for the goal and checking so that they're not equal to avatar or another obstacle's coords
        bool hasConflict;
        do
        {
            hasConflict = false;
            x = 2 + (std::rand() % ((width - 1) - 2 + 1));
            y = 2 + (std::rand() % ((height - 1) - 2 + 1));

            if (x == avatar->getCurrentX() && y == avatar->getCurrentY())
            {
                hasConflict = true;
            }
            else
            {
                for (auto &obs : obstacles)
                {
                    if (x == obs->getX() && y == obs->getY())
                    {
                        hasConflict = true;
                        break;
                    }
                }
            }

        } while (hasConflict);

        goal->setXandY(x, y);

        goals.push_back(goal);
    }

    this->goals = goals;

    // Initialize the walls
    std::vector<Wall *> walls;

    for (int i = 0; i < width; i++)
    {
        Wall *wall1 = new Wall(this, startTime, '@');
        Wall *wall2 = new Wall(this, startTime, '@');

        // Set wall color
        wall1->setColor(BOLDYELLOW);
        wall2->setColor(BOLDYELLOW);

        wall1->setXandY(i + 1, 1);
        wall2->setXandY(i + 1, height);

        walls.push_back(wall1);
        walls.push_back(wall2);
    }

    for (int i = 0; i < height; i++)
    {
        Wall *wall1 = new Wall(this, startTime, '@');
        Wall *wall2 = new Wall(this, startTime, '@');

        // Set wall color
        wall1->setColor(BOLDYELLOW);
        wall2->setColor(BOLDYELLOW);

        wall1->setXandY(1, i + 1);
        wall2->setXandY(width, i + 1);

        walls.push_back(wall1);
        walls.push_back(wall2);
    }

    this->walls = walls;

    // Initialize the render module
    renderModule->initRender();
}

clock_t Game::getCreationTime()
{
    return this->startTime;
}

void Game::mainLoop()
{
    // Initialize the game
    initGame();

    // Main Game Loop
    do
    {
        // GAME LOGIC

        // Get command from user
        Command *userCommand = inputHandler->getInput();

        // Checking if the command entered is valid
        if (userCommand != nullptr)
        {
            // Add the command to the pending commands in the command stream
            commandStream->addToPendingCommands(userCommand);

            // Dequeue a command out of the command stream
            Command *currentCommand = commandStream->popRecentPendingCommand();

            // Check if it's an undo command
            if (dynamic_cast<UndoCommand *>(currentCommand) != nullptr)
            {
                // Pop the most recent resolved command from the command stream and invert it (Undo it)
                Command *tempCommand = commandStream->popRecentResolvedCommand();

                // Check if there was a resolved command and the command stream wasn't empty
                if (tempCommand != nullptr)
                {
                    MoveCommand *moveCommand = dynamic_cast<MoveCommand *>(tempCommand);

                    // Inverting the move command
                    switch (moveCommand->getDirection())
                    {
                    case UP:
                        moveCommand->setDirection(DOWN);
                        break;
                    case DOWN:
                        moveCommand->setDirection(UP);
                        break;
                    case LEFT:
                        moveCommand->setDirection(RIGHT);
                        break;
                    case RIGHT:
                        moveCommand->setDirection(LEFT);
                        break;
                    default:
                        break;
                    }

                    physicsModule->applyPhysics(moveCommand);
                }
            }
            // If it's an exit command
            else if (dynamic_cast<ExitCommand *>(currentCommand) != nullptr)
            {
                system("clear");
                exit(0);
            }
            // It's a Move Command
            else
            {
                MoveCommand *moveCommand = dynamic_cast<MoveCommand *>(currentCommand);

                // Push the move command to the resolved command stream
                commandStream->addToResolvedCommands(currentCommand);

                physicsModule->applyPhysics(moveCommand);
            }
        }

        // Update the current frame buffer
        renderModule->updateFrameBuffer();

        // Render the new frame
        renderModule->render(clock());

    } while (true);
}
