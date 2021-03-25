#include "Headers/Game/Game.h"
#include "Headers/Utils.h"
#include "Headers/Command/MoveCommand.h"
#include "Headers/Command/UndoCommand.h"

Physics::Physics(GameComponent *parent) : GameComponent(parent)
{
}

Physics::~Physics()
{
}

void Physics::applyPhysics(Command *command)
{

    Game *game = dynamic_cast<Game *>(parent_component);
    Avatar *avatar = game->getAvatar();
    std::vector<Obstacle *> obstacles = game->getObstacles();
    std::vector<Wall *> walls = game->getWalls();

    MoveCommand *c = dynamic_cast<MoveCommand *>(command);

    // Checking the direction of the move
    Obstacle *obstacle = nullptr;

    switch (c->getDirection())
    {
    case UP:

        // Checking if an obstacle is in front of the avatar
        for (auto it = obstacles.begin(); it != obstacles.end(); it++)
        {

            if ((*it)->getY() == avatar->getCurrentY() && (*it)->getX() == (avatar->getCurrentX() - 1))
            {
                // If the obstacle is still not in its place
                if (!((*it)->getIsInPlace()))
                {
                    obstacle = (*it);
                }
                // If the obstacle is in its place
                else
                {
                    return;
                }
            }
        }

        // Check if there is a wall in front of the obstacle/avatar
        for (auto it = walls.begin(); it != walls.end(); it++)
        {
            // If there is an obstacle in front of the avatar
            if (obstacle != nullptr)
            {
                if ((*it)->getY() == obstacle->getY() && (*it)->getX() == (obstacle->getX() - 1))
                {
                    return;
                }
            }
            // If there is no obstacle in front of the avatar
            else
            {
                if ((*it)->getY() == avatar->getCurrentY() && (*it)->getX() == (avatar->getCurrentX() - 1))
                {
                    return;
                }
            }
        }

        // If there is an obstacle in front of the avatar
        if (obstacle != nullptr)
        {
            // Check if there is an obstacle in front of the obstacle
            for (auto it = obstacles.begin(); it != obstacles.end(); it++)
            {
                if ((*it)->getY() == obstacle->getY() && (*it)->getX() == (obstacle->getX() - 1))
                {
                    return;
                }
            }
        }

        // If there is no obstacle nor wall nor in place obstacle in front of the obstacle/avatar
        // Move the avatar (and the obstacle (not in place) if there is one in front of it)
        if (obstacle != nullptr)
        {
            obstacle->setXandY(obstacle->getX() - 1, obstacle->getY());
            // Check if the obstacle is in its place or not
            for (auto &goal : game->getGoals())
            {
                if (obstacle->getX() == goal->getX() && obstacle->getY() == goal->getY())
                {
                    obstacle->setIsInPlace(true);
                    game->setScore(game->getScore() + 1);
                    break;
                }
            }
        }
        avatar->setCurrentXandY(avatar->getCurrentX() - 1, avatar->getCurrentY());
        break;

    case DOWN:

        // Checking if an obstacle is in front of the avatar
        for (auto it = obstacles.begin(); it != obstacles.end(); it++)
        {

            if ((*it)->getY() == avatar->getCurrentY() && (*it)->getX() == (avatar->getCurrentX() + 1))
            {
                // If the obstacle is still not in its place
                if (!((*it)->getIsInPlace()))
                {
                    obstacle = (*it);
                }
                // If the obstacle is in its place
                else
                {
                    return;
                }
            }
        }

        // Check if there is a wall in front of the obstacle/avatar
        for (auto it = walls.begin(); it != walls.end(); it++)
        {
            // If there is an obstacle in front of the avatar
            if (obstacle != nullptr)
            {
                if ((*it)->getY() == obstacle->getY() && (*it)->getX() == (obstacle->getX() + 1))
                {
                    return;
                }
            }
            // If there is no obstacle in front of the avatar
            else
            {
                if ((*it)->getY() == avatar->getCurrentY() && (*it)->getX() == (avatar->getCurrentX() + 1))
                {
                    return;
                }
            }
        }

        // If there is an obstacle in front of the avatar
        if (obstacle != nullptr)
        {
            // Check if there is an obstacle in front of the obstacle
            for (auto it = obstacles.begin(); it != obstacles.end(); it++)
            {
                if ((*it)->getY() == obstacle->getY() && (*it)->getX() == (obstacle->getX() + 1))
                {
                    return;
                }
            }
        }

        // If there is no obstacle nor wall nor in place obstacle in front of the obstacle/avatar
        // Move the avatar (and the obstacle (not in place) if there is one in front of it)
        if (obstacle != nullptr)
        {
            obstacle->setXandY(obstacle->getX() + 1, obstacle->getY());
            // Check if the obstacle is in its place or not
            for (auto &goal : game->getGoals())
            {
                if (obstacle->getX() == goal->getX() && obstacle->getY() == goal->getY())
                {
                    obstacle->setIsInPlace(true);
                    game->setScore(game->getScore() + 1);
                    break;
                }
            }
        }
        avatar->setCurrentXandY(avatar->getCurrentX() + 1, avatar->getCurrentY());
        break;
    case RIGHT:

        // Checking if an obstacle is in front of the avatar
        for (auto it = obstacles.begin(); it != obstacles.end(); it++)
        {

            if ((*it)->getY() == (avatar->getCurrentY() + 1) && (*it)->getX() == avatar->getCurrentX())
            {
                // If the obstacle is still not in its place
                if (!((*it)->getIsInPlace()))
                {
                    obstacle = (*it);
                }
                // If the obstacle is in its place
                else
                {
                    return;
                }
            }
        }

        // Check if there is a wall in front of the obstacle/avatar
        for (auto it = walls.begin(); it != walls.end(); it++)
        {
            // If there is an obstacle in front of the avatar
            if (obstacle != nullptr)
            {
                if ((*it)->getY() == (obstacle->getY() + 1) && (*it)->getX() == obstacle->getX())
                {
                    return;
                }
            }
            // If there is no obstacle in front of the avatar
            else
            {
                if ((*it)->getY() == (avatar->getCurrentY() + 1) && (*it)->getX() == avatar->getCurrentX())
                {
                    return;
                }
            }
        }

        // If there is an obstacle in front of the avatar
        if (obstacle != nullptr)
        {
            // Check if there is an obstacle in front of the obstacle
            for (auto it = obstacles.begin(); it != obstacles.end(); it++)
            {
                if ((*it)->getY() == (obstacle->getY() + 1) && (*it)->getX() == obstacle->getX())
                {
                    return;
                }
            }
        }

        // If there is no obstacle nor wall nor in place obstacle in front of the obstacle/avatar
        // Move the avatar (and the obstacle (not in place) if there is one in front of it)
        if (obstacle != nullptr)
        {
            obstacle->setXandY(obstacle->getX(), obstacle->getY() + 1);
            // Check if the obstacle is in its place or not
            for (auto &goal : game->getGoals())
            {
                if (obstacle->getX() == goal->getX() && obstacle->getY() == goal->getY())
                {
                    obstacle->setIsInPlace(true);
                    game->setScore(game->getScore() + 1);
                    break;
                }
            }
        }
        avatar->setCurrentXandY(avatar->getCurrentX(), avatar->getCurrentY() + 1);
        break;

    case LEFT:

        // Checking if an obstacle is in front of the avatar
        for (auto it = obstacles.begin(); it != obstacles.end(); it++)
        {

            if ((*it)->getY() == (avatar->getCurrentY() - 1) && (*it)->getX() == avatar->getCurrentX())
            {
                // If the obstacle is still not in its place
                if (!((*it)->getIsInPlace()))
                {
                    obstacle = (*it);
                }
                // If the obstacle is in its place
                else
                {
                    return;
                }
            }
        }

        // Check if there is a wall in front of the obstacle/avatar
        for (auto it = walls.begin(); it != walls.end(); it++)
        {
            // If there is an obstacle in front of the avatar
            if (obstacle != nullptr)
            {
                if ((*it)->getY() == (obstacle->getY() - 1) && (*it)->getX() == obstacle->getX())
                {
                    return;
                }
            }
            // If there is no obstacle in front of the avatar
            else
            {
                if ((*it)->getY() == (avatar->getCurrentY() - 1) && (*it)->getX() == avatar->getCurrentX())
                {
                    return;
                }
            }
        }

        // If there is an obstacle in front of the avatar
        if (obstacle != nullptr)
        {
            // Check if there is an obstacle in front of the obstacle
            for (auto it = obstacles.begin(); it != obstacles.end(); it++)
            {
                if ((*it)->getY() == (obstacle->getY() - 1) && (*it)->getX() == obstacle->getX())
                {
                    return;
                }
            }
        }

        // If there is no obstacle nor wall nor in place obstacle in front of the obstacle/avatar
        // Move the avatar (and the obstacle (not in place) if there is one in front of it)
        if (obstacle != nullptr)
        {
            obstacle->setXandY(obstacle->getX(), obstacle->getY() - 1);
            // Check if the obstacle is in its place or not
            for (auto &goal : game->getGoals())
            {
                if (obstacle->getX() == goal->getX() && obstacle->getY() == goal->getY())
                {
                    obstacle->setIsInPlace(true);
                    game->setScore(game->getScore() + 1);
                    break;
                }
            }
        }
        avatar->setCurrentXandY(avatar->getCurrentX(), avatar->getCurrentY() - 1);
        break;
    default:
        break;
    }
}
