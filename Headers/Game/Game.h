#ifndef GAME_H
#define GAME_H

#include <chrono>
#include "../InputHandler/InputHandler.h"
#include "../AI/AIEngine.h"
#include "../Command/CommandStream.h"
#include "../Actor/Avatar.h"
#include "../Actor/Field.h"
#include "../Actor/Obstacle.h"
#include "../Actor/Goal.h"
#include "../Actor/Wall.h"
#include "../Physics/Physics.h"
#include "../Render/Render.h"
#include "../Command/UndoCommand.h"
#include "../Command/MoveCommand.h"
#include "../Command/ExitCommand.h"

class Game : public GameComponent
{
public:
    Game();
    ~Game();

    // Avatar Getter
    Avatar *getAvatar();

    // Obstacles Getter
    std::vector<Obstacle *> getObstacles();

    // Walls Getter
    std::vector<Wall *> getWalls();

    // Field Getter
    Field *getField();

    // Goals getter
    std::vector<Goal *> getGoals();

    // Creation Time Getter
    clock_t getCreationTime();

    // Score getter
    int getScore();

    // Score setter
    void setScore(int score);

    // Initialize the game
    void initGame();

    // Main game loop
    void mainLoop();

private:
    // Input Handler
    InputHandler *inputHandler;

    // AI Engine
    AIEngine *aiEngine;

    // Command Stream
    CommandStream *commandStream;

    // Physics Module
    Physics *physicsModule;

    // Render Module
    Render *renderModule;

    // Game Field
    Field *field;

    // Avatar
    Avatar *avatar;

    // Obstacles
    std::vector<Obstacle *> obstacles;

    // Goals
    std::vector<Goal *> goals;

    // Walls
    std::vector<Wall *> walls;

    // Start Time
    clock_t startTime;

    // Score
    int score;
};

#endif